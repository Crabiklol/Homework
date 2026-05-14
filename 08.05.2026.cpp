#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <unordered_map>
#include <stdexcept>
#include <functional>
#include <algorithm>

class IComponent {
public:
    virtual ~IComponent() = default;
    virtual std::string execute() const = 0;
    virtual double cost() const { return 0.0; }
    virtual bool validate(const std::string&) const { return true; }
};

class BaseComponent : public IComponent {
public:
    std::string execute() const override { return "Base"; }
    double cost() const override { return 1.0; }
};

class Decorator : public IComponent {
protected:
    std::unique_ptr<IComponent> wrapped; 
public:
    explicit Decorator(std::unique_ptr<IComponent> comp) : wrapped(std::move(comp)) {}
    ~Decorator() override = default;


    std::string execute() const override { return wrapped->execute(); }
    double cost() const override { return wrapped->cost(); }
    bool validate(const std::string& data) const override { return wrapped->validate(data); }
};

class BoldDecorator : public Decorator {
public:
    using Decorator::Decorator;
    std::string execute() const override { return "[B]" + wrapped->execute() + "[/B]"; }
};

class ItalicDecorator : public Decorator {
public:
    using Decorator::Decorator;
    std::string execute() const override { return "[I]" + wrapped->execute() + "[/I]"; }
};

class UnderlineDecorator : public Decorator {
public:
    using Decorator::Decorator;
    std::string execute() const override { return "[U]" + wrapped->execute() + "[/U]"; }
};

class CoffeeBase : public IComponent {
public:
    std::string execute() const override { return "Coffee"; }
    double cost() const override { return 2.0; }
};

class MilkDecorator : public Decorator {
public:
    using Decorator::Decorator;
    std::string execute() const override { return wrapped->execute() + " + Milk"; }
    double cost() const override { return wrapped->cost() + 0.5; }
};

class SugarDecorator : public Decorator {
public:
    using Decorator::Decorator;
    std::string execute() const override { return wrapped->execute() + " + Sugar"; }
    double cost() const override { return wrapped->cost() + 0.3; }
};

class OrderBase : public IComponent {
public:
    std::string execute() const override { return "Order"; }
    double cost() const override { return 10.0; }
};

class DeliveryDecorator : public Decorator {
public:
    using Decorator::Decorator;
    std::string execute() const override { return wrapped->execute() + " + Delivery"; }
    double cost() const override { return wrapped->cost() + 3.0; }
};

class PackagingDecorator : public Decorator {
public:
    using Decorator::Decorator;
    std::string execute() const override { return wrapped->execute() + " + Packaging"; }
    double cost() const override { return wrapped->cost() + 1.5; }
};

class DiscountDecorator : public Decorator {
    double discount_;
public:
    explicit DiscountDecorator(std::unique_ptr<IComponent> comp, double disc)
        : Decorator(std::move(comp)), discount_(disc) {
    }
    std::string execute() const override { return wrapped->execute() + " (-" + std::to_string(discount_ * 100) + "%)"; }
    double cost() const override { return wrapped->cost() * (1.0 - discount_); }
};

class LoggingDecorator : public Decorator {
public:
    using Decorator::Decorator;
    std::string execute() const override {
        std::cout << "[LOG] Before execute\n";
        std::string res = wrapped->execute();
        std::cout << "[LOG] After execute: " << res << "\n";
        return res;
    }
};

class ValidationDecorator : public Decorator {
public:
    using Decorator::Decorator;
    bool validate(const std::string& data) const override {
        if (data.empty()) throw std::invalid_argument("Empty data");
        return wrapped->validate(data);
    }
    std::string execute() const override { return wrapped->execute(); }
};

class CacheDecorator : public Decorator {
    mutable std::unordered_map<std::string, std::string> cache_;
public:
    using Decorator::Decorator;
    std::string execute() const override {
        std::string key = "default"; 
        auto it = cache_.find(key);
        if (it != cache_.end()) {
            std::cout << "[CACHE] Hit\n";
            return it->second;
        }
        std::string res = wrapped->execute();
        cache_[key] = res;
        std::cout << "[CACHE] Miss, stored\n";
        return res;
    }
};

class CharacterBase : public IComponent {
public:
    std::string execute() const override { return "Warrior"; }
    double cost() const override { return 100.0; }
};

class DamageBuff : public Decorator {
public:
    using Decorator::Decorator;
    std::string execute() const override { return wrapped->execute() + " (+DMG)"; }
};

class SpeedBuff : public Decorator {
public:
    using Decorator::Decorator;
    std::string execute() const override { return wrapped->execute() + " (+SPD)"; }
};

using DecoratorFactory = std::function<std::unique_ptr<IComponent>(std::unique_ptr<IComponent>)>;

