using System;

namespace BookExample
{
   
    class Book
    {
       
        public string Title;
        public string Author;
        public int Year;

       
        public Book()
        {
        }

        
        public Book(string title, string author, int year)
        {
            Title = title;
            Author = author;
            Year = year;
        }

       
        public void PrintInfo()
        {
            Console.WriteLine($"Название: {Title}");
            Console.WriteLine($"Автор: {Author}");
            Console.WriteLine($"Год: {Year}");
        }

      
        public bool IsOld()
        {
            int currentYear = DateTime.Now.Year;
            return (currentYear - Year) > 20;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            
            Book book1 = new Book("Война и Мир", "Лев Толстой", 1869);
            book1.PrintInfo();
            Console.WriteLine($"Это старая книга? {book1.IsOld()}");
            Console.WriteLine();

            
            Book book2 = new Book 
            {
                Title = "1984",
                Author = "Джордж Оруэлл",
                Year = 1949
            };
            book2.PrintInfo();
            Console.WriteLine($"Это старая книга? {book2.IsOld()}");
            Console.WriteLine();

           
            Book book3 = new Book();
            book3.Title = "Мастер и Маргарита";
            book3.Author = "Михаил Булгаков";
            book3.Year = 1967;
            book3.PrintInfo();
            Console.WriteLine($"Это старая книга? {book3.IsOld()}");
        }
    }
}
