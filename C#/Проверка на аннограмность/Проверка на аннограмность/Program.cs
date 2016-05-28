using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Text.RegularExpressions;

namespace Проверка_на_анаграммность
{
    class Program
    {
        public static string Anagrammer(string str_1,string str_2)
        {
            string pattern = @"\.+?|\,+?|\ +?|\-+?|\:+?|\!+?";
            str_1=(Regex.Replace(str_1,pattern,string.Empty));
            str_2=(Regex.Replace(str_2,pattern,string.Empty));
            char[] a = ((str_1.ToLower()).ToCharArray());
            char[] b = ((str_2.ToLower()).ToCharArray());
            Array.Sort(a);
            Array.Sort(b);
            string x =new string (a);
            string y =new string (b);
            if (Equals(x, y))
                return "Анаграмма";
            else
                return "Не анаграмма";
        }
        static void Main(string[] args)
        {
            Console.Title = "Проверка на анаграммность.";
            
            Console.WriteLine("Введите первую строку");
            string input_1 = Console.ReadLine();
            Console.WriteLine("Введите вторую строку");
            string input_2 = Console.ReadLine();
            Console.WriteLine(input_1 + " и " + input_2 + " - " + Anagrammer(input_1, input_2));
        }
    }
}
