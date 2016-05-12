using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ball_Inside
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = 21;
            int[, ,] arr = new int[n, n, n];

            for (int k = 0; k < n; k++)
            {
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (Math.Sqrt((k - n / 2) * (k - n / 2) + (i - n / 2) * (i - n / 2) + (j - n / 2) * (j - n / 2)) < n / 2)
                            arr[k, i, j] = 1;
                    }
                }
            }

            for (int k = 0; k < n; k++)
            {
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        Console.Write(arr[k, i, j]);
                    }
                    Console.WriteLine();
                }
                Console.WriteLine();
            }
            Console.WriteLine();
        }
    }
}
