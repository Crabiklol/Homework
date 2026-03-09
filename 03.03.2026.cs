using System;

namespace FleetManagement
{
    // Класс автомобиля
    public class Car
    {
        public string LicensePlate { get; set; }   // Номерной знак
        public string Model { get; set; }          // Модель
        public string DriverName { get; set; }     // Имя водителя

        public Car(string licensePlate, string model, string driverName)
        {
            LicensePlate = licensePlate;
            Model = model;
            DriverName = driverName;
        }

        public override string ToString()
        {
            return $"Номер: {LicensePlate}, Модель: {Model}, Водитель: {DriverName}";
        }
    }

    // Класс автопарка
    public class Fleet
    {
        private Car[] _cars;

        public Fleet(params Car[] initialCars)
        {
            _cars = initialCars ?? Array.Empty<Car>();
        }

        // Индексатор по целочисленному индексу
        public Car this[int index]
        {
            get
            {
                if (index < 0 || index >= _cars.Length)
                    throw new IndexOutOfRangeException("Индекс вне диапазона массива автопарка.");
                return _cars[index];
            }
            set
            {
                if (index < 0 || index >= _cars.Length)
                    throw new IndexOutOfRangeException("Индекс вне диапазона массива автопарка.");
                _cars[index] = value;
            }
        }

        // Индексатор по номерному знаку (строка)
        public Car this[string licensePlate]
        {
            get
            {
                for (int i = 0; i < _cars.Length; i++)
                {
                    if (string.Equals(_cars[i].LicensePlate, licensePlate, StringComparison.OrdinalIgnoreCase))
                    {
                        return _cars[i];
                    }
                }
                return null; // если не найден
            }
            set
            {
                // Сначала ищем существующий автомобиль с таким номером
                for (int i = 0; i < _cars.Length; i++)
                {
                    if (string.Equals(_cars[i].LicensePlate, licensePlate, StringComparison.OrdinalIgnoreCase))
                    {
                        _cars[i] = value;
                        return;
                    }
                }

                // Если не нашли — добавляем новый автомобиль в массив
                // (расширяем массив на 1 элемент)
                int newLength = _cars.Length + 1;
                Car[] newArray = new Car[newLength];
                for (int i = 0; i < _cars.Length; i++)
                {
                    newArray[i] = _cars[i];
                }

                newArray[newLength - 1] = value;
                _cars = newArray;
            }
        }

        // Вспомогательный метод для вывода всех машин (не обязателен, но полезен для демонстрации)
        public void PrintAll()
        {
            Console.WriteLine("Текущий список автомобилей в автопарке:");
            for (int i = 0; i < _cars.Length; i++)
            {
                Console.WriteLine($"{i}: {_cars[i]}");
            }
            Console.WriteLine();
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            // Создаем автопарк с начальными машинами
            Fleet fleet = new Fleet(
                new Car("A111AA", "Volvo FH", "Иванов Иван"),
                new Car("A123BC", "Mercedes Actros", "Петров Петр"),
                new Car("B222BB", "Scania R", "Сидоров Сидор")
            );

            fleet.PrintAll();

            // 1. Получение и вывод информации об автомобиле по индексу 1
            Console.WriteLine("Автомобиль по индексу 1:");
            Car carByIndex = fleet[1];
            Console.WriteLine(carByIndex);
            Console.WriteLine();

            // 2. Получение и вывод информации об автомобиле по номерному знаку "A123BC"
            Console.WriteLine("Автомобиль по номеру \"A123BC\":");
            Car carByPlate = fleet["A123BC"];
            if (carByPlate != null)
            {
                Console.WriteLine(carByPlate);
            }
            else
            {
                Console.WriteLine("Автомобиль с таким номером не найден.");
            }
            Console.WriteLine();

            // 3. Добавление нового автомобиля в автопарк с новым номерным знаком
            Console.WriteLine("Добавляем новый автомобиль с номером \"C333CC\":");
            fleet["C333CC"] = new Car("C333CC", "MAN TGX", "Кузнецов Алексей");

            // Проверяем, что автомобиль добавился
            fleet.PrintAll();

            // Чтобы окно не закрывалось сразу (если запускаете из IDE)
            Console.WriteLine("Нажмите любую клавишу для выхода...");
            Console.ReadKey();
        }
    }
}
