# Math Game 🧮

An interactive console application designed to test arithmetic skills through dynamically generated quizzes. Built with **C++**, the system allows users to customize their testing environment by selecting difficulty levels, operation types, and quiz length.

## 💻 Project Overview

This project serves as a demonstration of **Modular Procedural Programming**. It moves beyond simple linear scripts by implementing a robust **Game Loop**, state management using **Enumerations**, and dynamic randomization logic to ensure no two quizzes are exactly the same.

## 🚀 Key Features

### ⚙️ Customizable Settings
* **Difficulty Scaling:** Users can select between Easy (Single-digit), Medium (Double-digit), Hard (Up to 100), or a **"Mix"** mode that changes difficulty per question.
* **Operation Control:** Supports Addition, Subtraction, Multiplication, Division, or a **"Mix"** mode that randomizes the operator for every new question.
* **Quiz Length:** Dynamic input allows the user to define exactly how many questions they want to face.

### 🎲 Randomization Engine
* **Operand Generation:** Utilizes pseudo-random number generation with specific ranges based on the selected difficulty level.
* **Dynamic Mix Logic:** When "Mix" is selected, the system re-evaluates the difficulty and operation type on every single iteration of the loop, creating a truly unpredictable experience.

### 📊 Scoring System
* **Real-time Feedback:** Immediate validation of answers (Right/Wrong) is provided after every input.
* **Final Report:** The system tracks performance metrics in the background and generates a "Pass/Fail" report at the end of the session.

## ⚙️ Code Structure

The application follows a clean functional design, separating concerns into distinct logic blocks:

* **Input Handling:** Robust validation functions ensure user inputs for difficulty and question counts fall within allowed ranges.
* **Math Logic Core:** Dedicated functions handle the raw arithmetic and random number generation, isolated from the user interface.
* **Game Loop Controller:** A central function manages the flow of the quiz, iterating through questions and maintaining the score state until the session ends.

## 🛠 Tech Stack

* **Language:** C++
* **Paradigm:** Procedural Programming
* **Concepts:** Enums, Random Number Generation, Control Structures
