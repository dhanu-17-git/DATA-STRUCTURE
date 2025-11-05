# 🧠 Module 1 — Pointers & Data Structure Fundamentals

---

<a name="toc"></a>
## 📑 Table of Contents

1. [What is a Data Structure?](#ds)
2. [Pointers in C](#ptr)

   - [Symbol Table & Relative Address](#symbol)
   - [Pointer Arithmetic](#parith)
   - [Null Pointer](#null)
   - [Generic (Void) Pointer](#voidptr)
   - [Pointer to Pointer](#ptrptr)

3. [Structures in C](#structs)

   - [Typedef Declaration](#typedef)
   - [Accessing Members](#access)
   - [Dot vs Arrow Operator](#dotarrow)
   - [Nested Structures](#nested)
   - [Arrays of Structures](#arraystruct)
   - [Structures & Functions](#funcstruct)
   - [Self-Referential Structure](#selfref)

4. [Classification of Data Structures](#classify)
5. [Operations on Data Structures](#ops)
6. [Abstract Data Type (ADT)](#adt)

---

<a name="ds"></a>
## 📘 1. What is a Data Structure?

A data structure is a systematic way of **organizing, storing, and managing data** efficiently.

```c
int marks[5] = {45, 67, 88, 56, 92};
````

[🔼 Back to Top](#toc)

---

<a name="ptr"></a>

## 🧭 2. Pointers in C

A pointer stores the **memory address** of another variable.

```c
int x = 10;
int *ptr = &x;
printf("x = %d", *ptr);
```

---

<a name="symbol"></a>

### 🗃️ Symbol Table & Relative Address

| Symbol | Type | Address      |
| ------ | ---- | ------------ |
| x      | int  | offset +1003 |

[🔼 Back to Top](#toc)

---

<a name="parith"></a>

### ➕ Pointer Arithmetic

```c
int arr[3] = {10, 20, 30};
int *p = arr;
p++;        // moves to next element
```

---

<a name="null"></a>

### ⚫ Null Pointer

```c
int *ptr = NULL;
```

---

<a name="voidptr"></a>

### 🌀 Generic (Void) Pointer

```c
int a = 5;
void *ptr = &a;
printf("%d", *(int *)ptr);
```

---

<a name="ptrptr"></a>

### 🧩 Pointer to Pointer

```c
int a = 10;
int *p = &a;
int **pp = &p;
```

---

<a name="structs"></a>

## 🧰 3. Structures in C

```c
struct student {
    int roll;
    char name[20];
    float marks;
};
```

---

<a name="typedef"></a>

### ⚙️ Typedef Declaration

```c
typedef struct {
    int roll;
    char name[20];
} student;
```

---

<a name="access"></a>

### ⚙️ Accessing Members

```c
s1.roll = 10;
printf("%s", s1.name);
```

---

<a name="dotarrow"></a>

### 🧭 Dot vs Arrow Operator

```c
struct Point { int x, y; };
struct Point p, *ptr = &p;

ptr->y = 10;
```

---

<a name="nested"></a>

### 🧩 Nested Structures

```c
typedef struct { char first[20]; char last[20]; } Name;
typedef struct { int dd, mm, yy; } Date;
```

---

<a name="arraystruct"></a>

### 📚 Arrays of Structures

```c
struct student s[3] = {
    {1, "Aman"},
    {2, "Aryan"},
    {3, "John"}
};
```

---

<a name="funcstruct"></a>

### ⚙️ Structures & Functions

```c
void update(struct student *s) { s->roll = 100; }
update(&s1);
```

---

<a name="selfref"></a>

### 🔁 Self-Referential Structure

```c
struct node {
    int data;
    struct node *next;
};
```

---

<a name="classify"></a>

## 🧮 4. Classification of Data Structures

| Type       | Examples         |
| ---------- | ---------------- |
| Primitive  | int, char, float |
| Linear     | Array, Stack     |
| Non-linear | Tree, Graph      |

---

<a name="ops"></a>

## 🔧 5. Operations on Data Structures

| Operation | Meaning |
| --------- | ------- |
| Insert    | Add     |
| Delete    | Remove  |
| Search    | Find    |

---

<a name="adt"></a>

## 🧱 6. Abstract Data Type (ADT)

```c
push(); // insert
pop();  // delete
```

---


