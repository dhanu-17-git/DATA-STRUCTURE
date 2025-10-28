🧠 Module 1 — Pointers & Data Structure Fundamentals

(C Programming + DSA Basics — Teacher’s Friendly Guide)


---

📘 1. What is a Data Structure?

🧩 Definition

A data structure is a way to store and organize data in memory so that we can use it efficiently.

💡 Concept Explanation

Think of it like a bookshelf.
If you just throw books randomly on the floor, finding one takes forever.
But if you arrange them properly (say, alphabetically), finding one is fast.
That’s what a data structure does for your program.

🧱 Syntax

There’s no fixed syntax — you “build” data structures using arrays, pointers, structs, etc.

⚙️ Example

int marks[5] = {45, 67, 88, 56, 92};  // Array = basic data structure

🔑 Key Points

Organizes data for efficiency

Makes access and updates faster

Examples: Array, Linked List, Stack, Queue, Tree, Graph

Core of algorithms and software logic



---

🧭 2. Pointers in C

🧩 Definition

A pointer is a variable that stores the memory address of another variable.

💡 Concept Explanation

When you create a variable like int x = 10;, memory is reserved for x.
A pointer tells you where that memory is.
It’s like saving someone’s house address so you can visit them later.

🧱 Syntax

data_type *pointer_name;

⚙️ Example

int x = 10;
int *ptr = &x;  // store address of x
printf("x = %d\n", *ptr);  // prints 10
printf("Address of x = %p\n", ptr);

🔑 Key Points

& → gives address

* → gets value stored at address

Used for dynamic memory, arrays, functions, and structures



---

🗃️ Symbol Table & Relative Address

Symbol Table:
Compiler’s secret notebook — it stores each variable’s name, type, and address.

Relative Address:
Instead of full address, it’s the distance from the start of a memory block.

🔹 Example:
int x = 10; → compiler stores:

Symbol	Type	Address

x	int	offset +1003



---

➕ Pointer Arithmetic

Pointers can move around in memory.

int arr[3] = {10, 20, 30};
int *p = arr;

printf("%d\n", *p);   // 10
p++;
printf("%d\n", *p);   // 20

🔑 Rules:

Adding 1 to a pointer moves it by 1 element, not 1 byte.

For int *, it moves by 4 bytes (on 32-bit systems).

*ptr++ = increases pointer, not value. Use (*ptr)++ to increase value.



---

⚫ Null Pointer

Used when pointer has nothing to point to.

int *ptr = NULL;

if (ptr == NULL)
    printf("Pointer is empty!");

🔑 Key:

Prevents accidental access to garbage memory.

Defined in <stdio.h> / <stdlib.h>.



---

🌀 Generic (Void) Pointer

Can point to any data type, but must be typecast before using.

int a = 5;
void *ptr = &a;
printf("%d", *(int *)ptr);

🔑 Key Points

Type-agnostic pointer

Must be cast before dereferencing

Used in general-purpose functions



---

🧩 Pointer to Pointer

A pointer storing another pointer’s address.

int a = 10;
int *p = &a;
int **pp = &p;

printf("%d", **pp);  // 10

🔑 Why?
Useful in 2D arrays, dynamic data, and linked lists.


---

⚠️ Pointer Drawbacks

Pointing to wrong memory = 💀 crash

Uninitialized = “wild” pointer

Hard to debug
→ Use carefully.



---

🧰 3. Structures in C

🧩 Definition

A structure groups variables of different types under one name.

💡 Concept Explanation

Think of a “Student” — name (string), roll (int), marks (float).
You can pack all that in one struct.

🧱 Syntax

struct student {
    int roll;
    char name[20];
    float marks;
};

⚙️ Example

struct student s1 = {1, "Dhanush", 92.5};
printf("Name: %s, Marks: %.1f", s1.name, s1.marks);

🔑 Key Points

Combines multiple data types

Access with . (dot) operator

Memory allocated only when you declare a variable



---

⚙️ Typedef Declaration

Shortcut for naming structures.

typedef struct {
    int roll;
    char name[20];
} student;

student s1;

🔑 Easier to type and cleaner code.


---

🧱 Initialization

struct student s1 = {1, "Aman", 45000.0};

Partial:

struct student s2 = {2, "Aryan"}; // rest auto = 0


---

⚙️ Accessing Members

s1.roll = 10;
printf("%s", s1.name);


---

🧭 Dot vs Arrow Operator

struct Point {
    int x, y;
};

struct Point p, *ptr = &p;

p.x = 5;
ptr->y = 10;

🔹 . = access directly
🔹 -> = access via pointer


---

🧩 Nested Structures

Structure inside another structure.

typedef struct {
    char first[20];
    char last[20];
} Name;

typedef struct {
    int dd, mm, yy;
} Date;

typedef struct {
    int id;
    Name name;
    Date dob;
} Student;

Access:

Student s;
s.name.first = "John";
s.dob.yy = 2002;


---

📚 Arrays of Structures

Multiple records of same structure type.

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


---

⚙️ Structures & Functions

1️⃣ Passing Individual Members

void display(int roll) {
    printf("Roll = %d", roll);
}
display(s1.roll);

2️⃣ Passing Whole Structure

void show(struct student s) {
    printf("%s", s.name);
}

3️⃣ Passing via Pointer

void update(struct student *s) {
    s->id = 101;
}
update(&s1);


---

🔁 Self-Referential Structure

A structure that points to itself — base of linked lists.

struct node {
    int data;
    struct node *next;
};


---

🧮 4. Classification of Data Structures

Type	Examples	Description

Primitive	int, char, float	Basic built-in types
Non-Primitive	Array, List, Tree	Made from primitives
Linear	Array, Stack, Queue	Elements in sequence
Non-Linear	Tree, Graph	Hierarchical or networked



---

🔧 5. Operations on Data Structures

Operation	Meaning	Example

Traverse	Visit all elements	Print all names
Search	Find item	Find roll no. 2
Insert	Add element	Add student
Delete	Remove element	Remove student
Sort	Arrange order	Marks ascending
Merge	Combine data	Two lists → one



---

🧱 6. Abstract Data Type (ADT)

🧩 Definition

An ADT defines what operations can be done, not how they’re implemented.

💡 Concept

Think of a vending machine.
You just press a button (operation), not caring how it gives your drink (implementation).

⚙️ Example — Stack

push();  // add item
pop();   // remove item

Implementation can use array or linked list, user doesn’t care.

🔑 Key Points

Focuses on behavior, not details

Improves modularity

Examples: Stack, Queue, List, Graph
