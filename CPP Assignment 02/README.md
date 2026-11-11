# Assignment 2 – CO2 C++ Source Codes

Each question has its own folder. Compile a file with:

```bash
g++ -std=c++17 -Wall -Wextra filename.cpp -o program
```

Run on Windows:
```bash
program.exe
```

Run on Linux/macOS:
```bash
./program
```

## Folders
- Q1: Call by value, reference, pointer; output prediction; completed TODO.
- Q2: Return by reference, index and pointer alternatives. `invalidReference()` is deliberately unsafe and is included only to demonstrate the compiler warning; do not call it.
- Q3: Default arguments and function overloading.
- Q4: Savings account and circular transaction history.
- Q5: Static members, Token prediction and BusTicket.
- Q6: Friend functions, member-function alternative and timing benchmark.
- Q7: Circular-buffer redesign.

For Q6 timing, compile and run separately:
```bash
g++ -std=c++17 -O0 -Wall -Wextra inline_benchmark.cpp -o bench_O0
g++ -std=c++17 -O2 -Wall -Wextra inline_benchmark.cpp -o bench_O2
```
Record your own measured results. Timing values depend on the computer and compiler.

These are source files only. Add your own execution screenshots and GitHub details as required by the assignment.
