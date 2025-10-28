
# 📘 Data Structures & Pointers - Module 1

## 1. What is a Data Structure?

### 🧩 Definition
A *data structure* is a way to store and organize data in memory so that we can *use it efficiently*.

### 💡 Concept Explanation
Think of it like a *bookshelf*. If you just throw books randomly on the floor, finding one takes forever.  
But if you *arrange them properly* (say, alphabetically), finding one is fast. That's what a data structure does for your program.

### 🧱 Syntax
There's no single syntax — data structures are implemented using language constructs (arrays, structs, pointers, classes, etc.).

### ⚙ Example
```c
int marks[5] = {45, 67, 88, 56, 92};  // Array = basic data structure
```

### 🔑 Key Points
- Organizes data for efficiency
- Improves access and update speed
- Common examples: Array, Linked List, Stack, Queue, Tree, Graph
- Core of algorithm design and real-world software

---

## 🧭 2. Pointers in C

### 🧩 Definition
A pointer is a variable that stores the memory address of another variable.

### 💡 Concept Explanation
When you declare `int x = 10;`, memory is reserved to hold `x`. A pointer stores the address of that memory location.  
Pointers let you access or change the data at that address directly — powerful and dangerous.

### 🧱 Syntax
```c
data_type *pointer_name;
```

### ⚙ Example
```c
int x = 10;
int *ptr = &x;    // ptr stores address of x
printf("x = %d\n", *ptr);     // dereference -> prints 10
printf("Address of x = %p\n", ptr);
```

### 🔑 Key Points
- `&` — address-of operator (gives address)
- `*` — dereference operator (gives value at address)
- Useful for arrays, dynamic memory, function parameters, and complex data structures

---

## 🗃 Symbol Table & Relative Address

**Symbol Table:**
A data structure used by compilers to map identifiers (variables, functions) to metadata: type, scope, memory location (address / offset), etc.

**Relative Address:**
The offset or displacement from the start of a memory block or segment (useful for relocatable code and in compilers/linkers).

### 🔹 Small Example (conceptual)
When compiler sees:
```c
int x = 10;
```
it stores:

| Symbol | Type | Address/Offset |
|--------|------|----------------|
| x      | int  | offset +1003 (example) |

This helps generated code refer to variables by offsets.

---

## ➕ Pointer Arithmetic

Pointers support arithmetic operations — but semantics depend on the pointed type.

```c
int arr[3] = {10, 20, 30};
int *p = arr;      // points to arr[0]

printf("%d\n", *p); // 10
p++;                // moves to arr[1]
printf("%d\n", *p); // 20
```

### 🔑 Rules
- `p + 1` advances the pointer by `sizeof(*p)` bytes (one element), not by 1 byte
- On many systems `sizeof(int)` is 4 -> `p+1` moves 4 bytes for `int *`
- `*ptr++` is parsed as `*(ptr++)` — pointer increments, dereference uses previous location
- Use `(*ptr)++` to increment the value pointed to by ptr

---

## ⚫ Null Pointer

A null pointer points to nothing. Use `NULL` or `0` to initialize.

```c
int *ptr = NULL;
if (ptr == NULL) {
    printf("Pointer is empty\n");
}
```

### 🔑 Key
- Prevents accidental dereference of an invalid address
- Defined in `<stddef.h>`, `<stdio.h>`, `<stdlib.h>`
- Always check pointers before dereferencing

---

## 🌀 Generic (Void) Pointer

`void *` can hold address of any data type, but cannot be dereferenced until cast.

```c
int a = 5;
void *ptr = &a;
printf("%d\n", *(int *)ptr);  // cast to int before dereferencing
```

### 🔑 Key Points
- Type-agnostic pointer: useful in generic APIs (e.g., malloc, callbacks)
- Must cast to correct type before use

---

## 🧩 Pointer to Pointer

Pointer that points to another pointer (multi-level indirection).

```c
int a = 10;
int *p = &a;
int **pp = &p;

printf("%d\n", **pp); // 10
```

### 🔑 Use Cases
- Dynamic 2D arrays implemented via pointers-to-pointers
- Functions that need to modify the pointer passed by caller (e.g., allocate and set a pointer)

---

## ⚠ Drawbacks of Pointers

- Incorrect pointer use → crashes / undefined behavior
- Dangling pointers (pointing to freed memory) cause serious bugs
- Uninitialized pointers are "wild" — always initialize
- Memory leaks when dynamically allocated memory isn't freed

---

## 🧰 3. Structures

### 🧩 Definition
A structure (struct) is a user-defined data type that groups related variables (possibly of different types) under a single name.

### 💡 Concept Explanation
Use struct to model complex real-world entities. Eg: a student record has roll, name, course, fees (different types) — pack into one structure.

### 🧱 Syntax
```c
struct student {
    int r_no;
    char name[20];
    char course[20];
    float fees;
};
```

