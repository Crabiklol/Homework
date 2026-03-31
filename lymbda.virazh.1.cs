using System;

namespace StringDelegates
{
    
    delegate string StringFilter(string input);

    class Program
    {
        
        static string ToUpperCase(string input) 
        {
            return input.ToUpper();
        }

        static string ToStars(string input)
        {
            return new string('*', input.Length);
        }

        
        static void ProcessString(string input, StringFilter filter)
        {
            Console.WriteLine(filter(input));
        }

        static void Main(string[] args)
        {
            
            StringFilter filter;

            string testString = "Hello, World!";

            filter = ToUpperCase;
            ProcessString(testString, filter);

       
            filter = ToStars;
            ProcessString(testString, filter);
        }
    }
}
