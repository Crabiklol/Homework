//zadanie 1
using System;

public class Vector2D
{
   
    public double X { get; }
    public double Y { get; }

  
    public Vector2D(double x, double y)
    {
        X = x;
        Y = y;
    }

    public static Vector2D operator +(Vector2D v1, Vector2D v2)
    {
        return new Vector2D(v1.X + v2.X, v1.Y + v2.Y);
    }

    public static Vector2D operator -(Vector2D v1, Vector2D v2)
    {
        return new Vector2D(v1.X - v2.X, v1.Y - v2.Y);
    }

   
    public static Vector2D operator *(Vector2D v, double scalar)
    {
        return new Vector2D(v.X * scalar, v.Y * scalar);
    }

    
    public static bool operator ==(Vector2D v1, Vector2D v2)
    {
        if (ReferenceEquals(v1, v2))
            return true;
        if (v1 is null || v2 is null)
            return false;
        return v1.X == v2.X && v1.Y == v2.Y;
    }

   
    public static bool operator !=(Vector2D v1, Vector2D v2)
    {
        return !(v1 == v2);
    }

    
    public override bool Equals(object obj)
    {
        if (obj is null) return false;
        if (ReferenceEquals(this, obj)) return true;
        if (obj.GetType() != GetType()) return false;
        Vector2D other = (Vector2D)obj;
        return X == other.X && Y == other.Y;
    }

   
    public override int GetHashCode()
    {
        unchecked
        {
            int hash = 17;
            hash = hash * 23 + X.GetHashCode();
            hash = hash * 23 + Y.GetHashCode();
            return hash;
        }
    }

    
    public override string ToString()
    {
        return $"({X}, {Y})";
    }
}

//zadanie 2
using System;

public class Temperature
{

    public double Celsius { get; private set; }


    public Temperature(double celsius)
    {
        Celsius = celsius;
    }


    public static Temperature operator +(Temperature temp, double degrees)
    {
        return new Temperature(temp.Celsius + degrees);
    }


    public static Temperature operator -(Temperature temp, double degrees)
    {
        return new Temperature(temp.Celsius - degrees);
    }


    public static bool operator >(Temperature temp1, Temperature temp2)
    {
        return temp1.Celsius > temp2.Celsius;
    }


    public static bool operator <(Temperature temp1, Temperature temp2)
    {
        return temp1.Celsius < temp2.Celsius;
    }

    public static implicit operator double(Temperature temp)
    {
        return temp.Celsius;
    }

   
    public static explicit operator Temperature(double value)
    {
        return new Temperature(value);
    }


    public override string ToString()
    {
        return $"{Celsius}°C";
    }
}

//zadanie 3
using System;
using System.Collections.Generic;
using System.Linq;

public class StudentJournal
{
   
    private List<double> _grades = new List<double>();


    public double this[int index]
    {
        get
        {
            if (index < 0 || index >= _grades.Count)
                throw new IndexOutOfRangeException("Индекс выходит за пределы диапазона оценок.");
            return _grades[index];
        }
        set
        {
            if (index < 0 || index >= _grades.Count)
                throw new IndexOutOfRangeException("Индекс выходит за пределы диапазона оценок.");
            if (value < 1 || value > 5)  // предполагаем шкалу 1–5
                throw new ArgumentException("Оценка должна быть от 1 до 5.");
            _grades[index] = value;
        }
    }

   
    public double AverageGrade
    {
        get
        {
            if (_grades.Count == 0)
                return 0;  // если оценок нет, средний балл = 0
            return _grades.Average();
        }
    }

    
    public void AddGrade(double grade)
    {
        if (grade < 1 || grade > 5)
            throw new ArgumentException("Оценка должна быть от 1 до 5.");
        _grades.Add(grade);
    }


    public int Count => _grades.Count;

    
    public override string ToString()
    {
        return $"Оценки: {string.Join(", ", _grades)} | Средний балл: {AverageGrade:F2}";
    }
}
//zadanie 4
using System;

public class ChessBoard
{
    
    private const int Size = 8;

   
    private char[,] _board = new char[Size, Size];

   
    public ChessBoard()
    {
        for (int row = 0; row < Size; row++)
        {
            for (int col = 0; col < Size; col++)
            {
                _board[row, col] = '.';
            }
        }
    }

    public char this[int row, int col]
    {
        get
        {
            ValidateCoordinates(row, col);
            return _board[row, col];
        }
        set
        {
            ValidateCoordinates(row, col);
            _board[row, col] = value;
        }
    }

    private void ValidateCoordinates(int row, int col)
    {
        if (row < 0 || row >= Size || col < 0 || col >= Size)
        {
            throw new IndexOutOfRangeException(
                $"Координаты должны быть в диапазоне [0, {Size - 1}]. Получено: ({row}, {col})");
        }
    }


    public void Print()
    {
        Console.WriteLine("  a b c d e f g h");
        for (int row = 0; row < Size; row++)
        {
            Console.Write($"{8 - row} "); 
            for (int col = 0; col < Size; col++)
            {
                Console.Write(_board[row, col] + " ");
            }
            Console.WriteLine();
        }
    }
}

//zadanie 5
using System;

public class Car
{
    
    public string Brand { get; set; }
    public string Model { get; set; }

 
    private double _speed;

    
    public double Speed
    {
        get => _speed;
        set
        {
            if (value < 0)
                throw new ArgumentException("Скорость не может быть отрицательной.");
            _speed = value;
        }
    }


    public bool IsMoving => _speed > 0;


    public Car(string brand, string model, double speed = 0)
    {
        Brand = brand;
        Model = model;
        Speed = speed; 
    }
}

//zadanie 6
using System;

public class UserAccount
{
 
    public string Login { get; private set; }

    
    private string _password;

   
    public string Password 
    {
        get => _password;
        private set
        {
            if (string.IsNullOrEmpty(value))
                throw new ArgumentException("Пароль не может быть пустым.");
            
            if (value.Length < 6)
                throw new ArgumentException("Длина пароля должна быть не менее 6 символов.");

            _password = value;
        }
    }

   
    public UserAccount(string login, string password)
    {
        if (string.IsNullOrEmpty(login))
            throw new ArgumentException("Логин не может быть пустым.");

        Login = login;
        Password = password; // валидация и установка пароля
    }

    
    public bool ChangePassword(string oldPass, string newPass)
    {
        
        if (_password != oldPass)
        {
            Console.WriteLine("Ошибка: неверный текущий пароль.");
            return false;
        }

        
        if (newPass.Length < 6)
        {
            Console.WriteLine("Ошибка: новый пароль должен содержать не менее 6 символов.");
            return false;
        }

        
        Password = newPass;
        Console.WriteLine("Пароль успешно изменён.");
        return true;
    }
}

