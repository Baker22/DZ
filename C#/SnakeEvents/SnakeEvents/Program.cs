using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;

namespace SnakeEvents
{
    public class Snake
    {
         string body;
        public Snake()
        {
            this.body = "snake";
        }
        public string Body
        {
            get { return body;}
        }

        public delegate void Some();
        public event Some EatApple;
        public event Some HitWall;
        public event Some EatTail;
  
        public void EatSelf()
        {
            Console.Write(Body+" EatSelf- ");
            if (EatTail != null)
                EatTail();
        }
        public void Eat()
        {
            Console.Write(Body + " EatApple- ");
            if (EatApple != null)
                EatApple();
        }
        public void Hit()
        {
            Console.Write(Body + " Hit Wall- ");
            if (HitWall != null)
                HitWall();
        }
    }
   
    class Program
    {
        static public void Method2()
        {
            Console.WriteLine("Lost a life");
        }
        static public void Method1()
        {
            Console.WriteLine("Groun Up");
        }
        static public void game()
            {
                
            }
        static void Main(string[] args)
        {
            Snake piton = new Snake();
            piton.EatApple += Method1;
            piton.EatTail += Method2;
            piton.HitWall += Method2;
            while(true)
                {
                    Thread.Sleep(3000);
                    Random r=new Random();
                    int rand=r.Next(1, 4);

                    switch (rand)
                    {
                        case 1:
                            piton.Eat();
                            break;
                        case 2:
                            piton.Hit();
                            break;
                        case 3:
                            piton.EatSelf();
                            break;
                        default:
                            break;
                    }
                }

        }
    }
}
