using System;
using System.Threading;

namespace ConsoleApplication1
{

    class Program
    {
        static void Main(string[] args)
        {
            while (true)
            {
                if (Console.KeyAvailable == true)
                {
                    ConsoleKeyInfo k = Console.ReadKey(true);
                    Console.Write(k.KeyChar);
                }
                else
                {
                    Console.Write("_");
                }
                Thread.Sleep(15);
            }
        }
    }
}
