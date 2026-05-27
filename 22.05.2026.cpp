#include <iostream>
#include <string>
#include <memory>

class Character {
    std::string name_;
    std::string role_;
    int hp_;
    std::string weapon_;

    
    Character(std::string n, std::string r, int hp, std::string w)
        : name_(std::move(n)), role_(std::move(r)), hp_(hp), weapon_(std::move(w)) {
    }

    
    friend class CharacterBuilder;

public:
    void print() const {
        std::cout << "[Персонаж] " << name_ << " (" << role_ << ") | HP: " << hp_
            << " | Оружие: " << weapon_ << "\n";
    }
};

class CharacterBuilder {
    std::string name_;
    std::string role_ = "Новичок";
    int hp_ = 100;
    std::string weapon_ = "Кулаки";

public:
    CharacterBuilder& setName(const std::string& n) {
        name_ = n;
        return *this;
    }

    CharacterBuilder& setRole(const std::string& r) {
        role_ = r;
        return *this;
    }

    CharacterBuilder& setHP(int hp) {
        hp_ = hp;
        return *this;
    }

    CharacterBuilder& setWeapon(const std::string& w) {
        weapon_ = w;
        return *this;
    }

    std::unique_ptr<Character> build() {
        if (name_.empty()) {
            std::cerr << "[Ошибка] Имя не может быть пустым!\n";
            return nullptr;
        }
        if (hp_ <= 0) {
            std::cerr << "[Ошибка] HP должен быть > 0!\n";
            return nullptr;
        }
        
        return std::unique_ptr<Character>(new Character(name_, role_, hp_, weapon_));
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    auto hero = CharacterBuilder()
        .setName("Артас")
        .setRole("Рыцарь смерти")
        .setHP(250)
        .setWeapon("Фростморн")
        .build();

    if (hero) {
        hero->print();
    }

    return 0;
}
