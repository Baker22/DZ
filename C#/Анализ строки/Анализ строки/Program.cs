using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Text.RegularExpressions;

namespace Анализ_строки
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Title = "Анализ строки";
            Console.WriteLine("Введите анализируемую строку");
            string input = Console.ReadLine();
            int all_count = input.Length;
            int glas_count = Regex.Matches(input, @"[weyuioaёуеыаоэяию]", RegexOptions.IgnoreCase).Count;
            int sogl_count = Regex.Matches(input, @"[qrtpsdfghjklzxcvbnmйцкнгшщзхъфвпрлджчсмтьб]", RegexOptions.IgnoreCase).Count;
            int digits_count = Regex.Matches(input, @"\d", RegexOptions.IgnoreCase).Count;
            int stoper_count = Regex.Matches(input, @"[.,:;!?\/]", RegexOptions.IgnoreCase).Count;
            Console.WriteLine("Всего символов - {0}\nГласных - {1}\nСогласных - {2}\nЦифр - {3}\nЗнаков препинания - {4}", all_count, glas_count, sogl_count, digits_count, stoper_count);
        }
    }
}
