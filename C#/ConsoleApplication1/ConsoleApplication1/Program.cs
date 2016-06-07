using System;

namespace MutatorsAndAccessors
{
    class Human
    {
        uint age;

        public uint Age // http://msdn.microsoft.com/ru-ru/library/w86s7x04.aspx
        {
            get
            {
                return age;
            }
            /*protected */
            set
            {
                if (value >= 0 && value <= 100) age = value;
                else age = 18;
            }
        }

        public uint getAge()
        {
            return age;
        }

    }
    class Program
    {
        static void Main(string[] args)
        {
            Human a = new Human();
            Console.WriteLine(a.Age);
            a.Age = 146;
            Console.WriteLine(a.getAge());
        }
    }
}

// 10 глава рихтера!