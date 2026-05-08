//1 2
#include <iostream>

class Strategy {
public:
    virtual ~Strategy() = default;
    virtual void execute() const = 0;
};

class StrategyA : public Strategy {
public: void execute() const override { std::cout << "Выполнена стратегия A\n"; }
};
class StrategyB : public Strategy {
public: void execute() const override { std::cout << "Выполнена стратегия B\n"; }
};


class Context {
    const Strategy* strategy_ = nullptr;
public:
    void setStrategy(const Strategy* s) { strategy_ = s; }
    void run() const { if (strategy_) strategy_->execute(); }
};
int main() {
    setlocale(LC_ALL, "Russian"); 
    Context ctx;
    StrategyA s1; StrategyB s2;

    ctx.setStrategy(&s1);
    ctx.run(); 
    ctx.setStrategy(&s2);
    ctx.run(); 
    return 0;
}

//3
class ContextStrict {
    const Strategy& strategy_;
public:
    explicit ContextStrict(const Strategy& s) : strategy_(s) {}
    void run() const { strategy_.execute(); } // Нет проверок, компилятор гарантирует валидность
};

//4

enum class Mode { A, B };
class BadContext {
    Mode mode_;
public:
    explicit BadContext(Mode m) : mode_(m) {}
    void run() {
        if (mode_ == Mode::A) std::cout << "Логика A\n";
        else std::cout << "Логика B\n";
    }
};

//5
class MathStrategy {
public:
    virtual ~MathStrategy() = default;
    virtual int calculate(int a, int b) const = 0;
};

class AddStrategy : public MathStrategy {
public: int calculate(int a, int b) const override { return a + b; }
};
class SubStrategy : public MathStrategy {
public: int calculate(int a, int b) const override { return a - b; }
};

class Calculator {
    const MathStrategy* strat_ = nullptr;
public:
    void setStrategy(const MathStrategy* s) { strat_ = s; }
    int exec(int a, int b) const { return strat_ ? strat_->calculate(a, b) : 0; }
};

//6
#include <vector>
#include <algorithm>

class SortStrategy {
public:
    virtual ~SortStrategy() = default;
    virtual void sort(std::vector<int>& data) const = 0;
};

class BubbleSort : public SortStrategy {
public: void sort(std::vector<int>& d) const override {
    for (size_t i = 0; i < d.size(); ++i)
        for (size_t j = 0; j < d.size() - i - 1; ++j)
            if (d[j] > d[j+1]) std::swap(d[j], d[j+1]);
}};

class STLQuickSort : public SortStrategy {
public: void sort(std::vector<int>& d) const override {
    std::sort(d.begin(), d.end());
}};

//7
class SorterContext {
    std::unique_ptr<SortStrategy> strat_;
public:
    void setStrategy(std::unique_ptr<SortStrategy> s) { strat_ = std::move(s); }
    void sortData(std::vector<int>& data) { if (strat_) strat_->sort(data); }
};

//8
class SearchStrategy {
public:
    virtual ~SearchStrategy() = default;
    virtual int search(const std::vector<int>& data, int target) const = 0;
};

class LinearSearch : public SearchStrategy {
public: int search(const std::vector<int>& d, int t) const override {
    for (int i = 0; i < (int)d.size(); ++i) if (d[i] == t) return i;
    return -1;
}};

class BinarySearch : public SearchStrategy {
public: int search(const std::vector<int>& d, int t) const override {
    int l = 0, r = (int)d.size() - 1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (d[m] == t) return m;
        if (d[m] < t) l = m + 1; else r = m - 1;
    } return -1;
}};

//9
class FilterStrategy {
public:
    virtual ~FilterStrategy() = default;
    virtual std::vector<int> filter(const std::vector<int>& data) const = 0;
};

class EvenFilter : public FilterStrategy {
public: std::vector<int> filter(const std::vector<int>& d) const override {
    std::vector<int> res; for (int x : d) if (x % 2 == 0) res.push_back(x); return res;
}};

class PositiveFilter : public FilterStrategy {
public: std::vector<int> filter(const std::vector<int>& d) const override {
    std::vector<int> res; for (int x : d) if (x > 0) res.push_back(x); return res;
}};

//10
#include <string>
#include <algorithm>

class StringStrategy {
public:
    virtual ~StringStrategy() = default;
    virtual std::string process(const std::string& s) const = 0;
};

