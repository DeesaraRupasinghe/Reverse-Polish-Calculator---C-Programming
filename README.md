# Reverse Polish Notation Calculator

This repository contains a simple implementation of a Reverse Polish Notation (RPN) calculator in C. RPN, also known as postfix notation, is a mathematical notation in which every operator follows all of its operands. This calculator evaluates expressions in RPN format using a stack data structure.

## Features

- Supports basic arithmetic operations: addition (+), subtraction (-), multiplication (*), and division (/).
- Handles operands as integers.
- Provides error handling for division by zero and invalid characters in expressions.

## How to Run

### Prerequisites
- C Compiler (e.g., GCC)

### Steps
1. Clone the repository to your local machine:
    ```bash
    git clone https://github.com/your_username/rpn-calculator.git
    ```
2. Navigate to the repository directory:
    ```bash
    cd rpn-calculator
    ```
3. Compile the source code:
    ```bash
    gcc main.c -o rpn_calculator
    ```
4. Run the executable:
    ```bash
    ./rpn_calculator
    ```
5. Enter Reverse Polish Notation expressions when prompted. Separate each expression by spaces and press Enter after each expression.

## Example
```
Enter Reverse Polish Notation expressions (separated by spaces): 5 3 +
Result: 8
```

## Usage Tips
- Ensure each expression is in valid RPN format with appropriate spaces separating operands and operators.
- Remember that RPN does not require parentheses for grouping; it follows a strict left-to-right evaluation order.