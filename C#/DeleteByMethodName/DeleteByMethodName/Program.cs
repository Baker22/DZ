using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Reflection;
using System.Collections;

namespace DeleteByMethodName
{
    
    public class Publisher
    {
        public delegate void Some();
        public event Some Virtual;
        public void GotEvent()
        {
            if (Virtual != null)
                Virtual();
        }
        public void Deleter(string name)
        {
            int lenght=this.Virtual.GetInvocationList().Length;
                for(int i=0;i<lenght-1;i++)
                {
                    Some abc = (Some)Virtual.GetInvocationList()[i];
                    if(abc.GetMethodInfo().Name==name)
                        this.Virtual -=abc;
                }
            
        }
    }

    public class Program
    {
        static public void SayHello()
        {
            Console.WriteLine("Hello");
        }
        static public void SayHiHi()
        {
            Console.WriteLine("HI Hi");
        }
        static public void SayByeBye()
        {
            Console.WriteLine("Bye Bye");
        }
        static void Main(string[] args)
        {
            Publisher pub = new Publisher();
            pub.Virtual += SayHello;
            pub.Virtual += SayHiHi;
            pub.Virtual += SayByeBye;
            pub.GotEvent();
            pub.Deleter("SayHello");
            pub.GotEvent();
        }
    }
}