### ⚙ Example
```c
struct student stud1 = {1, "Rahul", "BCA", 45000.0};
printf("Name: %s, Fees: %.2f\n", stud1.name, stud1.fees);
```

### 🔑 Key Points
- Structure declaration defines a template — memory allocated only when variable is declared
- Members accessed with `.` when variable is a direct instance

---

## ⚙ Typedef Declaration

`typedef` creates an alias for a type — saves typing and improves readability.

```c
typedef struct {
    int r_no;
    char name[20];
    char course[20];
    float fees;
} student;

student stud1;   // now 'student' is a type name
```

### 🔑 Note
`typedef` doesn't create a new type at runtime — it's just an alias for the compiler.

---

## 🧱 Initialization of Structures

You can initialize at declaration:
```c
struct student s1 = {01, "Rahul", "BCA", 45000.0};
```

Partial initialization:
```c
struct student s2 = {02, "Aman"}; // other members default to 0 or '\0'
```

---

## ⚙ Accessing Members

```c
s1.r_no = 10;
strcpy(s1.name, "Dhanush");
printf("Course: %s\n", s1.course);
```

Use `scanf("%s", s1.name);` carefully — watch buffer sizes.

---

## ✅ Copying and Comparing Structures

You can assign one structure to another of the same type:
```c
struct student s1 = {1, "Rahul", "BCA", 45000.0};
struct student s2;
s2 = s1; // copies all members
```

C does not permit direct comparison of whole structs with `==`. Compare members individually:
```c
if (s1.fees > s2.fees) { ... }
```

---

## 🔎 Dot (.) and Arrow (->) Operators

Use `.` to access members of a structure variable.  
Use `->` to access members via a pointer to a structure.

**Example (dot)**
```c
struct Point {
    int x;
    int y;
};

struct Point p;
p.x = 5;
p.y = 10;
printf("(%d, %d)\n", p.x, p.y);
```

**Example (arrow)**
```c
struct Point *ptr = &p;
ptr->x = 7;          // same as (*ptr).x = 7;
printf("(%d, %d)\n", ptr->x, ptr->y);
```

---

## 🧩 Nested Structures

A structure can contain other structures.

```c
typedef struct {
    char first_name[20];
    char mid_name[20];
    char last_name[20];
} NAME;

typedef struct {
    int dd;
    int mm;
    int yy;
} DATE;

typedef struct {
    int r_no;
    NAME name;
    char course[20];
    DATE DOB;
    float fees;
} student;
```

Accessing nested members:
```c
student s;
strcpy(s.name.first_name, "Janak");
s.DOB.dd = 15;
s.fees = 45000.0;
```

---

## 📚 Arrays of Structures

Store multiple records of the same structure type.

```c
struct student {
    int r_no;
    char name[20];
    char course[20];
    float fees;
};

struct student stud[30];
```

Initialization at declaration:
```c
struct student stud[3] = {
    {1, "Aman", "BCA", 45000},
    {2, "Aryan", "BCA", 60000},
    {3, "John", "BCA", 45000}
};

printf("%s\n", stud[1].name); // Aryan
```

---

## ⚙ Structures and Functions

Three common ways to use structures in functions:

**1. Passing individual members**
```c
void showRoll(int r) {
    printf("Roll = %d\n", r);
}
showRoll(stud[0].r_no);
```

**2. Passing entire structure (by value)**
```c
void display(struct student s) {
    printf("%s\n", s.name);
}
display(stud[0]); // copies the structure
```
*Note: Passing large structs by value is inefficient (copy happens).*

**3. Passing pointer to structure (recommended)**
```c
void updateFees(struct student *s, float delta) {
    s->fees += delta;
}
updateFees(&stud[0], 500.0);
```

**Example full program (display via pointer)**
```c
#include <stdio.h>
typedef struct {
    int x;
    int y;
} POINT;

void display(POINT p) {
    printf("The coordinates are: %d %d\n", p.x, p.y);
}

int main() {
    POINT p1 = {2, 3};
    display(p1);
    return 0;
}
```

---

## 🔁 Self-Referential Structures

Structure containing a pointer to its own type — foundation of linked lists.

```c
struct node {
    int val;
    struct node *next;
};
```

Use to build:
- Singly linked lists
- Stacks/queues (linked)
- Trees (nodes pointing to children)

---

## ▶ Programs (Practice)

1. Declare variables and pointers; display values and addresses using pointers
2. Swap two numbers using a function (by value and by pointer)
3. Use structures to read/display student info
4. Array of structures — read/display information of multiple students
5. Add/subtract two complex numbers using structures

*(These are classic small practice programs — try implementing them.)*

---

## 🧮 4. Introduction to Data Structures — Classification

### Primitive vs Non-Primitive
- **Primitive**: Basic built-in types (int, char, float, double)
- **Non-Primitive**: Built using primitives (arrays, structs, lists, trees, graphs)

