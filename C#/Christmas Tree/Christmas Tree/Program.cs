using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Christmas_Tree
{
    class Stem
    {
        public int spaceBeforeStem;
        public string stemPart = "###";

        public Stem(int spaceBeforeStem)
        {
            this.spaceBeforeStem = spaceBeforeStem;
        }
        public void PrintBody()
        {
            for (int j = 0; j < 5; j++)
            {
                for (int i = 0; i < spaceBeforeStem; i++)
            {
                Console.Write(' ');
            }
            Console.WriteLine(stemPart);
            }
            
        }
    }

    class Head
    {
        public int simb;
        public int tiers;
        public int leafs;
        public char leaf;
        public Head(int simb, int tiers)
        {
            this.simb = simb;
            this.tiers = tiers;
            this.leaf = '@';
            this.leafs = 1;
        }
        public void PrintHead()
        {
            int space = simb + tiers;
            for (int all = 0; all < tiers;all++ )
            {
               int spaceOfEach = space;
            int leafsOfEach = leafs;
                for (int i = 0; i < simb; i++, spaceOfEach--)
                {
                    for (int j = 0; j < spaceOfEach; j++)
                        Console.Write(" ");
                    for (int k = 0; k < leafsOfEach; k++)
                        Console.Write(leaf);
                    Console.WriteLine();
                    leafsOfEach += 2;
                }
                leafs += 2;
                space -= 1;
            }
        }
    }
    class Program
    {    
        static void Main(string[] args)
        {
            Console.Title = "Christmas Tree";
            //Console.BackgroundColor = ConsoleColor.White;
            Console.Write("Введите высоту яруса : ");
            int s = Convert.ToInt32(Console.ReadLine());
            Console.Write("Введите кол-во ярусов : ");
            int t = Convert.ToInt32(Console.ReadLine());
            Head b = new Head(s, t);
            Stem a=new Stem(s+t-1);
            Console.ForegroundColor = ConsoleColor.DarkGreen;
            b.PrintHead();
            Console.ForegroundColor = ConsoleColor.DarkMagenta;
            a.PrintBody();
        }
    }
}
