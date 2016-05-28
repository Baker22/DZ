using System;
using System.Text.RegularExpressions;
public class Palindrom
{
    public static string Reverser(string a)
    {
        char[] arr = a.ToCharArray();
        Array.Reverse(arr);
        return new string(arr);
    }
    public static string Palindromer(string x)
    {
        string y = Reverser(x);
        Console.WriteLine(y);
        if (Equals(x, y))
            return "Палиндром";
        else
            return "Не палиндром";
    }
    public static void Main()
    {
        Console.Title = "Проверка на палиндромность.";
        Console.WriteLine("Введите тестируемую строку");
        string pattern = @"\.+?|\,+?|\ +?|\-+?|\:+?";
        string input = Console.ReadLine();
        string str = input.ToLower();
        str=(Regex.Replace(str, pattern, string.Empty));
        Console.WriteLine(input+" - "+Palindromer(str));
        Console.WriteLine();
    }
}