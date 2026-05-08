//Блок 1–3: Ядро паттерна + Управление подписками (Задачи 1–5, 11–14, 18)
#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <functional>
#include <unordered_map>
#include <algorithm>
#include <any>

// 1
class IObserver {
public:
    virtual ~IObserver() = default;
    // 3
    virtual void update(const std::any& data) = 0;
};

//  1 11 12 13 14 18 
class Subject {
     
    std::vector<std::weak_ptr<IObserver>> observers_;

public:
    void attach(std::shared_ptr<IObserver> obs) {
        //  13
        bool exists = std::any_of(observers_.begin(), observers_.end(),
            [&obs](const std::weak_ptr<IObserver>& w) {
                auto sp = w.lock();
                return sp && sp == obs;
            });
        if (!exists) observers_.push_back(obs);
    }

    void detach(std::shared_ptr<IObserver> obs) {
        //  11 18L
        auto it = std::remove_if(observers_.begin(), observers_.end(),
            [&obs](const std::weak_ptr<IObserver>& w) {
                auto sp = w.lock();
                return !sp || sp == obs;
            });
        observers_.erase(it, observers_.end());
    }

    void clear() { observers_.clear(); } //  14

    void notify(const std::any& data = {}) {
      
        observers_.erase(
            std::remove_if(observers_.begin(), observers_.end(),
                           [](const std::weak_ptr<IObserver>& w){ return w.expired(); }),
            observers_.end()
        );

        //  2, 5
        for (const auto& w : observers_) {
            if (auto sp = w.lock()) {
                sp->update(data); //3
            }
        }
    }
};

//  4
class DataModel : public Subject {
    int value_ = 0;
public:
    void setValue(int v) {
        value_ = v;
        notify(std::make_any<int>(value_));
    }
    int getValue() const { return value_; }
};


//Блок 2: Практические сценарии (Задачи 6–10)
// 6
class SaveHandler : public IObserver { void update(const std::any&) override { std::cout << " Save executed\n"; } };
class PrintHandler : public IObserver { void update(const std::any&) override { std::cout << " Print executed\n"; } };
class LogHandler : public IObserver { void update(const std::any&) override { std::cout << " Log executed\n"; } };

//  7
class ConsoleLogger : public IObserver { void update(const std::any& d) override { std::cout << "[CONSOLE] " << std::any_cast<std::string>(d) << '\n'; } };
class FileLogger      : public IObserver { void update(const std::any& d) override { std::cout << "[FILE]    " << std::any_cast<std::string>(d) << " (flushed to disk)\n"; } };

// 8
class TempScreen  : public IObserver { void update(const std::any& d) override { std::cout << " Экран: " << std::any_cast<int>(d) << "°C\n"; } };
class TempWarning : public IObserver {
    void update(const std::any& d) override {
        int t = std::any_cast<int>(d);
        if (t > 40) std::cout << " PREHEAT WARNING: " << t << "°C!\n";
    }
};

// 9
class ChatUser : public IObserver {
    std::string name_;
public:
    explicit ChatUser(std::string n) : name_(std::move(n)) {}
    void update(const std::any& d) override {
        std::cout << " " << name_ << " получил: " << std::any_cast<std::string>(d) << '\n';
    }
};

// 10
class HPManager : public IObserver {
    int hp_ = 100;
public:
    void update(const std::any& d) override {
        hp_ -= std::any_cast<int>(d);
        std::cout << " HP: " << hp_ << '\n';
    }
};
class SoundPlayer : public IObserver { void update(const std::any&) override { std::cout << " Play 'hit' sound\n"; } };
class VFXPlayer   : public IObserver { void update(const std::any&) override { std::cout << " Show damage VFX\n"; } };

//Блок 4 + Задача 20: Продвинутые задачи и EventManager
// 16
class ILogStrategy {
public:
    virtual ~ILogStrategy() = default;
    virtual void write(const std::string& msg) const = 0;
};
class ConsoleStrategy : public ILogStrategy { void write(const std::string& msg) const override { std::cout << "[STRATEGY:CONSOLE] " << msg << '\n'; } };
class FileStrategy    : public ILogStrategy { void write(const std::string& msg) const override { std::cout << "[STRATEGY:FILE]    " << msg << " (saved)\n"; } };

class StrategyObserver : public IObserver {
    std::unique_ptr<ILogStrategy> strategy_;
public:
    explicit StrategyObserver(std::unique_ptr<ILogStrategy> s) : strategy_(std::move(s)) {}
    void update(const std::any& d) override {
        if (strategy_) strategy_->write(std::any_cast<std::string>(d));
    }
};

// 17
class ObserverFactory {
    using Creator = std::function<std::shared_ptr<IObserver>()>;
    static std::unordered_map<std::string, Creator>& registry() {
        static std::unordered_map<std::string, Creator> map;
        return map;
    }
public:
    static void registerType(const std::string& type, Creator creator) { registry()[type] = std::move(creator); }
    static std::shared_ptr<IObserver> create(const std::string& type) {
        auto it = registry().find(type);
        return (it != registry().end()) ? it->second() : nullptr;
    }
};

//  15 19 20
class EventManager {
    std::unordered_map<std::string, std::vector<std::function<void(const std::any&)>>> handlers_;
public:
    void subscribe(const std::string& event, std::function<void(const std::any&)> handler) {
        handlers_[event].push_back(std::move(handler));
    }

    void emit(const std::string& event, const std::any& data = {}) {
        if (auto it = handlers_.find(event); it != handlers_.end()) {
            for (auto& h : it->second) h(data); // Прямой вызов, без if/switch
        }
    }

    void clear(const std::string& event) { handlers_.erase(event); }
    void clearAll() { handlers_.clear(); }
};
