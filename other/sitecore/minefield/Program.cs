using System;
using System.Collections.Generic;

namespace Minefield
{
  class Program
  {
    static Field[][] ReadInput()
    {
      List<Field[]> minefield = new List<Field[]>();

      string? line = Console.ReadLine();
      string[] dimension = line!.Split(' ');
      int n = Convert.ToInt32(dimension[0]);
      int m = Convert.ToInt32(dimension[1]);

      while (n-- > 0)
      {
        List<Field> fields = new List<Field>();
        line = Console.ReadLine();
        foreach (var c in line!.Split(' '))
        {
          switch (c)
          {
            case "E":
              fields.Add(Field.Empty);
              break;
            case "S":
              throw new Exception("initial minefield can only have 'Empty' or 'Bomb' field");
            case "B":
              fields.Add(Field.Bomb);
              break;
            default:
              throw new Exception("only 'E' or 'B' are accepted as initial field");
          }
        }
        minefield.Add(fields.ToArray());
      }

      return minefield.ToArray();
    }

    static void Main(string[] args)
    {
      Minefield mf = new Minefield(ReadInput());

      try
      {
        mf.Solve();
      }
      catch (Exception e)
      {
        mf.Display();
        Console.ForegroundColor = ConsoleColor.DarkRed;
        Console.WriteLine("\n{0}", e.Message);
        Console.ResetColor();
      }
    }
  }
}