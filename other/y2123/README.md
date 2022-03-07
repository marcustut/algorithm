# Y2123 Take Home Test

The solutions are implemented in both **Go** and **TypeScript**.

```
Y2123
├── go
│   ├── main.go           # Implementation of solution in Go.
│   └── main_test.go      # Unit test for the solution.
├── typescript
│   ├── .gitignore        # Git ignored files.
│   ├── main.ts           # Implementation of solution in TypeScript.
│   ├── main_test.ts      # Unit test for the solution.
│   ├── package.json      # Project configuration file.
│   ├── tsconfig.json     # TypeScript configuration file.
│   └── yarn.lock         # lock file for yarn.
```

## How to run the solutions?

### Go

For solutions implemented in Go, you need to have Go installed. To test the solutions with sample test cases, go into the folder and run `go test .`

This will run the unit test for the solution, to test the solution with another input, replace or add a test case under `main_test.go`

### TypeScript

For solutions implemented in TypeScript, you'll need to have `node` and `yarn` installed. First run `yarn` in the folder, this will install all the project dependencies.

After that, run `yarn test` to execute the unit tests. The testcases are defined in `main_test.ts`
