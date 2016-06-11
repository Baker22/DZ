using System;
using System.Text.RegularExpressions;

abstract class Device 
{
    private int price;
    private int warranty;
    private string category;
    private string producer;
    private string dateOfIssue;
    private string model;

     public Device(int price,int warranty,string category, string producer, string dateOfIssue, string model) 
    {
        this.price = price;
        this.warranty=warranty;
        this.category=category;
        this.producer = producer;
        this.dateOfIssue=dateOfIssue;
        this.model=model;
    }
    public int Price
    {
        get {return price;}
        set
        {
            if (value > 0) price = value;
        }
    }
    public int Warranty
    {
        get {return warranty;}
        set
        {
            if (value > 0) warranty = value;
        }
    }
    public string Producer
    {
        get {return producer;}
        set
        {
            if(value!=null)
            producer = value;
        }
    }
    public string Category
    {
        get {return category;}
        set
        {
            if (value != null)
                category = value;
        }
    }
    public string DateOfIssue
    {
        get { return dateOfIssue; }
        set
        {
            if (value != null)
                dateOfIssue = value;
        }
    }
    public string Model
    {
        get { return model; }
        set
        {
            if (value != null)
                model = value;
        }
    }
    public override String ToString()
{
    return "Price: " + price + "\n warranty: $" + warranty+"\n Category: "+category+"\n Producer: "+producer+"\n Date of issue: "+dateOfIssue+"\n Model: "+model;
}
}


class Laptop : Device
{
    public Laptop(int price, int warranty, string category, string producer, string dateOfIssue, string model) : base(price,warranty,category, producer, dateOfIssue, model) { }
}
class Tablet : Device
{
    public Tablet(int price, int warranty, string category, string producer, string dateOfIssue, string model) : base(price, warranty, category, producer, dateOfIssue, model) { }
}
class Phone : Device
{
    public Phone(int price, int warranty, string category, string producer, string dateOfIssue, string model) : base(price, warranty, category, producer, dateOfIssue, model) { }
}
class Charger : Device
{
    public Charger(int price, int warranty, string category, string producer, string dateOfIssue, string model) : base(price, warranty, category, producer, dateOfIssue, model) { }
}
class Case : Device
{
    public Case(int price, int warranty, string category, string producer, string dateOfIssue, string model) : base(price, warranty, category, producer, dateOfIssue, model) { }
}





//////////////////////////////////////////////////////////////////////////////////////

class Store
{
    private Device[] devices;

    uint devicesSize = 0;
   
public Store(int sizeOfStore)
{
    devices = new Device[sizeOfStore];
 
}
    public void AddDevice(Device _new)
{
    devices[devicesSize] = _new;
    devicesSize++;
}
  public void SearchByPrice(int min,int max)
{
    for (int i = 0; i < devicesSize;i++ )
    {
        if (devices[i].Price > min && devices[i].Price < max)
            Console.WriteLine(devices[i].ToString());
    }
}
    public void SearchByModel(string mod)
  {
      Regex reg = new Regex(mod);
        for(int i=0;i<devicesSize;i++)
        {
            Match mat = reg.Match(devices[i].Model);
                if(mat.Success)
                Console.WriteLine(devices[i].ToString());
        }
  }

public Device this[uint index]
{
    get
    {
        if (index >= devices.Length)
        {
            throw new IndexOutOfRangeException();
        }
        else
        {
            return devices[index];
        }
    }
    set
    {
        devices[index] = value as Device;
    }
}
public Device this[string date]
{
    get
    {
        for (int i = 0; i < devicesSize; i++)
        {
            if (devices[i].DateOfIssue == date)
                return devices[i];  
        }
            return null;
    }
}

}

class Program
{
    static void Main(string[] args)
    {
        Store s = new Store(30);
        Device a = new Laptop(1500, 2, "Laptops", "Toshiba", "2016", "The best");//(price,warranty,category, producer, dateOfIssue, model)
        Device b = new Tablet(1000, 1, "Tablets", "Samsung", "2016", "The thinkest");
        s.AddDevice(a);
        s.SearchByPrice(1000, 1600);
        s.SearchByModel("The best");
        Console.WriteLine(s["2016"]);
        /*s[0] = new Laptop("Samsung", 5200);
        s[1] = new Laptop("Asus", 4700);
        s[2] = new Laptop("Toshiba", 4300);

        try
        {
            for (uint i = 0; i < s.Length; i++)
            {
                Console.WriteLine(s[i]);
            }
        }
        catch (NullReferenceException exception)
        {
            Console.WriteLine(exception.Message);
        }
    }*/
    }
}