#include <iostream>
#include <memory>
#include <stack>


class Command {
public:
    virtual ~Command() = default;
    virtual void execute() = 0;
    virtual void undo() = 0;
};


class Light {
public:
    void turnOn() { std::cout << "[Свет] ВКЛЮЧЕН\n"; }
    void turnOff() { std::cout << "[Свет] ВЫКЛЮЧЕН\n"; }
};


class TurnOnCommand : public Command {
    Light* light;
public:
    explicit TurnOnCommand(Light* l) : light(l) {}
    void execute() override { light->turnOn(); }
    void undo() override { light->turnOff(); }
};

class TurnOffCommand : public Command {
    Light* light;
public:
    explicit TurnOffCommand(Light* l) : light(l) {}
    void execute() override { light->turnOff(); }
    void undo() override { light->turnOn(); }
};


class Remote {
    std::stack<std::unique_ptr<Command>> history;
public:
    void press(std::unique_ptr<Command> cmd) {
        cmd->execute();
        history.push(std::move(cmd));
    }
    void undo() {
        if (!history.empty()) {
            history.top()->undo();
            history.pop();
        }
    }
};


int main() {
    setlocale(LC_ALL, "Russian");
    Light lamp;
    Remote remote;

    std::cout << "=== Выполнение команд ===\n";
 
    remote.press(std::make_unique<TurnOnCommand>(&lamp));
    remote.press(std::make_unique<TurnOffCommand>(&lamp));
    remote.press(std::make_unique<TurnOnCommand>(&lamp));

    std::cout << "\n=== Отмена действий (undo) ===\n";
    remote.undo(); 
    remote.undo(); 
    remote.undo(); 

    return 0;
}
