# Sitecore Internship Technical Assignment

The solutions to three questions given are in the 3 folders.

```
SitecoreAssignment
├── simple_figures        # Solution for first question.
│   ├── main.go           # Implementation of solution in Go.
│   └── main_test.go      # Unit test for the solution.
├── palindrome            # Solution for second question.
│   ├── main.go           # Implementation of solution in Go.
│   └── main_test.go      # Unit test for the solution.
├── minefield             # Solution for second question.
│   ├── bin               # .NET generated folder.
│   ├── obj               # .NET generated folder.
│   ├── minefield.csproj  # .NET project configuration.
│   ├── input.txt         # Sample input that can feed to the program's STDIN.
│   ├── Minefield.cs      # Actual implementation of minefield.
│   └── Program.cs        # The program's main entry point.
```

## How to run the solutions?

For solutions implemented in Go, you need to have Go installed. To test the solutions with sample test cases, go into the folder and run `go test .`

This will run the unit test for the solution, to test the solution with another input, replace or add a test case under `main_test.go`

For the third question (minefield), you need to have .NET installed. There are no unit tests, but I have provided the sample input hence you can run the program using `dotnet run < input.txt`.

This will feed the sample input to the program.
