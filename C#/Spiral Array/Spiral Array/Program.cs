using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Spiral_Array
{
    class Program
    {
        static void Main(string[] args)
        {
            int width = 5;
            int height = 5;
            int increment = 1;
            int[,] arr = new int[20, 20];
            arr[height, width] = 0;
            for (int i = 0; i < 100; )
            {
                for (int a = 0; a < increment; a++)
                {
                    i++;
                height--;
                arr[height, width] = i;
                }
                for (int b = 0; b < increment; b++)
                {
                    i++;
                width--;
                arr[height, width] = i;
                }
                increment++;
                for (int c = 0; c < increment; c++)
                {
                    i++;
                height++;
                arr[height, width] = i;
                }
                
                for (int d = 0; d < increment; d++)
                {
                    i++;
                width++;
                arr[height, width] = i;
                }  
                increment++;
            }
            for (int i = 0; i < 10; i++)
            {
                for (int j = 0; j < 10; j++)
                {
                    Console.Write("{0, 4}", arr[i, j]);
                }

                Console.Write("\n");
            }
        }
    }
}