### Linear vs Non-linear
- **Linear**: Elements are arranged sequentially (Array, Linked List, Stack, Queue)
- **Non-linear**: Elements have hierarchical or graph relationships (Tree, Graph)

---

## ➿ Arrays

### Definition
An array is a collection of similar data elements stored at contiguous memory locations and referenced by index (subscript).

### Syntax
```c
type name[size];
```

### Example
```c
int arr[5] = {1, 2, 3, 4, 5};
printf("%d\n", arr[2]); // 3
```

### Key Points
- Fixed size
- Fast random access (O(1) by index)
- Insert/delete in middle expensive (shifting)
- Contiguous memory requirement may cause allocation issues

---

## ➿ Linked Lists

### Definition
A linked list is a dynamic collection of nodes where each node contains data and a pointer to the next node.

### Node structure
```c
struct node {
    int data;
    struct node *next;
};
```

### Key Points
- Dynamic size (grow/shrink at runtime)
- Efficient insert/delete (O(1) with pointer manipulation at known positions)
- Search is O(n)
- Extra memory for pointers

---

## 🗂 Stacks

### Definition
LIFO data structure — last inserted, first removed.

### Basic operations
- `push()` — insert at top
- `pop()` — remove from top
- `peek()` or `top()` — view top without removing

### Implementations
- Array-based (fixed size)
- Linked-list-based (dynamic)

### Key Points
Useful for recursion, expression evaluation, backtracking.

---

## ↔ Queues

### Definition
FIFO data structure — first inserted, first removed.

### Basic operations
- `enqueue()` — insert at rear
- `dequeue()` — remove from front

### Implementations
- Array-based (circular queue recommended)
- Linked-list-based

### Key Points
Useful in scheduling, buffering, BFS on graphs.

---

## 🌳 Trees

### Definition
Non-linear hierarchical data structure with nodes having parent-child relationships. A root node is the top.

### Binary tree node
```c
struct node {
    int data;
    struct node *left;
    struct node *right;
};
```

### Key Points
- Binary tree: each node max two children
- Balanced vs unbalanced affects search times
- Special trees: BST (binary search tree), AVL, heap, etc.

---

## 🔗 Graphs

### Definition
Collection of vertices (nodes) and edges (connections) — models networked relationships.

### Representations
- Adjacency matrix (dense graphs)
- Adjacency list (sparse graphs)

### Key Points
- Useful for routing, social networks, dependency graphs
- Many important algorithms: BFS, DFS, Dijkstra, Kruskal, Prim

---

## 🔧 Operations on Data Structures

| Operation | Meaning | Example |
|-----------|---------|---------|
| Traverse | Visit all elements | Print the list |
| Search | Find data item | Find key in array |
| Insert | Add element | Add student to list |
| Delete | Remove element | Delete from queue |
| Sort | Arrange order | Quick sort array |
| Merge | Combine | Merge two sorted lists |

---

## 🧱 6. Abstract Data Type (ADT)

### 🧩 Definition
An ADT specifies what operations are available and what behavior is expected, but not how it is implemented.

### 💡 Concept Explanation
Like a vending machine: you press a button (operation). You don't need to know how its internal mechanism (the implementation) works.

### Example: Stack ADT
**Operations:**
```c
void push(int item);
int pop(void);
int isEmpty(void);
```

Implementation can use array or linked list — user's interface remains same.

### 🔑 Advantages
- **Abstraction**: hide implementation details
- **Modularity**: swap data structure implementation without changing user code
- **Reusability and maintainability**

---

## ✅ Summary (Key Takeaways)

- Pointers give control over memory (addresses, dynamic allocations), but they require caution
- Structures let you group different data types into meaningful records
- Self-referential structures form the basis of dynamic DS (linked lists, trees)
- Classification: primitive vs non-primitive, linear vs non-linear
- Operations: traverse, insert, delete, search, sort, merge — fundamental for algorithms
- ADT separates interface from implementation — a core software engineering principle

---

## 📎 Example Mini Programs (C)

### 1) Pointer demo
```c
#include <stdio.h>
int main() {
    int x = 10;
    int *p = &x;
    printf("Value: %d\n", *p);
    printf("Address: %p\n", p);
    return 0;
}
```

### 2) Swap using pointers
```c
#include <stdio.h>
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}
int main() {
    int x = 5, y = 10;
    swap(&x, &y);
    printf("x=%d y=%d\n", x, y);
    return 0;
}
```

### 3) Simple struct usage
```c
#include <stdio.h>
typedef struct {
    int roll;
    char name[20];
    float fees;
} Student;

int main() {
    Student s = {1, "Aman", 45000.0};
    printf("Name: %s, Roll: %d, Fees: %.2f\n", s.name, s.roll, s.fees);
    return 0;
}
```

