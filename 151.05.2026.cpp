#include <iostream>


class Engine {
public:
    void start() { std::cout << "  [Engine] Запущен\n"; }
    void stop() { std::cout << "  [Engine] Остановлен\n"; }
};

class Radio {
public:
    void on() { std::cout << "  [Radio] Включено\n"; }
    void off() { std::cout << "  [Radio] Выключено\n"; }
};


class CarFacade {
    Engine engine;
    Radio radio;

public:
  
    void startTrip() {
        std::cout << "--- Начало поездки ---\n";
        engine.start();
        radio.on();
    }

    void endTrip() {
        std::cout << "--- Конец поездки ---\n";
        radio.off();
        engine.stop();
    }
};


int main() {
    setlocale(LC_ALL, "Russian");
    CarFacade car; 

    std::cout << "=== Утро ===\n";
    car.startTrip();

    std::cout << "\n=== Вечер ===\n";
    car.endTrip();   

    return 0;
}
