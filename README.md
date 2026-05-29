# 🎯 Guess The Name

<div align="center">

![C++](https://img.shields.io/badge/C++-17-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![Platform](https://img.shields.io/badge/Platform-Linux%20%7C%20Windows%20%7C%20macOS-lightgrey?style=for-the-badge)
![License](https://img.shields.io/badge/License-MIT-green?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Complete-brightgreen?style=for-the-badge)

**An interactive terminal-based name guessing game built with modern C++.**  
The program uses a character grid system, frequency analysis, and multithreading to predict a user's name — letter by letter.

</div>

---

## 📌 Overview

**Guess The Name** is a terminal game where the user interacts with an alphabetical character grid. By selecting columns and rows that correspond to each letter of their name, the program collects input, analyzes character frequencies, and reconstructs the name through a guessing algorithm.

This project demonstrates core **C++ programming concepts** including:
- STL containers (`vector`, `set`)
- Multi-threading with `std::thread` and `std::chrono`
- Input validation and error handling
- Frequency analysis algorithm
- Modular function design

---

## 🛠️ Features

| Feature | Description |
|---|---|
| 🔤 **Character Grid** | Dynamically generated 6×5 uppercase or lowercase alphabet grid |
| 🎮 **Interactive Input** | Step-by-step column and row selection for each letter |
| 🧠 **Frequency Analysis** | Algorithm finds the most frequent character across selected positions |
| ⏳ **Loading Animation** | Multithreaded animated spinner using `std::this_thread::sleep_for` |
| ✅ **Input Validation** | Robust `getValidInput()` loop with `cin.fail()` guard and range checking |
| 🔡 **Case Support** | Player chooses uppercase (A–Z) or lowercase (a–z) mode at start |
| 🖥️ **Clean Terminal UI** | Bordered welcome message via `printMessageWithAsterisks()` |

---

## 🧠 How The Algorithm Works

```
User selects columns → Program maps column selections to grid characters
                     ↓
User selects rows from filtered grid → Characters added to per-letter arrays
                     ↓
Frequency Analysis: most common character per letter position = guessed letter
                     ↓
                 Guessed Name Output
```

Each letter of the name has its own `vector<char>` (stored in `nameArrays`). The `guessName()` function sorts each vector and finds the character with the highest frequency — that becomes the guessed letter.

---

## 📁 Project Structure

```
Guess-The-Name/
├── guess_the_name.cpp      # Main source file (199 lines)
└── README.md               # Project documentation
```

### Key Functions

| Function | Responsibility |
|---|---|
| `main()` | Game loop — orchestrates all steps |
| `createGrid()` | Builds the 6×5 character grid from a start letter |
| `displayGrid()` | Renders the grid to terminal |
| `getValidInput()` | Validated integer input with range check and error recovery |
| `buildNameArrays()` | Collects characters from selected columns for each name letter |
| `getSelectedGrid()` | Filters grid to only show unique selected columns |
| `guessName()` | Frequency analysis — returns the most common char per position |
| `showLoadingMessage()` | Animated spinner using `std::thread` + `chrono` |
| `printMessageWithAsterisks()` | Formats bordered welcome banner |

---

## 🚀 How to Run

### Prerequisites
- A C++17-compatible compiler (g++, clang++, MSVC)

### Compile

```bash
g++ -std=c++17 -o guess_the_name guess_the_name.cpp -lpthread
```

### Run

```bash
./guess_the_name
```

> On Windows (MinGW):
> ```bash
> g++ -std=c++17 -o guess_the_name.exe guess_the_name.cpp
> guess_the_name.exe
> ```

---

## 🎮 How to Play

**Step 1** — Choose letter case: `1` for Uppercase (A–Z), `2` for Lowercase (a–z)

**Step 2** — A 6×5 character grid is displayed:
```
A B C D E
F G H I J
K L M N O
P Q R S T
U V W X Y
Z
```

**Step 3** — Enter the number of characters in your name (e.g. `5` for "Ahsan")

**Step 4** — For each letter, select the **column** (1–5) where that letter appears in the grid

**Step 5** — A filtered grid is shown based on your column selections. Select the **row** (1–6) for each letter

**Step 6** — The program analyzes your selections and outputs the guessed name 🎉

---

## 📷 Example Output

```
******************************
* Welcome to the Name Guessing Game! *
******************************

Searching Done!

Do you want to play with (1) Uppercase letters or (2) Lowercase letters? 1

Choose your columns here!
A B C D E
F G H I J
K L M N O
P Q R S T
U V W X Y
Z

How many characters are in your name? 3
Enter the column numbers (1-5):
Column for character 1: 1
Column for character 2: 1
Column for character 3: 3

Select again from rows:
...

Guessed Name: ACH
```

---

## 🧩 Concepts Demonstrated

```cpp
// STL Containers
vector<vector<char>> grid;     // 2D grid storage
set<int> uniqueColumns;        // Unique column tracking (auto-sorted)

// Multi-threading
this_thread::sleep_for(chrono::milliseconds(500));  // Loading animation

// Input Validation
while (true) {
    cin >> input;
    if (cin.fail()) { cin.clear(); cin.ignore(...); }
    else if (input < min || input > max) { /* retry */ }
    else break;
}

// Frequency Analysis
sort(sortedChars.begin(), sortedChars.end());
// → find most frequent element → guessed letter
```

---

## 📜 License

This project is open-source and available under the [MIT License](LICENSE).

---

## 🤝 Contributing

Contributions, issues, and feature requests are welcome!

1. Fork the repository
2. Create your feature branch: `git checkout -b feature/improvement`
3. Commit your changes: `git commit -m 'Add some improvement'`
4. Push to the branch: `git push origin feature/improvement`
5. Open a Pull Request

---

## 👨‍💻 Author

**Ahsan Ali Shah** — Flutter & Mobile Application Developer

> *This project was built as part of my early programming journey — demonstrating understanding of C++ STL, algorithms, and system-level concepts.*

[![LinkedIn](https://img.shields.io/badge/LinkedIn-Connect-blue?logo=linkedin)](https://linkedin.com/in/ahsanalishah4105)
[![Fiverr](https://img.shields.io/badge/Fiverr-Hire%20Me-1DBF73?style=flat&logo=fiverr&logoColor=white)]([https://www.fiverr.com/s/m51PEoZ](https://www.fiverr.com/sellers/ahsanshahkazm/edit))
[![GitHub](https://img.shields.io/badge/GitHub-Follow-black?style=flat&logo=github)](https://github.com/ahsanshah4105)

---

<div align="center">

**⭐ If you found this interesting, give it a star!**

*Built with C++17 · STL · Multithreading · Frequency Analysis*

</div>
