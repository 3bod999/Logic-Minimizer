# 🚀 Logic Minimizer CLI

A powerful C++ tool to simplify Boolean expressions using the **Kitty** library. This project takes complex logic equations and reduces them to their simplest **Sum of Products (SOP)** form.



## ✨ Features
* **Expression Parsing:** Supports direct input of logic strings (e.g., `(a&b)|(a&!b)`).
* **Advanced Minimization:** Uses the **ISOP (Irredundant Sum of Products)** algorithm.
* **Support for Multiple Variables:** Handles up to 4 variables (`a`, `b`, `c`, `d`).
* **Clean CLI Output:** Provides clear, human-readable simplified results.

## 🛠️ Logic Symbols Supported
| Operation | Symbol | Example |
|-----------|--------|---------|
| **AND** | `&`    | `a & b` |
| **OR** | `\|`   | `a \| b`|
| **NOT** | `!`  | `!a`    |
| **XOR** | `^`    | `a ^ b` |



## 🚀 Getting Started

### Prerequisites
* A C++ compiler (supporting C++17).
* The [Kitty](https://github.com/lsils/kitty) library header files.

### Compilation
Run the following command in your terminal:
```bash
g++ -std=c++17 main.cpp -I ../kitty/include -o logic_minimizer


<img width="1169" height="760" alt="image" src="https://github.com/user-attachments/assets/48da3b7f-ab08-42a8-9d9c-96b4639b5087" />

