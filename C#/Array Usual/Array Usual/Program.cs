using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ArrayUsual
{
    class Program
    {
        static void Main(string[] args)
        {
            int[,] Array = new int[5, 6];
            int counter = 1;
            for (int a = 0; a < 5; a++)
            {
                for (int b = 0; b < 6; b++)
                {
                    Array[a, b] = counter;
                    counter++;
                    Console.Write("{0,4}", Array[a, b]);
                }
                Console.WriteLine();
            }
            Console.WriteLine();  
        }
    }
}
