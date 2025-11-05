
# 🧠 Module 1 — Pointers & Data Structure Fundamentals
*(C Programming + DSA Basics — Teacher’s Friendly Guide)*

---

## 📑 Table of Contents

1. [What is a Data Structure?](#1-what-is-a-data-structure)
2. [Pointers in C](#2-pointers-in-c)
   - [Symbol Table & Relative Address](#symbol-table--relative-address)
   - [Pointer Arithmetic](#pointer-arithmetic)
   - [Null Pointer](#null-pointer)
   - [Generic (Void) Pointer](#generic-void-pointer)
   - [Pointer to Pointer](#pointer-to-pointer)
3. [Structures in C](#3-structures-in-c)
   - [Typedef Declaration](#typedef-declaration)
   - [Accessing Members](#accessing-members)
   - [Dot vs Arrow Operator](#dot-vs-arrow-operator)
   - [Nested Structures](#nested-structures)
   - [Arrays of Structures](#arrays-of-structures)
   - [Structures & Functions](#structures--functions)
   - [Self-Referential Structure](#self-referential-structure)
4. [Classification of Data Structures](#4-classification-of-data-structures)
5. [Operations on Data Structures](#5-operations-on-data-structures)
6. [Abstract Data Type (ADT)](#6-abstract-data-type-adt)

---

## 📘 1. What is a Data Structure?

**Definition:**  
A data structure is a systematic way of **organizing, storing, and managing data** so it can be used efficiently.

**Think of it like:**  
📚 A library bookshelf — if books are arranged properly, finding becomes easy.

```c
int marks[5] = {45, 67, 88, 56, 92};
````

---

## 🧭 2. Pointers in C

**Definition:**
A pointer is a variable that stores the **memory address** of another variable.

```c
int x = 10;
int *ptr = &x;
printf("x = %d\n", *ptr);
printf("Address of x = %p\n", ptr);
```

---

### 🗃️ Symbol Table & Relative Address

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

---

### ⚫ Null Pointer

```c
int *ptr = NULL;
if (ptr == NULL)
    printf("Pointer is empty!");
```

---

### 🌀 Generic (Void) Pointer

```c
int a = 5;
void *ptr = &a;
printf("%d", *(int *)ptr);
```

---

### 🧩 Pointer to Pointer

```c
int a = 10;
int *p = &a;
int **pp = &p;

printf("%d", **pp);
```

---

## 🧰 3. Structures in C

```c
struct student {
    int roll;
    char name[20];
    float marks;
};
```

```c
struct student s1 = {1, "Dhanush", 92.5};
printf("Name: %s, Marks: %.1f", s1.name, s1.marks);
```

---

### Typedef Declaration

```c
typedef struct {
    int roll;
    char name[20];
} student;

student s1;
```

---

### Accessing Members

```c
s1.roll = 10;
printf("%s", s1.name);
```

---

### Dot vs Arrow Operator

```c
struct Point {
    int x, y;
};

struct Point p, *ptr = &p;

p.x = 5;
ptr->y = 10;
```

---

### Nested Structures

```c
typedef struct { char first[20]; char last[20]; } Name;
typedef struct { int dd, mm, yy; } Date;

typedef struct {
    int id;
    Name name;
    Date dob;
} Student;
```

---

### Arrays of Structures

```c
struct student s[3] = {
    {1, "Aman"},
    {2, "Aryan"},
    {3, "John"}
};
```

---

### Structures & Functions

```c
void update(struct student *s) {
    s->id = 101;
}
update(&s1);
```

---

### Self-Referential Structure

```c
struct node {
    int data;
    struct node *next;
};
```

---

## 🧮 4. Classification of Data Structures

| Type          | Examples            | Description                        |
| ------------- | ------------------- | ---------------------------------- |
| Primitive     | int, char, float    | Built-in data types                |
| Non-Primitive | Array, List, Tree   | Made using primitives              |
| Linear        | Array, Stack, Queue | Sequential arrangement             |
| Non-Linear    | Tree, Graph         | Hierarchical / networked structure |

---

## 🔧 5. Operations on Data Structures

| Operation | Description    |
| --------- | -------------- |
| Insert    | Add data       |
| Delete    | Remove data    |
| Search    | Locate an item |
| Sort      | Arrange data   |
| Merge     | Combine data   |

---

## 🧱 6. Abstract Data Type (ADT)

**Definition:**
ADT = *What operations are allowed*, not *how it works internally*.

Example (Stack):

```c
push();
pop();
```

