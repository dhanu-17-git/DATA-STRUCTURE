
# 🧠 Module 1 — Pointers & Data Structure Fundamentals
*(C Programming + DSA Basics — Teacher’s Friendly Guide)*

---

## 📑 Table of Contents (Click to Jump)

1. [What is a Data Structure?](#-1-what-is-a-data-structure)
2. [Pointers in C](#-2-pointers-in-c)
   - [Symbol Table & Relative Address](#️-symbol-table--relative-address)
   - [Pointer Arithmetic](#-pointer-arithmetic)
   - [Null Pointer](#-null-pointer)
   - [Generic (Void) Pointer](#-generic-void-pointer)
   - [Pointer to Pointer](#-pointer-to-pointer)
3. [Structures in C](#-3-structures-in-c)
   - [Typedef Declaration](#-typedef-declaration)
   - [Accessing Members](#-accessing-members)
   - [Dot vs Arrow Operator](#-dot-vs-arrow-operator)
   - [Nested Structures](#-nested-structures)
   - [Arrays of Structures](#-arrays-of-structures)
   - [Structures & Functions](#-structures--functions)
   - [Self-Referential Structure](#-self-referential-structure)
4. [Classification of Data Structures](#-4-classification-of-data-structures)
5. [Operations on Data Structures](#-5-operations-on-data-structures)
6. [Abstract Data Type (ADT)](#-6-abstract-data-type-adt)

---

## 📘 1. What is a Data Structure?

**🧩 Definition**  
A data structure is a way to **store and organize data** in memory so that we can use it efficiently.

**💡 Concept Explanation**  
- Think of it like a bookshelf:  
  - Random books on the floor → hard to find  
  - Alphabetically arranged → fast access  
- Data structures help programs **access and update data efficiently**.

**⚙️ Example**
```c
int marks[5] = {45, 67, 88, 56, 92};  // Array = basic data structure
````

**🔑 Key Points**

* Organizes data for efficiency
* Faster access and updates
* Examples: Array, Linked List, Stack, Queue, Tree, Graph
* Core of algorithms and software logic

---

## 🧭 2. Pointers in C

**🧩 Definition**
A pointer is a variable that stores the **memory address** of another variable.

**💡 Concept Explanation**

* Example: `int x = 10;` → memory reserved for `x`
* Pointer = “house address” of `x`, so you can access it later.

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

* `&` → gives address
* `*` → gets value stored at address
* Used for **dynamic memory, arrays, functions, structs**

---

### 🗃️ Symbol Table & Relative Address

**Symbol Table:** Compiler's notebook storing variable **name, type, address**

**Relative Address:** Distance from starting memory block

| Symbol | Type | Address      |
| ------ | ---- | ------------ |
| x      | int  | offset +1003 |

---

### ➕ Pointer Arithmetic

```c
int arr[3] = {10, 20, 30};
int *p = arr;

printf("%d\n", *p);  // 10
p++;
printf("%d\n", *p);  // 20
```

**Rules:**

* Adding 1 moves pointer by **1 element**, not 1 byte
* `*ptr++` → increases pointer
* `(*ptr)++` → increases value

---

### ⚫ Null Pointer

```c
int *ptr = NULL;

if (ptr == NULL)
    printf("Pointer is empty!");
```

✅ Prevents access to garbage memory

---

### 🌀 Generic (Void) Pointer

```c
int a = 5;
void *ptr = &a;
printf("%d", *(int *)ptr);
```

✅ Can point to **any data type**
✅ Must be typecast before dereferencing

---

### 🧩 Pointer to Pointer

```c
int a = 10;
int *p = &a;
int **pp = &p;

printf("%d", **pp);  // 10
```

➡️ Used in **dynamic memory, linked lists, 2D arrays**

---

### ⚠️ Pointer Drawbacks

* Wrong memory access → crash 💀
* Uninitialized pointer → wild pointer
* Hard to debug

---

## 🧰 3. Structures in C

**🧩 Definition**
Used to group variables of **different data types**.

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

**🔑 Key Points**

* Combines multiple types
* Uses dot (`.`) operator to access members

---

### ⚙️ Typedef Declaration

```c
typedef struct {
    int roll;
    char name[20];
} student;

student s1;
```

➡️ Makes code clean and short

---

### ⚙️ Accessing Members

```c
s1.roll = 10;
printf("%s", s1.name);
```

---

### 🧭 Dot vs Arrow Operator

```c
struct Point {
    int x, y;
};

struct Point p, *ptr = &p;

p.x = 5;     // dot operator (direct access)
ptr->y = 10; // arrow operator (pointer access)
```

---

### 🧩 Nested Structures

```c
typedef struct { char first[20]; char last[20]; } Name;
typedef struct { int dd, mm, yy; } Date;

typedef struct {
    int id;
    Name name;
    Date dob;
} Student;

Student s;
s.name.first = "John";
s.dob.yy = 2002;
```

---

### 📚 Arrays of Structures

```c
struct student {
    int id;
    char name[20];
};

struct student s[3] = {
    {1, "Aman"},
    {2, "Aryan"},
    {3, "John"}
};

printf("%s", s[1].name);
```

---

### ⚙️ Structures & Functions

**1️⃣ Passing individual member**

```c
void display(int roll) {
    printf("Roll = %d", roll);
}
display(s1.roll);
```

**2️⃣ Passing whole structure**

```c
void show(struct student s) {
    printf("%s", s.name);
}
```

**3️⃣ Passing structure using pointer**

```c
void update(struct student *s) {
    s->id = 101;
}
update(&s1);
```

---

### 🔁 Self-Referential Structure (Linked List Base)

```c
struct node {
    int data;
    struct node *next;
};
```

---

## 🧮 4. Classification of Data Structures

| Type          | Examples            | Description              |
| ------------- | ------------------- | ------------------------ |
| Primitive     | int, char, float    | Built-in basic types     |
| Non-Primitive | Array, List, Tree   | Made from primitives     |
| Linear        | Array, Stack, Queue | Sequential access        |
| Non-Linear    | Tree, Graph         | Hierarchical / networked |

---

## 🔧 5. Operations on Data Structures

| Operation | Meaning        | Example            |
| --------- | -------------- | ------------------ |
| Traverse  | Visit all data | Print all records  |
| Search    | Find element   | Find roll no. 2    |
| Insert    | Add element    | Add student record |
| Delete    | Remove element | Delete record      |
| Sort      | Arrange order  | Marks ascending    |
| Merge     | Combine data   | Merge two lists    |

---

## 🧱 6. Abstract Data Type (ADT)

**🧩 Definition**
Defines **what operations can be done**, not how they are implemented.

**💡 Concept**
Like a vending machine — you press the button (operation), you don’t care how it works inside.

**⚙️ Example (Stack ADT)**

```c
push(); // add item
pop();  // remove item
```

✅ Focuses on **behavior**, not implementation
✅ Improves modularity

---

✔️ End of Module 1 — All the Best 🤝

```

