using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Romanian_numbers
{
    class Program
    {
        static string Converter(string num)
        {
            if (num == "0")
                return "Ноль";
            string res = "";
            int full = Convert.ToInt32(num);
            int counter = 0;
            while (full > 0)
            {
                if (full == 1000000)
                    return "Один миллион";
                while (full >= 100000)
                {
                    full -= 100000;
                    counter++;
                }
                if (counter >= 9)
                    res = res + "Девятьсот ";
                else if (counter >= 8)
                    res = res + "Восемьсот ";
                else if (counter >= 7)
                    res = res + "Семьсот ";
                else if (counter >= 6)
                    res = res + "Шестьсот ";
                else if (counter >= 5)
                    res = res + "Пятьсот ";
                else if (counter >= 4)
                    res = res + "Четыреста ";
                else if (counter >= 3)
                    res = res + "Триста ";
                else if (counter >= 2)
                    res = res + "Двести ";
                else if (counter >= 1)
                    res = res + "Сто "; 
                counter = 0;
                if(full>=20000||full<11000)
                {
                    while (full >= 10000)
                {
                    full -= 10000;
                    counter++;
                }
                    if (counter == 9)
                    res = res + "Девяносто ";
                else if (counter == 8)
                    res = res + "Восемьдесят ";
                else if (counter == 7)
                    res = res + "Семьдесят ";
                else if (counter == 6)
                    res = res + "Шестьдесят ";
                else if (counter == 5)
                    res = res + "Пятьдесят ";
                else if (counter == 4)
                    res = res + "Сорок ";
                else if (counter == 3)
                    res = res + "Тридцать ";
                else if (counter == 2)
                    res = res + "Двадцать ";
                else if (counter == 1)
                    res = res + "Десять ";
                    if (full < 1000)
                        res = res + "Тысяч ";
                }
                counter = 0;
                if(full<20000&&full>=11000)
                {
                    while (full >= 1000)
                {
                    full -= 1000;
                    counter++;
                }
                if (counter == 10&&full<1000)
                    res = res + "Десять Тысяч ";
                else if (counter == 11)
                    res = res + "Одинадцать Тысяч ";
                else if (counter == 12)
                    res = res + "Двенадцать Тысяч ";
                else if (counter == 13)
                    res = res + "Тринадцать Тысяч ";
                else if (counter == 14)
                    res = res + "Четырнадцать Тысяч ";
                else if (counter == 15)
                    res = res + "Пятнадцать Тысяч ";
                else if (counter == 16)
                    res = res + "Шестнадцать Тысяч ";
                else if (counter == 17)
                    res = res + "Семнадцать Тысяч ";
                else if (counter == 18)
                    res = res + "Восемнадцать Тысяч ";
                else if (counter == 19)
                    res = res + "Девятнадцать Тысяч ";
                }
                counter = 0;
                if(full<10000&&full>=1000)
                    while(full>=1000)
                    {
                        full -= 1000;
                        counter++;
                    }
                    if (counter == 1)
                        res = res + "Одна Тысяча ";
                    else if (counter == 2)
                        res = res + "Две Тысячи ";
                    else if (counter == 3)
                        res = res + "Три Тысячи ";
                    else if (counter == 4)
                        res = res + "Четыре Тысячи ";
                    else if (counter == 5)
                        res = res + "Пять Тысяч ";
                    else if (counter == 6)
                        res = res + "Шесть Тысяч ";
                    else if (counter == 7)
                        res = res + "Семь Тысяч ";
                    else if (counter == 8)
                        res = res + "Восемь Тысяч ";
                    else if (counter == 9)
                        res = res + "Девять Тысяч ";
                counter = 0;
                while (full >= 100)
                {
                    full -= 100;
                    counter++;
                }
                if (counter >= 9)
                    res = res + "Девятьсот ";
                else if (counter >= 8)
                    res = res + "Восемьсот ";
                else if (counter >= 7)
                    res = res + "Семьсот ";
                else if (counter >= 6)
                    res = res + "Шестьсот ";
                else if (counter >= 5)
                    res = res + "Пятьсот ";
                else if (counter >= 4)
                    res = res + "Четыреста ";
                else if (counter >= 3)
                    res = res + "Триста ";
                else if (counter >= 2)
                    res = res + "Двести ";
                else if (counter >= 1)
                    res = res + "Сто ";
                counter = 0;
                while (full >= 10)
                {
                    full -= 10;
                    counter++;
                }
                if (counter == 9)
                    res = res + "Девяносто ";
                else if (counter == 8)
                    res = res + "Восемьдесят ";
                else if (counter == 7)
                    res = res + "Семьдесят ";
                else if (counter == 6)
                    res = res + "Шестьдесят ";
                else if (counter == 5)
                    res = res + "Пятьдесят ";
                else if (counter == 4)
                    res = res + "Сорок ";
                else if (counter == 3)
                    res = res + "Тридцать ";
                else if (counter == 2)
                    res = res + "Двадцать ";
                if (counter == 1&&full==0)
                    res = res + "Десять ";
                else if (counter == 1&&full==1)
                    res = res + "Одинадцать ";
                else if (counter == 1 && full == 2)
                    res = res + "Двенадцать ";
                else if (counter == 1 && full == 3)
                    res = res + "Тринадцать ";
                else if (counter == 1 && full == 4)
                    res = res + "Четырнадцать ";
                else if (counter == 1 && full == 5)
                    res = res + "Пятнадцать ";
                else if (counter == 1 && full == 6)
                    res = res + "Шестнадцать ";
                else if (counter == 1 && full == 7)
                    res = res + "Семнадцать ";
                else if (counter == 1 && full == 8)
                    res = res + "Восемнадцать ";
                else if (counter == 1 && full == 9)
                    res = res + "Девятнадцать ";
                if (full == 1)
                    res = res + "Один";
                if (full == 2)
                    res = res + "Два";
                if (full == 3)
                    res = res + "Три";
                if (full == 4)
                    res = res + "Четыре";
                if (full == 5)
                    res = res + "Пять";
                if (full == 6)
                    res = res + "Шесть";
                if (full == 7)
                    res = res + "Семь";
                if (full == 8)
                    res = res + "Восемь";
                if (full == 9)
                    res = res + "Девять";
                full = 0;
            }

            return res;
        }
        static void Main(string[] args)
        {
            Console.Title = "Million by words";
            while(true)
            {
            Console.WriteLine("Enter a number");
            string numb = Console.ReadLine();
            Console.WriteLine(Converter(numb));
            }
            
        }
    }
}
