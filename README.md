# Push_swap - Sorting Algorithm Project in C

## 📌 Description
**Push_swap** is an algorithmic project written in **C** that aims to sort a stack of integers with a limited set of operations using **two stacks (A and B)**. The goal is to achieve the sorting with the **fewest possible moves**.

The allowed operations are:

- **sa**: Swap the first two elements of stack A
- **sb**: Swap the first two elements of stack B
- **ss**: Swap the first two elements of both stacks A and B
- **pa**: Push the top element from stack B to stack A
- **pb**: Push the top element from stack A to stack B
- **ra**: Rotate stack A upwards (first element becomes last)
- **rb**: Rotate stack B upwards (first element becomes last)
- **rr**: Rotate both stacks upwards
- **rra**: Reverse rotate stack A (last element becomes first)
- **rrb**: Reverse rotate stack B (last element becomes first)
- **rrr**: Reverse rotate both stacks

The program takes a sequence of integers as arguments and outputs the sequence of operations required to sort them in ascending order.

---

## 🎮 Features

- 🧮 **Efficient Sorting Algorithm** for small and large sets of integers
- 🌀 **Handling small cases (3, 4, 5 elements)** with optimal moves
- 🔄 **Rotations and Reverse Rotations** optimization
- 🚧 **Error handling** for invalid inputs
- ✅ **Duplicate and range checking** for valid integer inputs

---

## 🛠 Compilation and Execution

### 🔧 **Compilation**

```sh
make
```

### ▶️ **Execution**

```sh
./push_swap [numbers]
```
Example:
```sh
./push_swap 3 2 5 1 4
```

```sh
./push_swap "3 2 5 1 4"
```
The program will output the operations required to sort the sequence.

---

## 🧑‍💻 Input Validation
- The input must be integers within the range of **INT_MIN** and **INT_MAX**.
- Duplicate values are not allowed.
- Non-numeric characters are invalid.

---

## 📂 Project Structure

```
push_swap/
├── include/
│   ├── error_handling.h
│   ├── instruction.h
│   ├── libft.h
│   ├── push_swap.h
│   ├── small_sort.h
│   ├── sorting.h
│   ├── stack_operation.h
│   └── tool.h
├── mylib/
├── src/
│   ├── error_handling.c
│   ├── instructions_2.c
│   ├── instructions_3.c
│   ├── instructions.c
│   ├── main.c
│   ├── small_sort.c
│   ├── sorting.c
│   ├── stack_operations.c
│   ├── tool_2.c
│   └── tool.c
├── Makefile
├── push_swap_subject.pdf
└── README.md
```

---

## 📜 Author
- **vbonnard** (<vbonnard@student.42.fr>)
---

## 📌 Note
This project was developed as part of **42 School**. If you encounter a bug or have suggestions, feel free to contribute! 🚀
