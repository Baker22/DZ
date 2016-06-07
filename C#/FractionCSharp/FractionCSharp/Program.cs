using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FractionCSharp
{
    class Fraction
    {
        uint chislitel,znamenatel;
        public Fraction(uint chislitel,uint znamenatel)
        {
            SetChis(chislitel);
            SetZnam(znamenatel);
        }
        public void SetChis(uint chislitel) { this.chislitel = chislitel; }
        public void SetZnam(uint znamenatel) { this.znamenatel = znamenatel; }
        public uint GetChis() { return chislitel;}
        public uint GetZnam() { return znamenatel;}
        public static uint Nod(uint a,uint b)
        {
            if (b == 0)
                return a;
            return Nod(b, a % b);
        }
        public static Fraction Sokr(Fraction f)
        {
            uint nod = Nod(f.chislitel, f.znamenatel);
                f.chislitel/=nod;
            f.znamenatel/=nod;
            return f;
        }
        public static Fraction operator *(Fraction f,uint a)
        {
            Fraction z = new Fraction(f.GetChis() * a, f.GetZnam());
            if (z) return z;
            else  Sokr(z);
            return z;
        }
        public static Fraction operator *(uint a,Fraction f)
        {
            return f * a;
        }
        public static Boolean operator true(Fraction f)
        {
            return (f.chislitel < f.znamenatel);
        }
        public static Boolean operator false(Fraction f)
        {
            return(f.chislitel > f.znamenatel);
        }
        public static Fraction operator +(Fraction a,Fraction b)
        {
            Fraction f=new Fraction(a.GetChis() * b.GetZnam() + b.GetChis() * a.GetZnam(), a.GetZnam() * b.GetZnam());
            if (f)  return f;
            else Sokr(f);
            return f;
        }
        public static Fraction operator +(Fraction a, double d)
        {
            uint znam = 1;
            while (d>(uint)d)
            {
                d *= 10;
                znam *= 10;
            }

            Fraction f = new Fraction((uint)d, znam);
            return a + f;
        }
 
    }
    class Program
    {
        static void Main(string[] args)
        {
            Fraction f=new Fraction(5,4);
            Console.WriteLine(ToString(f));
            if(f)
            Console.WriteLine("yes");
            uint a = 10;
            Fraction f1 = f * a;
            Console.WriteLine(ToString(f1));
            Fraction f2 = a * f;
            Console.WriteLine(ToString(f2));
            double d = 1.5;
            Fraction f3 = f+d;
            Console.WriteLine(ToString(f3));
            Fraction f4 = new Fraction(15, 10);
            Fraction f5 = f4 + f;
            Console.WriteLine(ToString(f5));
        }

        private static string ToString(Fraction f)
        {
            return("chislitel="+f.GetChis().ToString()+"znamenatel="+f.GetZnam().ToString());
        }
    }
}
