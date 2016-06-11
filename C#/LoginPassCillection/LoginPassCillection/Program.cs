using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LoginPassCollection
{
    public class Pair
    {
        private string login;
        private string password;
        public Pair(string login,string password)
        {
            SetLog(login);
            SetPass(password);
        }
        private void SetLog(string login)
        {
            this.login=login;
        }
        private void SetPass(string password)
        {
            this.password = password;
        }
        public string Login
        {
            get{return login;}
            set
            {
                login = value;
            }
        }
        public string Password 
        { 
            get { return password; }
            set
            {
                password = value;
            }
        }
    }
       public class Collection
    {
           ShowMenu x=new ShowMenu();
            Pair[] arr;
            uint count=0;
            public Collection(uint size)
            {
                arr = new Pair[size];
                x.Show();
            }
            public int this[string log]
        {
            get
            {
                for(int i=0;i<count;i++)
                {
                    if (arr[i].Login == log)
                        return i;
                }
                throw new Exception("no such login");
            }
        }
            
            public override string ToString()
            {
                string res="";
                for (int i = 0; i <count; i++)
                {
                    res = res + "Login: " + arr[i].Login + ".\n" + "Password: " + arr[i].Password + ".\n\n";
                }
                return res;
            }
           public void ShowAll(){Console.WriteLine(this.ToString());} 
           public void AddNewUser(Pair _new)
            {
                arr[count] = _new;
                count++;
            }
           public void DeleteUser(string log)
           {
               Pair[] temp = new Pair[arr.Length];
               for (int i = 0; i < this[log]; i++)
                       temp[i] = arr[i];
               for (int j = this[log]; j < count-1; j++)
                   temp[j] = arr[j + 1];
               arr = temp;
               count--;
           }
           public void Edit(string log)
           {
               int index=this[log];
               Console.WriteLine("Enter a new Login");
               arr[index].Login = (Console.ReadLine());
               Console.WriteLine("Enter a new Password");
               arr[index].Password = (Console.ReadLine());
               Console.WriteLine("\n");
           }
           public class ShowMenu
           {
               public void Show()
               {
                   Console.WriteLine("      MENU\n ");
               Console.WriteLine(" For open all collection Enter \"ShowAll()\"");
               Console.WriteLine(" For add new user Enter \"AddNewUser(Pair _new)\"");
               Console.WriteLine(" For delete user by login Enter \"DeleteUser(string log)\"");
               Console.WriteLine(" For edit user by login Enter \"Edit(string log)\"");

               }

           }
        }
  
    
    public class Program
    {
        static void Main(string[] args)
        {
            Collection col = new Collection(30);
            Pair a = new Pair("Alex","Baker22");
            Pair b=new Pair("timur","batrutdinov");
            Pair c=new Pair("sergey","2222");
            Pair d=new Pair("dima","ursu");
            col.AddNewUser(a);
            col.AddNewUser(b);
            col.AddNewUser(c);
            col.AddNewUser(d);
            col.ShowAll();
            col.DeleteUser("timur");
            col.ShowAll();
            col.Edit("sergey");
            col.ShowAll();
        }
    }
}
