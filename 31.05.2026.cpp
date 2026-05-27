//1-5
#include <iostream>
#include <string>
#include <unordered_map>
#include <memory>
#include <atomic>
#include <iomanip>


struct CarExtrinsic {
    float x = 0.0f, y = 0.0f, speed = 0.0f;
};


class CarFlyweight {
    static std::atomic<int> instance_counter;
    const std::string model_, color_, engine_;
public:
    CarFlyweight(std::string m, std::string c, std::string e)
        : model_(std::move(m)), color_(std::move(c)), engine_(std::move(e)) {
        ++instance_counter;
    }
    static int get_count() { return instance_counter.load(); }

    const std::string& key() const {
        static thread_local std::string buf;
        buf = model_ + "_" + color_ + "_" + engine_;
        return buf;
    }
    void print() const {
        std::cout << "🚗 " << model_ << " | " << color_ << " | " << engine_ << "\n";
    }
};
std::atomic<int> CarFlyweight::instance_counter{0};


class CarFactory {
    std::unordered_map<std::string, std::shared_ptr<CarFlyweight>> cache_; // STL #2
public:
    std::shared_ptr<CarFlyweight> get(std::string m, std::string c, std::string e) {
        std::string key = m + "_" + c + "_" + e;
        if (auto it = cache_.find(key); it != cache_.end()) return it->second;
        auto fw = std::make_shared<CarFlyweight>(std::move(m), std::move(c), std::move(e));
        cache_[key] = fw;
        return fw;
    }
};


struct CarContext {
    std::shared_ptr<CarFlyweight> flyweight;
    CarExtrinsic extrinsic;
    void render() const {
        flyweight->print();
        std::cout << "   Коорд: (" << extrinsic.x << "," << extrinsic.y 
                  << ") Скорость: " << extrinsic.speed << "\n";
    }
};

int main() {
    CarFactory factory;
    
   
    std::vector<CarContext> cars(5);
    cars[0] = {factory.get("BMW", "red", "V6"), {0,0,60}};
    cars[1] = {factory.get("BMW", "red", "V6"), {10,0,80}}; 
    cars[2] = {factory.get("Audi", "blue", "V8"), {5,5,40}};
    cars[3] = {factory.get("Audi", "blue", "V8"), {-2,3,50}};
    cars[4] = {factory.get("Toyota", "white", "Hybrid"), {0,10,30}};

    std::cout << " Проверка адресов:\n";
    for (size_t i = 0; i < cars.size(); ++i)
        std::cout << "Car[" << i << "] FW addr: " << std::hex << cars[i].flyweight.get() << "\n";

    std::cout << "\n Создано flyweight-объектов: " << CarFlyweight::get_count() << "\n";
}

//6-10

struct TreeExtrinsic { float x, y, height; };
class TreeType {
    std::string texture_, model_, type_;
public:
    TreeType(std::string t, std::string m, std::string ty) 
        : texture_(std::move(t)), model_(std::move(m)), type_(std::move(ty)) {}
    void render_base() const { 
        std::cout << "[🌲 " << type_ << "] tex:" << texture_ << " model:" << model_ << "\n"; 
    }
};
struct Tree { std::shared_ptr<TreeType> type; TreeExtrinsic pos; };


struct CharExtrinsic { char symbol; int x, y; };
class CharacterStyle {
    std::string font_; int size_; std::string color_;
public:
    CharacterStyle(std::string f, int s, std::string c) : font_(std::move(f)), size_(s), color_(std::move(c)) {}
    void apply() const { std::cout << "Font:" << font_ << " Size:" << size_ << " Color:" << color_ << "\n"; }
};
struct Character { std::shared_ptr<CharacterStyle> style; CharExtrinsic pos; };


//11-12
class FontFactory {
    std::unordered_map<std::string, std::shared_ptr<std::string>> fonts_; 
public:
    std::shared_ptr<std::string> get_font(std::string name, int size) {
        std::string key = name + "_" + std::to_string(size);
        if (auto it = fonts_.find(key); it != fonts_.end()) return it->second;
        
        auto f = std::make_shared<std::string>("FontData_" + key);
        fonts_[key] = f;
        return f;
    }
};

//14
void run_massive_test() {
    CarFactory factory;
    std::vector<CarContext> fleet;
    fleet.reserve(10000);

    
    std::vector<std::tuple<std::string,std::string,std::string>> templates = {
        {"BMW","red","V6"}, {"Audi","blue","V8"}, {"Toyota","white","Hybrid"}, 
        {"Tesla","black","Electric"}, {"Lada","grey","Petrol"}
    };

    for (int i = 0; i < 10000; ++i) {
        auto& t = templates[i % templates.size()];
        fleet.push_back({
            factory.get(std::get<0>(t), std::get<1>(t), std::get<2>(t)),
            CarExtrinsic{float(i), float(i%100), float(30 + i%50)}
        });
    }

    std::cout << " Всего объектов: " << fleet.size() << "\n";
    std::cout << " Уникальных flyweight: " << CarFlyweight::get_count() << "\n";
    std::cout << " Экономия: ~" << (1 - double(CarFlyweight::get_count())/fleet.size()) * 100 << "%\n";
}

//15

class MutableFlyweight {
public:
    std::string shared_color; 
};

void demonstrate_bug() {
    auto fw1 = std::make_shared<MutableFlyweight>();
    fw1->shared_color = "red";
    
    auto fw2 = fw1;
    fw2->shared_color = "green"; 
    
    std::cout << "fw1 color: " << fw1->shared_color << "\n";
}

