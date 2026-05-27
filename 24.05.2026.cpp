#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <queue>
#include <functional>
#include <algorithm>
#include <stdexcept>


class Component {
public:
    virtual ~Component() = default;
    virtual std::string getName() const = 0;

    
    virtual void add(std::unique_ptr<Component> child) {
        throw std::logic_error("Leaf: add() not supported");
    }
    virtual void remove(const std::string& name) {
        throw std::logic_error("Leaf: remove() not supported");
    }
    virtual Component* find(const std::string& name) = 0;

   
    virtual int count() const = 0;
    virtual int getSize() const = 0;
    virtual void display(int depth = 0) const = 0;

   
    virtual void dfs(std::function<void(const Component*)> visitor) const = 0;
    virtual void bfs(std::function<void(const Component*)> visitor) const = 0;

   
    virtual std::vector<const Component*> getRawChildren() const {
        return {};
    }
};


class Leaf : public Component {
    std::string name_;
    int size_;
public:
    Leaf(std::string name, int size) : name_(std::move(name)), size_(size) {}

    std::string getName() const override { return name_; }
    int getSize() const override { return size_; }
    int count() const override { return 1; }

    Component* find(const std::string& name) override {
        return name_ == name ? this : nullptr;
    }

    void display(int depth) const override {
        std::cout << std::string(depth * 2, ' ') << "├─ " << name_
            << " (" << size_ << " KB)\n";
    }

    void dfs(std::function<void(const Component*)> v) const override {
        v(this);
    }

    void bfs(std::function<void(const Component*)> v) const override {
        v(this);
    }
};


class Composite : public Component {
    std::string name_;
    std::vector<std::unique_ptr<Component>> children_;

public:
    explicit Composite(std::string name) : name_(std::move(name)) {}

    std::string getName() const override { return name_; }

    void add(std::unique_ptr<Component> child) override {
        children_.push_back(std::move(child));
    }

    void remove(const std::string& name) override {
        auto it = std::remove_if(children_.begin(), children_.end(),
            [&](const auto& c) { return c->getName() == name; });
        children_.erase(it, children_.end());
    }

    Component* find(const std::string& name) override {
        if (name_ == name) return this;
        for (auto& child : children_) {
            if (auto* found = child->find(name))
                return found;
        }
        return nullptr;
    }

    int count() const override {
        int c = 1;
        for (const auto& child : children_)
            c += child->count();
        return c;
    }

    int getSize() const override {
        int total = 0;
        for (const auto& child : children_)
            total += child->getSize();
        return total;
    }

    void display(int depth = 0) const override {
        std::cout << std::string(depth * 2, ' ') << " " << name_ << "\n";
        for (const auto& child : children_)
            child->display(depth + 1);
    }

    void dfs(std::function<void(const Component*)> v) const override {
        v(this);
        for (const auto& child : children_)
            child->dfs(v);
    }

    void bfs(std::function<void(const Component*)> v) const override {
        std::queue<const Component*> q;
        q.push(this);
        while (!q.empty()) {
            const auto* curr = q.front();
            q.pop();
            v(curr);
            for (auto* child : curr->getRawChildren())
                q.push(child);
        }
    }

    std::vector<const Component*> getRawChildren() const override {
        std::vector<const Component*> ptrs;
        ptrs.reserve(children_.size());
        for (const auto& c : children_)
            ptrs.push_back(c.get());
        return ptrs;
    }
};


int main() {
    setlocale(LC_ALL, "Russian");
    std::cout << "=== COMPOSITE PATTERN DEMO ===\n\n";

 
    auto root = std::make_unique<Composite>(" AppRoot");

    auto fileMenu = std::make_unique<Composite>(" File");
    fileMenu->add(std::make_unique<Leaf>("New", 12));
    fileMenu->add(std::make_unique<Leaf>("Open", 15));
    fileMenu->add(std::make_unique<Leaf>("Save", 10));

    auto editMenu = std::make_unique<Composite>(" Edit");
    editMenu->add(std::make_unique<Leaf>("Copy", 5));
    editMenu->add(std::make_unique<Leaf>("Paste", 5));

    auto toolsMenu = std::make_unique<Composite>(" Tools");
    auto pluginsSub = std::make_unique<Composite>(" Plugins");
    auto settingsSub = std::make_unique<Composite>(" Settings");
    auto advancedSub = std::make_unique<Composite>(" Advanced");
    advancedSub->add(std::make_unique<Leaf>("Debug Mode", 20));
    settingsSub->add(std::move(advancedSub));
    pluginsSub->add(std::make_unique<Leaf>("Theme Loader", 25));
    toolsMenu->add(std::move(pluginsSub));
    toolsMenu->add(std::move(settingsSub));

    root->add(std::move(fileMenu));
    root->add(std::move(editMenu));
    root->add(std::move(toolsMenu));


    std::cout << " Структура меню:\n";
    root->display();
    std::cout << "\n";

   
    std::cout << " Всего пунктов: " << root->count() << "\n";
    std::cout << " Общий размер: " << root->getSize() << " KB\n\n";


    std::cout << " Поиск 'Paste': ";
    if (auto* found = root->find("Paste"))
        std::cout << "Найдено '" << found->getName() << "'\n";
    else
        std::cout << "Не найдено\n";

    
    std::cout << "\n  Удаляем 'Copy'...\n";
    root->remove("Copy");
    root->display();
    std::cout << " Пунктов осталось: " << root->count() << "\n\n";

    
    std::cout << " DFS обход: ";
    root->dfs([](const Component* c) {
        std::cout << c->getName() << " ";
        });
    std::cout << "\n";

    
    std::cout << " BFS обход: ";
    root->bfs([](const Component* c) {
        std::cout << c->getName() << " ";
        });
    std::cout << "\n\n";

    std::cout << " Все тесты пройдены!\n";

    return 0;
}
