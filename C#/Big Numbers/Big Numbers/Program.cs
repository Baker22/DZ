using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Big_Numbers
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Title = "Big Numbers";
            Console.Write("Введите число : ");
            
            string[] one = { "   1   ", "  11   ", " 1 1   ", "   1   ", "   1   ", "   1   ", "   1   ", "  111  " };
            string[] two = { "  222  ", " 2   2 ", " 2   2 ", "     2 ", "    2  ", "   2   ", "  2    ", " 22222 " };
            string[] three = { "  333  ", " 3   3 ", "     3 ", "    33 ", "     3 ", "     3 ", " 3   3 ", "  333  " };
            string[] four = { " 4   4 ", " 4   4 ", " 4   4 ", "  4444 ", "     4 ", "     4 ", "     4 ", "     4 " };
            string[] five = { " 55555 ", " 5     ", " 5     ", " 5555  ", "     5 ", "     5 ", "     5 ", " 5555  " };
            string[] six = { "  666  ", " 6   6 ", " 6     ", " 6666  ", " 6   6 ", " 6   6 ", " 6   6 ", "  666  " };
            string[] seven = { " 77777 ", "     7 ", "    7  ", "   7   ", "   7   ", "   7   ", "   7   ", "   7   " };
            string[] eight = { "  888  ", " 8   8 ", " 8   8 ", "  888  ", " 8   8 ", " 8   8 ", " 8   8 ", "  888  " };
            string[] nine  = { "  999  ", " 9   9 ", " 9   9 ", "  9999 ", "     9 ", "     9 ", " 9   9 ", "  999  " };
            string[] zero = { "  000  ", " 0   0 ", " 0   0 ", " 0   0 ", " 0   0 ", " 0   0 ", " 0   0 ", "  000  " };
            string num = Console.ReadLine();
            int quant = num.Count();
            Console.WriteLine();
            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < quant; j++)
                {
                    switch (num.ElementAt(j))
                    {
                        case '1':
                            Console.Write(one[i]);
                            break;
                        case '2':
                            Console.Write(two[i]);
                            break;
                        case '3':
                            Console.Write(three[i]);
                            break;
                        case '4':
                            Console.Write(four[i]);
                            break;
                        case '5':
                            Console.Write(five[i]);
                            break;
                        case '6':
                            Console.Write(six[i]);
                            break;
                        case '7':
                            Console.Write(seven[i]);
                            break;
                        case '8':
                            Console.Write(eight[i]);
                            break;
                        case '9':
                            Console.Write(nine[i]);
                            break;
                        case '0':
                            Console.Write(zero[i]);
                            break;
                        default:
                            break;
 
                    }
                }
                Console.WriteLine();
            }
            Console.WriteLine();
        }
         
    }
}