std::unique_ptr<IComponent> buildChain(
    std::unique_ptr<IComponent> base,
    const std::vector<DecoratorFactory>& decorators)
{
    std::unique_ptr<IComponent> current = std::move(base);
   
    for (auto it = decorators.rbegin(); it != decorators.rend(); ++it) {
        current = (*it)(std::move(current));
    }
    return current;
}

class MessageBase : public IComponent {
    std::string content_;
public:
    explicit MessageBase(std::string c) : content_(std::move(c)) {}
    std::string execute() const override { return content_; }
};

class EncryptDecorator : public Decorator {
public:
    using Decorator::Decorator;
    std::string execute() const override {
        std::string raw = wrapped->execute();
        return "[ENCRYPTED]" + raw + "[/ENCRYPTED]";
    }
};

class CompressDecorator : public Decorator {
public:
    using Decorator::Decorator;
    std::string execute() const override {
        std::string raw = wrapped->execute();
        return "[COMPRESSED]" + raw + "[/COMPRESSED]";
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
   
    std::cout << "=== Задание 2 ===\n";
    auto comp1 = std::make_unique<BaseComponent>();
    auto dec1 = std::make_unique<BoldDecorator>(std::move(comp1));
    std::cout << dec1->execute() << "\n\n";


    std::cout << "=== Задание 3 ===\n";
    auto comp2 = std::make_unique<CoffeeBase>();
    auto milk = std::make_unique<MilkDecorator>(std::move(comp2));
    auto sugar = std::make_unique<SugarDecorator>(std::move(milk));
    std::cout << sugar->execute() << " | Cost: " << sugar->cost() << "\n\n";

  
    std::cout << "=== Задание 4 ===\n";
    auto base = std::make_unique<BaseComponent>();
    auto A = std::make_unique<BoldDecorator>(std::make_unique<BaseComponent>());
    auto B = std::make_unique<ItalicDecorator>(std::move(base));
  
    auto chain1 = std::make_unique<UnderlineDecorator>(std::make_unique<BoldDecorator>(std::make_unique<BaseComponent>()));
    auto chain2 = std::make_unique<BoldDecorator>(std::make_unique<UnderlineDecorator>(std::make_unique<BaseComponent>()));
    std::cout << "U(B(Base)): " << chain1->execute() << "\n";
    std::cout << "B(U(Base)): " << chain2->execute() << "\n\n";

  
    std::cout << "=== Задание 5 ===\n";
    std::cout << "Наследование: BoldCoffee, MilkCoffee, BoldMilkCoffee, SugarBoldMilkCoffee...\n";
    std::cout << "Комбинаторный взрыв: 2^n классов. Декоратор решает это композицией.\n\n";


    std::cout << "=== Задание 8 ===\n";
    auto txt = std::make_unique<UnderlineDecorator>(
        std::make_unique<BoldDecorator>(
            std::make_unique<ItalicDecorator>(std::make_unique<BaseComponent>())));
    std::cout << txt->execute() << "\n\n";


    std::cout << "=== Задания 11-12 ===\n";
    auto order = std::make_unique<DiscountDecorator>(
        std::make_unique<PackagingDecorator>(
            std::make_unique<DeliveryDecorator>(std::make_unique<OrderBase>())), 0.1);
    std::cout << order->execute() << " | Cost: " << order->cost() << "\n\n";


    std::cout << "=== Задание 13 ===\n";
    auto log = std::make_unique<LoggingDecorator>(std::make_unique<BaseComponent>());
    log->execute();
    std::cout << "\n";


    std::cout << "=== Задание 14 ===\n";
    auto val = std::make_unique<ValidationDecorator>(std::make_unique<BaseComponent>());
    try { val->validate(""); }
    catch (const std::exception& e) {
        std::cout << "Caught: " << e.what() << "\n";
    }


    std::cout << "\n=== Задание 15 ===\n";
    auto cache = std::make_unique<CacheDecorator>(std::make_unique<BaseComponent>());
    cache->execute(); 
    cache->execute(); 
    std::cout << "\n";


    std::cout << "=== Задания 16-17 ===\n";
    std::vector<DecoratorFactory> buffs;
    buffs.push_back([](auto c) { return std::make_unique<DamageBuff>(std::move(c)); });
    buffs.push_back([](auto c) { return std::make_unique<SpeedBuff>(std::move(c)); });

    auto hero = buildChain(std::make_unique<CharacterBase>(), buffs);
    std::cout << hero->execute() << "\n\n";


    std::cout << "=== Задание 19 ===\n";
    std::cout << "unique_ptr используется везде для владения (zero-copy move semantics).\n";
    std::cout << "shared_ptr нужен, если один объект обёрнут в несколько декораторов одновременно.\n\n";


    std::cout << "=== Задание 20 ===\n";
    auto msg = std::make_unique<CompressDecorator>(
        std::make_unique<EncryptDecorator>(
            std::make_unique<LoggingDecorator>(std::make_unique<MessageBase>("Secret Data"))));
    std::cout << msg->execute() << "\n";

    return 0;
}
