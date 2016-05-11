using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Romanian_numbers
{
    class Program
    {
        static string Converter(int num)
        {
            string res="";
            int full=num;
            int counter=0;
            while (full > 0)
            {
                while(full>=1000)
                {
                    full -= 1000;
                    res = res + "M";
                }

                counter=0;
                while(full>=100)
                {
                    full -= 100;
                    counter++;
                }
                    if (counter == 9)
                        res = res + "CM";
                    else if (counter == 8)
                        res = res + "DCCC";
                    else if (counter == 7)
                        res = res + "DCC";
                    else if (counter == 6)
                        res = res + "DC";
                    else if (counter == 5)
                        res = res + "D";
                    else if (counter == 4)
                        res = res + "CD";
                    else 
                        for (int a = 0; a < counter; a++)
                        {
                            res = res + "C";
                        }
                    counter = 0;
                while(full>=10)
                {
                    full -= 10;
                    counter++;
                }
                if (counter == 9)
                    res = res + "XC";
                else if (counter == 8)
                    res = res + "LXXX";
                else if (counter == 7)
                    res = res + "LXX";
                else if (counter == 6)
                    res = res + "LX";
                else if (counter == 5)
                    res = res + "L";
                else if (counter == 4)
                    res = res + "XL";
                else
                    for (int a = 0; a < counter; a++)
                    {
                        res = res + "X";
                    }
                counter = full;
                if (counter == 9)
                    res = res + "IX";
                else if (counter == 8)
                    res = res + "VIII";
                else if (counter == 7)
                    res = res + "VII";
                else if (counter == 6)
                    res = res + "VI";
                else if (counter == 5)
                    res = res + "V";
                else if (counter == 4)
                    res = res + "IV";
                else
                    for (int a = 0; a < counter; a++)
                    {
                        res = res + "I";
                        full--;
                    }
                full = 0;
            }

            return res;
        }
        static void Main(string[] args)
        {
            Console.Title = "Romanian Numbers";
            string[] rom_arr = new string[4001];
            for (int i = 1; i <= 4000; i++)
            {
                rom_arr[i] = Converter(i);
                Console.WriteLine(rom_arr[i]);
            }
        }
    }
}
