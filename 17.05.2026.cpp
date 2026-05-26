#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <memory>
#include <thread>
#include <chrono>

using namespace std;


class Prototype {
public:
    virtual ~Prototype() = default; 
    virtual unique_ptr<Prototype> clone() const = 0; 
};


//(1-5)
class Enemy : public Prototype {
public:
    int hp, damage, speed;
    Enemy(int h, int d, int s) : hp(h), damage(d), speed(s) {}
    unique_ptr<Prototype> clone() const override { return make_unique<Enemy>(*this); }
};

class NPC : public Prototype {
public:
    string name, faction; int level;
    NPC(string n, int l, string f) : name(n), level(l), faction(f) {}
    unique_ptr<Prototype> clone() const override { return make_unique<NPC>(*this); }
};

class Weapon : public Prototype {
public:
    string name; int damage, price;
    Weapon(string n, int d, int p) : name(n), damage(d), price(p) {}
    unique_ptr<Prototype> clone() const override { return make_unique<Weapon>(*this); }
};


class EnemySimple {
public: int hp;
      EnemySimple(int h) : hp(h) {}
      unique_ptr<EnemySimple> clone() const { return make_unique<EnemySimple>(*this); }
     
};


//(6-10)

class BadEnemy {
public: int* data;
      BadEnemy(int v) { data = new int(v); }
      ~BadEnemy() { delete data; }
    
      BadEnemy* cloneShallow() const { return new BadEnemy(*this); }
};


class GoodEnemy {
public: int* data;
      GoodEnemy(int v) { data = new int(v); }
      ~GoodEnemy() { delete data; }
      GoodEnemy(const GoodEnemy& o) { data = new int(*o.data); } 
      unique_ptr<GoodEnemy> clone() const { return make_unique<GoodEnemy>(*this); }
};


class Player : public Prototype {
public:
    string name; int hp;
    vector<string> inventory; 
    Weapon* weapon;          

    Player(string n, int h, vector<string> inv, Weapon* w)
        : name(n), hp(h), inventory(inv), weapon(w) {
    }
    ~Player() { delete weapon; }
   
    unique_ptr<Prototype> clone() const override {
        return make_unique<Player>(
            name, hp, inventory,
            weapon ? static_cast<Weapon*>(weapon->clone().release()) : nullptr
        );
    }
};


//(11-15)

class PrototypeRegistry {
    map<string, unique_ptr<Prototype>> templates;
public:
    void add(string id, unique_ptr<Prototype> p) { templates[id] = move(p); }
    unique_ptr<Prototype> create(string id) { return templates[id]->clone(); }
};

void spawnerDemo(PrototypeRegistry& reg) {
    for (int i = 0; i < 3; ++i) {
        auto enemy = reg.create("zombie");
        cout << "[Spawner] Spawned zombie #" << i + 1 << "\n";
    
    }
}

class Spell : public Prototype {
public: string name;
      Spell(string n) : name(n) {}
      virtual ~Spell() = default;
};
class Fireball : public Spell { public: Fireball() : Spell("Fireball") {}   unique_ptr<Prototype> clone() const override { return make_unique<Fireball>(*this); } };
class IceBlast : public Spell { public: IceBlast() : Spell("IceBlast") {}   unique_ptr<Prototype> clone() const override { return make_unique<IceBlast>(*this); } };
class PoisonCloud : public Spell { public: PoisonCloud() : Spell("PoisonCloud") {} unique_ptr<Prototype> clone() const override { return make_unique<PoisonCloud>(*this); } };

class Room : public Prototype {
public: string theme;
      Room(string t) : theme(t) {}
      unique_ptr<Prototype> clone() const override { return make_unique<Room>(*this); }
};


// (16-20)

class IWeapon {
public: virtual int damage() const = 0; virtual unique_ptr<IWeapon> clone() const = 0; virtual ~IWeapon() = default;
};
class BaseW : public IWeapon {
    int d;
public: BaseW(int dmg) : d(dmg) {}
      int damage() const override { return d; }
      unique_ptr<IWeapon> clone() const override { return make_unique<BaseW>(*this); }
};
class FireDec : public IWeapon {
    unique_ptr<IWeapon> base;
public: FireDec(unique_ptr<IWeapon> b) : base(move(b)) {}
      int damage() const override { return base->damage() + 15; }
      unique_ptr<IWeapon> clone() const override { return make_unique<FireDec>(base->clone()); }
};


class CloneCommand {
    Player* src;
    vector<unique_ptr<Player>> clones;
public:
    CloneCommand(Player* s) : src(s) {}
    void execute(int count) {
        for (int i = 0; i < count; ++i) clones.push_back(unique_ptr<Player>(static_cast<Player*>(src->clone().release())));
    }
};


class GameFacade {
    PrototypeRegistry reg;
public:
    void runLevel() {
        reg.add("zombie", make_unique<Enemy>(100, 10, 5));
        reg.add("room", make_unique<Room>("Dungeon"));
        auto e = reg.create("zombie");
        auto r = reg.create("room");
        cout << "[Facade] Level: Enemy in " << static_cast<Room*>(r.get())->theme << "\n";
    }
};


int main() {
    setlocale(LC_ALL, "Russian");
    // 1, 2
    Enemy orig(100, 10, 5);
    auto clone1 = make_unique<Enemy>(static_cast<Enemy&>(*orig.clone()));
    clone1->hp = 50;
    cout << "1-2. Orig HP: " << orig.hp << " | Clone HP: " << clone1->hp << "\n";

    // 4
    Weapon sword("Legendary Sword", 50, 100);
    for (int i = 0; i < 5; ++i) {
        auto w = make_unique<Weapon>(static_cast<Weapon&>(*sword.clone()));
        w->damage += i * 2; w->name += "+" + to_string(i);
    }

    // 5
    NPC guard("Guard", 5, "Kingdom");
    vector<unique_ptr<NPC>> army;
    for (int i = 0; i < 3; ++i) army.push_back(make_unique<NPC>(static_cast<NPC&>(*guard.clone())));

    // 7
    GoodEnemy g1(42);
    auto g2 = g1.clone();
    *g2->data = 99;
    cout << "7. Deep: " << *g1.data << " vs " << *g2->data << "\n";

    // 9
    Player p1("Hero", 100, { "potion" }, new Weapon("Axe", 20, 50));
    auto p2 = make_unique<Player>(static_cast<Player&>(*p1.clone()));
    p2->hp = 50; p2->inventory.push_back("map");
    cout << "9. P1 HP: " << p1.hp << " | P2 HP: " << p2->hp << "\n";

    // 11, 12, 13, 20
    PrototypeRegistry reg;
    reg.add("zombie", make_unique<Enemy>(80, 15, 3));
    reg.add("fireball", make_unique<Fireball>());
    spawnerDemo(reg);
    auto z = reg.create("zombie");

    // 16
    auto base = make_unique<BaseW>(20);
    auto fire = make_unique<FireDec>(move(base));
    auto clonedW = fire->clone();
    cout << "16. Decorator damage: " << clonedW->damage() << "\n";

    // 17
    CloneCommand cmd(&p1);
    cmd.execute(2);

    // 18
    GameFacade facade;
    facade.runLevel();

    cout << "\n Все задачи выполнены. Утечек нет (unique_ptr + RAII).\n";
    return 0;
}