//16
struct IFlyweightFactory {
    virtual ~IFlyweightFactory() = default;
    virtual std::shared_ptr<void> get(const std::string& key) = 0;
};

class ConcreteFlyFactory : public IFlyweightFactory {
    std::unordered_map<std::string, std::shared_ptr<void>> cache_;
public:
    std::shared_ptr<void> get(const std::string& key) override {
        if (auto it = cache_.find(key); it != cache_.end()) return it->second;
        auto obj = std::make_shared<std::string>("Res:" + key);
        cache_[key] = obj;
        return obj;
    }
};

//17

class TextureProxy {
    std::string filename_;
    std::shared_ptr<std::vector<uint8_t>> data_; 
    bool loaded_ = false;
public:
    explicit TextureProxy(std::string fn) : filename_(std::move(fn)) {}
    
    const std::vector<uint8_t>& get_data() {
        if (!loaded_) {
            std::cout << " Lazy loading: " << filename_ << "\n";
            data_ = std::make_shared<std::vector<uint8_t>>(1024 * 1024);
            loaded_ = true;
        }
        return *data_;
    }
};

//18
struct IRenderable { virtual ~IRenderable() = default; virtual void render() const = 0; };

class MeshFlyweight {
    std::string mesh_name_;
public:
    explicit MeshFlyweight(std::string n) : mesh_name_(std::move(n)) {}
    void draw() const { std::cout << "Drawing mesh: " << mesh_name_ << "\n"; }
};

class SceneLeaf : public IRenderable {
    std::shared_ptr<MeshFlyweight> mesh;
    std::string position_;
public:
    SceneLeaf(std::shared_ptr<MeshFlyweight> m, std::string pos) 
        : mesh(std::move(m)), position_(std::move(pos)) {}
    void render() const override { mesh->draw(); }
};

class SceneGroup : public IRenderable {
    std::vector<std::shared_ptr<IRenderable>> children_;
public:
    void add(std::shared_ptr<IRenderable> c) { children_.push_back(std::move(c)); }
    void render() const override { for (auto& c : children_) c->render(); }
};

//19
class WeakCache {
    std::unordered_map<std::string, std::weak_ptr<void>> cache_;
public:
    std::shared_ptr<void> get_or_create(const std::string& key, std::function<std::shared_ptr<void>()> creator) {
        if (auto sp = cache_[key].lock()) return sp; 
        auto new_obj = creator();
        cache_[key] = new_obj;
        return new_obj;
    }
    
    void compact() {
        for (auto it = cache_.begin(); it != cache_.end();) {
            if (it->second.expired()) it = cache_.erase(it);
            else ++it;
        }
    }
};

//20
#include <iostream>
#include <vector>
#include <unordered_map>
#include <memory>
#include <string>
#include <atomic>
#include <iomanip>


struct RenderResource {
    std::string model_, texture_, animation_, sound_;
};

class ResourceFactory {
    static std::atomic<int> fw_count;
    std::unordered_map<std::string, std::shared_ptr<RenderResource>> cache_;
public:
    std::shared_ptr<RenderResource> get(const std::string& model, const std::string& tex,
                                        const std::string& anim, const std::string& snd) {
        std::string key = model + "|" + tex + "|" + anim + "|" + snd;
        if (auto it = cache_.find(key); it != cache_.end()) return it->second;
        
        auto res = std::make_shared<RenderResource>(RenderResource{model, tex, anim, snd});
        cache_[key] = res;
        ++fw_count;
        return res;
    }
    static int get_fw_count() { return fw_count.load(); }
};
std::atomic<int> ResourceFactory::fw_count{0};


struct EntityContext {
    std::shared_ptr<RenderResource> resource;
    float x = 0, y = 0, z = 0;
    std::string state = "idle";
    int health = 100;
    float direction = 0.0f;
};


class GameWorld {
    std::vector<EntityContext> entities_;
    std::unique_ptr<ResourceFactory> res_factory_ = std::make_unique<ResourceFactory>();
public:
    void spawn_entity(const std::string& type, float x, float y, float z, float dir) {
        std::string model, tex, anim, snd;
        if (type == "Tree")      { model="pine.obj"; tex="bark.png"; anim="wind.anim"; snd="rustle.wav"; }
        else if (type == "Rock") { model="boulder.obj"; tex="stone.png"; anim="static.anim"; snd="none.wav"; }
        else if (type == "Grass"){ model="grass.obj"; tex="green.png"; anim="sway.anim"; snd="none.wav"; }
        else if (type == "NPC")  { model="human.obj"; tex="cloth.png"; anim="walk.anim"; snd="steps.wav"; }
        
        entities_.push_back({
            res_factory_->get(model, tex, anim, snd),
            x, y, z, "active", 100, dir
        });
    }

    void print_stats() const {
        std::cout << " СТАТИСТИКА МИРА\n";
        std::cout << " Игровых объектов: " << entities_.size() << "\n";
        std::cout << " Flyweight ресурсов: " << ResourceFactory::get_fw_count() << "\n";
        std::cout << " Экономия объектов: " 
                  << std::fixed << std::setprecision(1)
                  << (1.0 - double(ResourceFactory::get_fw_count()) / entities_.size()) * 100 << "%\n";
    }
};

int main() {
    GameWorld world;
    
    for (int i = 0; i < 1250; ++i) {
        const char* types[] = {"Tree", "Rock", "Grass", "NPC"};
        world.spawn_entity(types[i % 4], float(i), float(i%100), 0.0f, 0.0f);
    }
    world.print_stats();
    return 0;
}
