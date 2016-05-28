using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Буквенный_микс
{
    class Program
    {
        public static int size = 0;
        public static string[] arr=new string[size];
        public static void AddToStrArr(string str)
        {
            if (!arr.Contains(str))
            {
                string[]temp=new string[size+1];
                for (int i = 0; i < size; i++)
                    temp[i]=arr[i];
                temp[size]=str;
                arr = temp;
                size++;
            }
                
        }
        public static void Nesu_Bred(char[] x,int size)
        {
            for (int i = 0; i < size; i++)
            {
                char temp = x[size - 1];
                for(int j=size-1;j>0;j--)
                {
                    x[j] = x[j - 1];
                }
                x[0] = temp;
                if (i < size - 1)
                {
                    string y=new string(x);
                    AddToStrArr(y);
                }
                    
                if (size > 0)
                    Nesu_Bred(x, size - 1);
            }
        }
        static void Main(string[] args)
        {
            Console.Title = "Все возможные перестановки букв";
               string input=Console.ReadLine();
               Nesu_Bred(input.ToCharArray(),input.Length);
               for (int i = 0; i < size; i++)
               {
                   Console.WriteLine("{0}) "+arr[i],i+1);
               }
        }
    }
}
