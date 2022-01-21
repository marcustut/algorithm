using System;
using System.Collections;

namespace Minefield
{
  public enum Field { Bomb, Empty, Safe }

  public class Minefield
  {
    private Field[][] minefield;

    public Minefield(Field[][] minefield) { this.minefield = minefield; }

    public void Display()
    {
      foreach (var fields in minefield)
      {
        foreach (var field in fields)
        {
          char symbol = 'E';
          switch (field)
          {
            case Field.Safe:
              Console.ForegroundColor = ConsoleColor.Green;
              symbol = 'S';
              break;
            case Field.Bomb:
              Console.ForegroundColor = ConsoleColor.Red;
              symbol = 'B';
              break;
          }
          Console.Write("{0} ", symbol);
          Console.ResetColor();
        }
        Console.Write("\n");
      }
    }

    public void Solve()
    {
      for (int i = 0; i < minefield.Length; i++)
      {
        bool found = false;
        for (int j = 0; j < minefield[i].Length; j++)
        {
          // skip bomb/safe field or when found
          if (found || minefield[i][j] == Field.Bomb || minefield[i][j] == Field.Safe) continue;

          // find first line
          if (i == 0)
            if ((j - 1 > 0 && minefield[i + 1][j - 1] == Field.Empty) || (j + 1 < minefield.Length && minefield[i + 1][j + 1] == Field.Empty) || (minefield[i + 1][j] == Field.Empty))
            {
              minefield[i][j] = Field.Safe;
              found = true;
            }

          // all next lines
          if (CheckAdjacent(new Tuple<int, int>(i, j), minefield))
          {
            minefield[i][j] = Field.Safe;
            found = true;
            Console.WriteLine("Step {0}:", i + 1);
            Display();
            Console.WriteLine();
          }
        }

        // unable to find safe path
        if (!found)
          throw new Exception("invalid minefield (no safe path)");
      }
    }

    private bool CheckAdjacent(Tuple<int, int> coord, Field[][] minefield)
    {
      var (r, c) = coord;
      for (int i = r - 1; i <= r + 1; i++)
      {
        // if i is out of bounds
        if (i < 0 || i >= minefield.Length) continue;

        for (int j = c - 1; j <= c + 1; j++)
        {
          // if j is out of bounds
          if (j < 0 || j >= minefield[i].Length) continue;

          if (minefield[i][j] == Field.Safe) return true;
        }
      }
      return false;
    }
  }
}