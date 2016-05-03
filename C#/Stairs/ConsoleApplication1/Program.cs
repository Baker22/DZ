using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Program
    {
        static int stairs = Convert.ToInt32(Console.ReadLine());
        static int spaceStair = 0;
        static int downSpace =2;
        static void Main(string[] args)
        {
            for (int i = 0; i < stairs;i++ )
            {
                for (int j = 0; j < spaceStair; j++)
                    Console.Write(' ');
                Console.WriteLine("***");
                 for (int t = 0; t < downSpace; t++)
                     Console.Write(' ');
                Console.WriteLine("*");
                    spaceStair += 2;
                    downSpace += 2;
                if(i==stairs-1)
                {
                    for (int t = 0; t < downSpace-2; t++)
                        Console.Write(' ');
                    Console.WriteLine("***");
                }
            }       
        }
    }
}
