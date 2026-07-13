# CS204 — Homeworks

C++ homework assignments from CS204 (Advanced Programming), Spring 2022 and Spring 2023.
Each folder holds the sources plus the original assignment PDF.

| Homework | What it does | Key ideas |
|---|---|---|
| [`homework1 2022`](homework1%202022) | Word-guessing (hangman) game driven by a word list read from file. | File I/O, string manipulation |
| [`homework2 2022`](homework2%202022) | Reads and compares the contents of two files. | Multi-file I/O, parsing |
| [`homework3 2022`](homework3%202022) | Matrix stored as a **2D linked list**, with a menu to display it forwards, in reverse, and more. | Custom linked structures, pointers |
| [`homework4 2022`](homework4%202022) | Bracket/symbol matcher — scans a file and reports unbalanced opening and closing symbols. | Stack-based parsing |
| [`homework5 2022`](homework5%202022) | Two-player card game with a `Deck` / `Card` model, played round by round to a winner. | Classes, composition |
| [`homework6 2022`](homework6%202022) | Two-player territory board game — players own and update cells on a shared `Board`, with move validation. | Class design, encapsulation |
| [`homework1 2023`](homework1%202023) | File parsing with content validation and error reporting. | Robust input handling |

## Building

Each homework is standalone. From inside its folder:

```bash
g++ -std=c++11 -o hw *.cpp
./hw
```

Most of them prompt for an input file name, which is expected in the working directory.

Two take slightly different commands: **`homework6 2022`** `#include`s its `.cpp` files
directly, so build only `main.cpp` (`g++ -std=c++11 -o hw main.cpp`), and
**`homework4 2022`** expects the course-provided `DynStackHW4.h` header alongside it.
