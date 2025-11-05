
# 🧠 Module 1 — Pointers & Data Structure Fundamentals

*(C Programming + DSA Basics — Teacher’s Friendly Guide)*

---

## 📑 Table of Contents

1. [What is a Data Structure?](#-1-what-is-a-data-structure)
2. [Pointers in C](#-2-pointers-in-c)

   * [Symbol Table & Relative Address](#️-symbol-table--relative-address)
   * [Pointer Arithmetic](#-pointer-arithmetic)
   * [Null Pointer](#-null-pointer)
   * [Generic (Void) Pointer](#-generic-void-pointer)
   * [Pointer to Pointer](#-pointer-to-pointer)
3. [Structures in C](#-3-structures-in-c)

   * [Typedef Declaration](#-typedef-declaration)
   * [Accessing Members](#-accessing-members)
   * [Dot vs Arrow Operator](#-dot-vs-arrow-operator)
   * [Nested Structures](#-nested-structures)
   * [Arrays of Structures](#-arrays-of-structures)
   * [Structures & Functions](#-structures--functions)
   * [Self-Referential Structure](#-self-referential-structure)
4. [Classification of Data Structures](#-4-classification-of-data-structures)
5. [Operations on Data Structures](#-5-operations-on-data-structures)
6. [Abstract Data Type (ADT)](#-6-abstract-data-type-adt)

---

## 📘 1. What is a Data Structure?

**🧩 Definition:**
A **data structure** is a systematic way of **organizing, storing, and managing data** so it can be used efficiently.

**💡 Think of it like:**
📚 A *library bookshelf* — when books are arranged by subject or title, it’s easy to find one.
If all books were on the floor, searching would take hours — that’s what happens when data is unorganized!

**⚙️ Example**

```c
int marks[5] = {45, 67, 88, 56, 92};  // Array = basic data structure
```

**🔑 Key Points**

* Helps store and retrieve data quickly
* Improves efficiency of programs
* Common structures: **Array, Stack, Queue, Linked List, Tree, Graph**
* Foundation for **algorithms and problem-solving**

---

## 🧭 2. Pointers in C

**🧩 Definition:**
A **pointer** is a special variable that stores the **memory address** of another variable.

**💡 Imagine:**
If a variable is a *house*, the pointer is its *address*.
Instead of directly going inside the house, you can use the address to find it anytime.

**🧱 Syntax**

```c
data_type *pointer_name;
```

**⚙️ Example**

```c
int x = 10;
int *ptr = &x;
printf("x = %d\n", *ptr);
printf("Address of x = %p\n", ptr);
```

**🔑 Key Points**

* `&` → “address of” operator
* `*` → “value at” operator (dereference)
* Used for **dynamic memory, arrays, functions, and structures**

---

### 🗃️ Symbol Table & Relative Address

**Symbol Table:**
It’s like the compiler’s *contact list*, where it records —
→ variable name, type, and where it lives in memory.

| Symbol | Type | Address      |
| ------ | ---- | ------------ |
| x      | int  | offset +1003 |

**Relative Address:**
It’s not the full address, but a **distance (offset)** from the program’s start in memory.
Think of it as “Room 3rd from the start of the floor.”

---

### ➕ Pointer Arithmetic

**🧩 Definition:**
Pointer arithmetic allows you to **move** a pointer forward or backward by elements.

**Example**

```c
int arr[3] = {10, 20, 30};
int *p = arr;
printf("%d\n", *p);  // 10
p++;
printf("%d\n", *p);  // 20
```

**💡 Analogy:**
If `p` points to the first student in a queue, `p++` moves to the next student.

**Rules**

* Adding `1` → moves pointer to **next element**, not 1 byte
* `*ptr++` → moves pointer
* `(*ptr)++` → increases value stored at pointer

---

### ⚫ Null Pointer

**🧩 Definition:**
A **null pointer** is a pointer that points to **nothing**.

**Example**

```c
int *ptr = NULL;

if (ptr == NULL)
    printf("Pointer is empty!");
```

**💡 Analogy:**
Like an empty address — no house exists there.
Used to **avoid garbage memory access**.

---

### 🌀 Generic (Void) Pointer

**🧩 Definition:**
A **void pointer** can store the address of **any data type**, but must be typecast before use.

**Example**

```c
int a = 5;
void *ptr = &a;
printf("%d", *(int *)ptr);
```

**💡 Analogy:**
A *universal plug adapter* — fits any socket, but needs proper conversion before use.

---

### 🧩 Pointer to Pointer

**🧩 Definition:**
A pointer that stores the **address of another pointer**.

**Example**

```c
int a = 10;
int *p = &a;
int **pp = &p;

printf("%d", **pp);  // 10
```

**💡 Analogy:**
Like having a “friend who knows the address of another friend.”

---

### ⚠️ Pointer Drawbacks

* Uninitialized pointer → *wild pointer* (dangerous 🐍)
* Wrong dereferencing → program crash
* Difficult to debug → needs careful handling

---

## 🧰 3. Structures in C

**🧩 Definition:**
A **structure** is a user-defined data type that allows grouping of **different data types** under one name.

**💡 Analogy:**
A student record contains roll number (int), name (string), and marks (float) — all related but different types.

**🧱 Syntax**

```c
struct student {
    int roll;
    char name[20];
    float marks;
};
```

**⚙️ Example**

```c
struct student s1 = {1, "Dhanush", 92.5};
printf("Name: %s, Marks: %.1f", s1.name, s1.marks);
```

---

### ⚙️ Typedef Declaration

**🧩 Definition:**
`typedef` creates a **nickname** for a structure.

```c
typedef struct {
    int roll;
    char name[20];
} student;

student s1;
```

**💡 Analogy:**
Like calling "Professor" instead of "Dr. John Matthew" — shorter and easier.

---

### ⚙️ Accessing Members

```c
s1.roll = 10;
printf("%s", s1.name);
```

**💡 Dot operator** connects structure name → member name.

---

### 🧭 Dot vs Arrow Operator

**Example**

```c
struct Point {
    int x, y;
};

struct Point p, *ptr = &p;

p.x = 5;     // dot operator
ptr->y = 10; // arrow operator
```

**💡 Analogy:**

* `.` → direct access (you own the object)
* `->` → indirect access (you have pointer to it)

---

### 🧩 Nested Structures

**🧩 Definition:**
A structure inside another structure.

```c
typedef struct { char first[20]; char last[20]; } Name;
typedef struct { int dd, mm, yy; } Date;

typedef struct {
    int id;
    Name name;
    Date dob;
} Student;
```

**💡 Analogy:**
Like a *folder inside another folder* on your computer.

---

### 📚 Arrays of Structures

**🧩 Definition:**
An array containing multiple structure variables.

```c
struct student s[3] = {
    {1, "Aman"},
    {2, "Aryan"},
    {3, "John"}
};
```

**💡 Analogy:**
Like a *classroom register* with many students.

---

### ⚙️ Structures & Functions

**1️⃣ Passing individual member**

```c
void display(int roll) { printf("Roll = %d", roll); }
display(s1.roll);
```

**2️⃣ Passing whole structure**

```c
void show(struct student s) { printf("%s", s.name); }
```

**3️⃣ Passing structure using pointer**

```c
void update(struct student *s) { s->id = 101; }
update(&s1);
```

**💡 Tip:**
Pass by pointer to avoid **copying large structures**.

---

### 🔁 Self-Referential Structure

**🧩 Definition:**
A structure that contains a **pointer to itself** — forms the base of **linked lists**.

```c
struct node {
    int data;
    struct node *next;
};
```

**💡 Analogy:**
Each train coach (node) connects to the *next* coach using a link.

---

## 🧮 4. Classification of Data Structures

| Type          | Examples            | Description                         |
| ------------- | ------------------- | ----------------------------------- |
| Primitive     | int, char, float    | Basic built-in types                |
| Non-Primitive | Array, List, Tree   | Made from primitives                |
| Linear        | Array, Stack, Queue | Data arranged in sequence           |
| Non-Linear    | Tree, Graph         | Data linked in hierarchy or network |

**💡 Analogy:**
Linear → Train coaches (one after another)
Non-linear → Family tree (one parent, many children)

---

## 🔧 5. Operations on Data Structures

| Operation | Meaning            | Example            |
| --------- | ------------------ | ------------------ |
| Traverse  | Visit all elements | Print all records  |
| Search    | Find an element    | Find roll no. 2    |
| Insert    | Add new data       | Add student record |
| Delete    | Remove data        | Delete record      |
| Sort      | Arrange order      | Marks ascending    |
| Merge     | Combine data       | Merge two lists    |

**💡 Analogy:**
Like maintaining a contact list — you add, delete, search, or update names.

---

## 🧱 6. Abstract Data Type (ADT)

**🧩 Definition:**
An **ADT** defines *what operations can be performed*, not *how they’re done internally*.

**💡 Analogy:**
A vending machine — you press a button (operation), you don’t know the internal mechanism.

**⚙️ Example (Stack ADT)**

```c
push(); // add item
pop();  // remove item
```

✅ Focus on **behavior**, not code details
✅ Improves **modularity and abstraction**


