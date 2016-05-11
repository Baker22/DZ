using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Logical_Task
{
    class Program
    {
        static string Analizer(string num)
        {
            int index = Convert.ToInt32(num);
            string res="1";
            for (int i = 0; i < index; i++)
            {
                char[] arr;
                arr = res.ToCharArray();
                Console.WriteLine(arr);
                int a = 0;
                char temp = arr[a];
                string _new = "";
                int counter=0;
                for (int j = 0; j < res.Length; j++)
                {
                    if (temp == arr[j])
                    {
                        counter++;
                    }
                    else
                    {
                        
                        _new = _new + Convert.ToString(counter);
                        _new = _new+temp;
                        temp = arr[j];
                        counter = 0;
                        j--;
                    }
                    if (counter > 0 && j == res.Length-1)
                    {
                        _new = _new + Convert.ToString(counter);
                        _new = _new + arr[j];
                        a++;
                    }
   
                }
                
                res = _new;
            }    
            return res;
        }
        static void Main(string[] args)
        {
            Console.Title = "Logical Task";
            Console.WriteLine("Введите номер последовательности");
            string numb = Console.ReadLine();
            Console.WriteLine(Analizer(numb));
        }
    }
}
