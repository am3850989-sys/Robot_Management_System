# Robot Management System (C++) 🤖

A robust console-based application designed to manage different types of robots using **Object-Oriented Programming (OOP)** principles in C++.

## 🚀 Features
- **Dynamic Robot Creation:** Supports multiple robot types (Cleaning, Security, and Delivery).
- **Polymorphism in Action:** Each robot type has its own specific `task()` and `updateMaintenance()` logic.
- **System Controls:** - Bulk charging mode.
  - Emergency shutdown for all units.
  - Tracking maintenance history and schedules.
- **Input Validation:** Ensures robot statuses are only set to recognized states.

## 🛠 Concepts Used
- **Inheritance:** Base class `Robot` with specialized derived classes.
- **Polymorphism:** Using `virtual` functions and `override` to provide specific behaviors.
- **Encapsulation:** Protecting data members and providing access through getters and setters.
- **Memory Management:** Managing objects using pointers and arrays.

## 💻 How to Run
1. Clone the repository.
2. Compile using any C++ compiler (e.g., `g++ RobotSystem.cpp -o RobotSystem`).
3. Run the executable file.
4.