class ToUpperStrategy : public StringStrategy {
public: std::string process(const std::string& s) const override {
    std::string r = s; std::transform(r.begin(), r.end(), r.begin(), ::toupper); return r;
}};

class ToLowerStrategy : public StringStrategy {
public: std::string process(const std::string& s) const override {
    std::string r = s; std::transform(r.begin(), r.end(), r.begin(), ::tolower); return r;
}};

//11
class PaymentStrategy {
public: virtual ~PaymentStrategy() = default;
    virtual void pay(double amount) const = 0;
};
class CardPayment  : public PaymentStrategy { void pay(double a) const override { std::cout << "Оплата " << a << " картой\n"; } };
class CashPayment  : public PaymentStrategy { void pay(double a) const override { std::cout << "Оплата " << a << " наличными\n"; } };
class CryptoPayment: public PaymentStrategy { void pay(double a) const override { std::cout << "Оплата " << a << " криптой\n"; } };

//12
class DiscountStrategy {
public: virtual ~DiscountStrategy() = default;
    virtual double apply(double price) const = 0;
};
class PercentDiscount : public DiscountStrategy {
    double percent_;
public: explicit PercentDiscount(double p) : percent_(p) {}
    double apply(double price) const override { return price * (1.0 - percent_ / 100.0); }
};
class FixedDiscount : public DiscountStrategy {
    double value_;
public: explicit FixedDiscount(double v) : value_(v) {}
    double apply(double price) const override { return std::max(0.0, price - value_); }
};

//13
class LoggerStrategy {
public: virtual ~LoggerStrategy() = default;
    virtual void log(const std::string& msg) const = 0;
};
class ConsoleLogger : public LoggerStrategy {
    void log(const std::string& m) const override { std::cout << "[CONSOLE] " << m << '\n'; }
};
class FileLogger : public LoggerStrategy {
    void log(const std::string& m) const override { std::cout << "[FILE] Запись в log.txt: " << m << '\n'; }
};

//14
class NPCBehavior {
public: virtual ~NPCBehavior() = default;
    virtual void act() const = 0;
};
class Aggressive : public NPCBehavior { void act() const override { std::cout << "NPC атакует!\n"; } };
class Defensive  : public NPCBehavior { void act() const override { std::cout << "NPC защищается!\n"; } };

//15
class MovementStrategy {
public: virtual ~MovementStrategy() = default;
    virtual void move() const = 0;
};
class Walk : public MovementStrategy { void move() const override { std::cout << "Медленно идёт...\n"; } };
class Run  : public MovementStrategy { void move() const override { std::cout << "Быстро бежит!\n"; } };

//16
class ContextInjected {
    const Strategy& strategy_;
public:
    explicit ContextInjected(const Strategy& s) : strategy_(s) {}
    void run() const { strategy_.execute(); } // Стратегия задаётся один раз при создании
};

//17
class DynamicContext {
    std::unique_ptr<Strategy> strategy_;
public:
    explicit DynamicContext(std::unique_ptr<Strategy> s) : strategy_(std::move(s)) {}
    
    void executeAndUpgrade(std::unique_ptr<Strategy> next) {
        if (strategy_) strategy_->execute();
        strategy_ = std::move(next); // Замена внутри метода без внешних проверок
    }
};

//18
class VectorStrategy {
public: virtual ~VectorStrategy() = default;
    virtual void apply(std::vector<int>& vec) const = 0;
};

class STLContext {
    std::vector<int> data_;
    const VectorStrategy* strat_;
public:
    STLContext(std::vector<int> d, const VectorStrategy* s) : data_(std::move(d)), strat_(s) {}
    void process() { if (strat_) strat_->apply(data_); }
    const std::vector<int>& getData() const { return data_; }
};

//19
#include <memory>

class ModernContext {
    std::unique_ptr<Strategy> strategy_;
public:
    void setStrategy(std::unique_ptr<Strategy> s) { strategy_ = std::move(s); }
    void run() const { if (strategy_) strategy_->execute(); }
};

int main() {
    ModernContext ctx;
    ctx.setStrategy(std::make_unique<StrategyA>()); // Нет ручного delete, безопасное владение
    ctx.run();
    return 0;
}

//20
template<typename StrategyType>
class GenericContext {
    StrategyType strategy_;
public:
    explicit GenericContext(StrategyType s) : strategy_(std::move(s)) {}

    template<typename... Args>
    auto execute(Args&&... args) const {
        return strategy_.execute(std::forward<Args>(args)...);
    }
};

