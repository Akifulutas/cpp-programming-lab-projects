# 🎓 C++ Advanced Programming Practicum

A comprehensive collection of C++ engineering projects developed during the "Praktikum Programmiersprachen" coursework at **RWTH Aachen University**. This repository demonstrates a progressive mastery of modern C++ concepts, from low-level memory management to advanced Object-Oriented Programming (OOP) and custom data structure implementations.

## 🚀 Key Technical Highlights

Unlike standard application development, this practicum focuses on building core computer science mechanisms from scratch without relying heavily on the C++ Standard Template Library (STL) in the initial phases:

* **Raw Memory Management:** Deep understanding of pointer arithmetic, dynamic memory allocation (`new`/`delete`), and preventing memory leaks in complex object lifecycles.
* **Custom Data Structures:** Engineered custom implementations of Doubly Linked Lists, Ring Buffers, Stacks, Queues, and dynamic Vectors (`MyVector`).
* **Advanced OOP Architecture:** Extensive use of Inheritance, Polymorphism, Abstract Classes, and Virtual Functions to model real-world systems (e.g., Library Management, Chess Board logic).
* **Professional Build System:** The entire multi-module project is orchestrated using **CMake**, allowing for seamless cross-platform compilation and modular testing.
* **File I/O & Parsing:** Robust handling of external data, reading/writing to `.csv` and `.txt` files, string tokenization, and dynamic object instantiation based on parsed data.

## 📂 Module Overview (Praktikum Stages)

The repository is structured into distinct modules, each targeting specific core competencies:

* **`P1/` (Pointers & Dynamic Arrays):** Magic Square generation and basic singly linked list operations. Focus on fundamental pointer manipulation.
* **`P2/` (Advanced Structures):** Implementation of a Doubly Linked List and a circular Ring Buffer architecture.
* **`P3/` (Polymorphism):** A Library Management System (`Bibliothek`) simulating polymorph behavior across different media types (`Buch`, `DVD`).
* **`P4/` (Game Logic & OOP):** A Chess simulator (`Schachbrett`) utilizing abstract classes for chess pieces (`Spielfigur`) and inheritance for specific movements (`Turm`).
* **`P5/` (LIFO/FIFO & Exceptions):** Custom implementations of `Stack` and `Queue` using linked elements, alongside custom C++ exception handling (`out_of_range`).
* **`P6/` (Data Processing):** A Student Database (`StudentenTabelle`) featuring File I/O parsing, operator overloading, and array sorting algorithms.

## 🛠️ Technologies & Tools

* **Language:** C++
* **Build System:** CMake, Make / GCC compiler
* **Concepts:** Data Structures, OOP, Pointer Arithmetic, Memory Management, File I/O

## ⚙️ How to Build and Run

This project uses CMake for easy compilation across different environments.

1. **Clone the repository:**
   ```bash
   git clone [https://github.com/Akifulutas/cpp-programming-lab-projects.git](https://github.com/Akifulutas/cpp-programming-lab-projects.git)
   cd cpp-programming-lab-projects
2. Generate Build Files & Compile:
mkdir build &å ed build
cmake
make
3.
Execute Modules:
Run the specific executables generated in the build directory for each practicum stage.
./P1_Executable # (Replace with actual target names defined in CMakeLists)
