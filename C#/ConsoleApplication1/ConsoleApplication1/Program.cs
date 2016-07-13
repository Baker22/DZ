using System;
using System.Threading;

namespace GenericClassExample2
{
    class Box<T> where T : class, new()
    {
        protected T innerObject;

        public Box()
        {
            innerObject = new T();
        }

        public Box(T someObject)
        {
            innerObject = someObject;
        }

        public T InnerObject
        {
            get
            {
                return innerObject;
            }
            set
            {
                innerObject = value;
            }
        }

        public void Print()
        {
            Console.Write(innerObject);
            if (typeof(T).Name.Contains("Box")) Console.Write(",");
            Console.WriteLine(" находится в коробке.");
        }

        public override string ToString()
        {
            return "коробка, внутри которой лежит " + innerObject;
        }
    }

    ////////////////////////////////////////////////////////////////

    class Cat
    {
        public override string ToString()
        {
            return "кошка";
        }
    }

    ////////////////////////////////////////////////////////////////

    abstract class RadioactiveMaterial
    {
        public int RadioactivePower { get; set; }
    }

    class Uranium : RadioactiveMaterial
    {
        public override string ToString()
        {
            return "немного урана";
        }
    }

    ////////////////////////////////////////////////////////////////

    class RadioactiveBox<T> : Box<T> where T : RadioactiveMaterial, new()
    {
        public RadioactiveBox()
        {
            innerObject = new T();
        }

        public override string ToString()
        {
            return base.ToString() + " с радиактивной силой " + InnerObject.RadioactivePower;
        }
    }

    class NuclearReactor : Box<Uranium>
    {
        public NuclearReactor(Uranium u)
        {
            this.InnerObject = u;
        }

        public override string ToString()
        {
            return "большая " + base.ToString() + " - это ядерный реактор!\n";
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            // var a = new Box<int>(); // The type 'int' must be a reference type in order to use it as parameter 'T' in the generic type or method

            var b = new Box<Cat>();
            b.Print();
            Console.WriteLine(b + ".\n");

            Thread.Sleep(2000);

            var c = new Box<Uranium>(new Uranium() { RadioactivePower = 9001 });
            c.Print();
            Console.WriteLine(c + ".\n");

            Thread.Sleep(2000);

            var d = new Box<Box<Uranium>>(new Box<Uranium>(new Uranium()));
            d.Print();
            Console.WriteLine(d + ".\n");

            Thread.Sleep(2000);

            var e = new NuclearReactor(new Uranium());
            Console.WriteLine(e);
        }
    }
}
