
# ☕ JAVA MODULE 1 — Core Concepts + OOP (Complete Notes)

---

## 📘 1. Introduction to Java

### 🧩 Definition
**Java** is an object-oriented, platform-independent programming language developed by *James Gosling* at Sun Microsystems (now owned by Oracle).

### 💡 Concept
Java code is compiled into **bytecode** (not machine code) by the *Java Compiler (javac)*, and executed by the **Java Virtual Machine (JVM)**, making it **Write Once, Run Anywhere (WORA)**.

### ⚙ Example
```java
class Hello {
    public static void main(String[] args) {
        System.out.println("Hello, Java!");
    }
}
````

### 🔑 Key Points

* Platform Independent (via JVM)
* Object-Oriented
* Simple, Secure, Robust
* Multithreaded and Portable

---

## 🧱 2. Basic Structure of a Java Program

```java
class ClassName {
    public static void main(String[] args) {
        // statements
    }
}
```

| Part                   | Description               |
| ---------------------- | ------------------------- |
| `class`                | Keyword to define a class |
| `main()`               | Entry point of program    |
| `System.out.println()` | Prints output to console  |

---

## 🧩 3. Java Tokens

Smallest elements of a program.

### Types:

1. Keywords → `int`, `class`, `if`, `for`, `static`, `void`, etc.
2. Identifiers → names of variables, classes, methods
3. Literals → constants (`10`, `'A'`, `"Hello"`, `true`)
4. Operators → `+`, `-`, `*`, `/`, `=`, `==`, etc.
5. Separators → `;`, `,`, `{}`, `[]`, `()`

---

## 🧮 4. Data Types in Java

| Type      | Category  | Size              | Example      |
| --------- | --------- | ----------------- | ------------ |
| `byte`    | Integer   | 1 byte            | 127          |
| `short`   | Integer   | 2 bytes           | 32767        |
| `int`     | Integer   | 4 bytes           | 10000        |
| `long`    | Integer   | 8 bytes           | 123456789L   |
| `float`   | Floating  | 4 bytes           | 10.5f        |
| `double`  | Floating  | 8 bytes           | 23.45        |
| `char`    | Character | 2 bytes (Unicode) | 'A'          |
| `boolean` | Logical   | 1 bit             | true / false |

---

## 🧾 5. Variables & Constants

### Syntax

```java
datatype variableName = value;
final datatype CONSTANT_NAME = value;
```

### Example

```java
int age = 20;
final double PI = 3.14159;
```

### Key Points

* `final` makes variable constant (value cannot change)
* Variable names must begin with letter or underscore

---

## ⚙ 6. Operators

| Type                  | Example                    |   |    |
| --------------------- | -------------------------- | - | -- |
| Arithmetic            | `+ - * / %`                |   |    |
| Relational            | `== != > < >= <=`          |   |    |
| Logical               | `&&                        |   | !` |
| Assignment            | `= += -= *= /=`            |   |    |
| Increment/Decrement   | `++ --`                    |   |    |
| Conditional (Ternary) | `condition ? true : false` |   |    |

---

## 🧠 7. Input & Output in Java

### Input using Scanner

```java
import java.util.*;

class InputDemo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter name: ");
        String name = sc.nextLine();
        System.out.println("Hello " + name);
    }
}
```

---

## 🔁 8. Control Statements

### a) Conditional

```java
if (condition) { ... }
else if (condition) { ... }
else { ... }
```

### b) Switch

```java
switch (choice) {
    case 1: System.out.println("One"); break;
    case 2: System.out.println("Two"); break;
    default: System.out.println("Invalid");
}
```

### c) Loops

```java
for (int i=1; i<=5; i++)
    System.out.println(i);

while (i<=5) { ... }
do { ... } while (i<=5);
```

---

## 🧩 9. Arrays

### Syntax

```java
datatype[] arr = new datatype[size];
```

### Example

```java
int[] marks = {90, 80, 70};
for (int i : marks)
    System.out.println(i);
```

### Multidimensional

```java
int[][] matrix = { {1,2}, {3,4} };
System.out.println(matrix[1][0]); // 3
```

---

## 🧱 10. Methods (Functions in Java)

### Syntax

```java
returnType methodName(parameters) {
    // code
    return value;
}
```

### Example

```java
int add(int a, int b) {
    return a + b;
}
```

### Calling a method

```java
int sum = add(10, 20);
```

### Key Points

* Methods can return any type
* `void` means no return
* Can be overloaded (same name, different parameters)

---

## 🧰 11. Method Overloading

Same method name, different parameter list (number or type).

```java
class MathOps {
    void add(int a, int b) {
        System.out.println(a + b);
    }
    void add(double a, double b) {
        System.out.println(a + b);
    }
}
```

---

## 🧩 12. Static Keyword

* Belongs to the **class**, not to objects
* Can be accessed without creating an object

```java
class Demo {
    static int count = 0;
    static void show() {
        System.out.println("Static method");
    }
    public static void main(String[] args) {
        Demo.show();
    }
}
```

---

## 🧱 13. Classes and Objects

### Class — blueprint or template

### Object — instance of a class

```java
class Student {
    int id;
    String name;

    void display() {
        System.out.println(id + " " + name);
    }
}

class Main {
    public static void main(String[] args) {
        Student s1 = new Student();
        s1.id = 101;
        s1.name = "Dhanush";
        s1.display();
    }
}
```

---

## 🧠 14. Constructors

Used to initialize objects automatically when created.

### Types

* Default Constructor
* Parameterized Constructor

### Example

```java
class Student {
    int id;
    String name;

    Student(int i, String n) {   // constructor
        id = i;
        name = n;
    }

    void display() {
        System.out.println(id + " " + name);
    }

    public static void main(String[] args) {
        Student s1 = new Student(101, "Aman");
        s1.display();
    }
}
```

---

## 🧱 15. This Keyword

Refers to **current object**.

```java
class Demo {
    int x;
    Demo(int x) {
        this.x = x;   // differentiates between local and instance variable
    }
}
```

---

## 🧩 16. Inheritance (Reusability)

Inheritance allows one class to **acquire properties** of another.

### Syntax

```java
class A {
    void showA() { System.out.println("Class A"); }
}

class B extends A {
    void showB() { System.out.println("Class B"); }
}

class Main {
    public static void main(String[] args) {
        B obj = new B();
        obj.showA();
        obj.showB();
    }
}
```

### Types of Inheritance

* Single
* Multilevel
* Hierarchical
  *(Java does not support multiple inheritance directly — use interfaces)*

---

## 🧩 17. Super Keyword

Used to access parent class members.

```java
class A {
    int x = 10;
}
class B extends A {
    int x = 20;
    void show() {
        System.out.println(super.x); // 10
        System.out.println(x);       // 20
    }
}
```

---

## 🧩 18. Polymorphism

**Poly** = many, **morph** = forms
Means same function behaves differently depending on context.

### Types:

1. **Compile-time** → Method Overloading
2. **Runtime** → Method Overriding

---

## ⚙ 19. Method Overriding (Runtime Polymorphism)

Child class provides its own implementation of a parent class method.

```java
class Animal {
    void sound() { System.out.println("Animal sound"); }
}
class Dog extends Animal {
    void sound() { System.out.println("Bark"); }
}
class Main {
    public static void main(String[] args) {
        Animal a = new Dog();   // Upcasting
        a.sound();              // Bark
    }
}
```

---

## 🧩 20. Encapsulation

Wrapping data (variables) and code (methods) together inside a class.

```java
class Account {
    private int balance = 10000;

    public void setBalance(int amt) {
        balance = amt;
    }
    public int getBalance() {
        return balance;
    }
}
```

### Key Points

* Data Hiding via `private`
* Access through getters/setters

---

## 🧱 21. Abstraction

Showing only essential features, hiding internal details.

### Using Abstract Class

```java
abstract class Shape {
    abstract void draw();  // abstract method
}

class Circle extends Shape {
    void draw() {
        System.out.println("Drawing Circle");
    }
}
```

### Using Interface

```java
interface Vehicle {
    void start();
}

class Bike implements Vehicle {
    public void start() {
        System.out.println("Bike Started");
    }
}
```

---

## 🧩 22. Final Keyword

Used with variable, method, and class:

* Variable → cannot be changed
* Method → cannot be overridden
* Class → cannot be inherited

```java
final class A {}
final int speed = 90;
```

---

## 🧱 23. Packages

A package is a collection of related classes and interfaces.

```java
package mypack;

public class Hello {
    public static void main(String[] args) {
        System.out.println("Package Demo");
    }
}
```

---

## 🧩 24. Exception Handling

Used to handle runtime errors gracefully.

### Syntax

```java
try {
    int a = 10/0;
}
catch (ArithmeticException e) {
    System.out.println("Cannot divide by zero");
}
finally {
    System.out.println("Always executes");
}
```

---

## ⚙ 25. Wrapper Classes

Used to convert primitive data types to objects.

| Primitive | Wrapper   |
| --------- | --------- |
| int       | Integer   |
| char      | Character |
| boolean   | Boolean   |
| float     | Float     |
| double    | Double    |

```java
int x = 10;
Integer obj = Integer.valueOf(x);  // boxing
int y = obj;                       // unboxing
```

---

## 🧩 26. In-built Classes (String, Math, etc.)

### String

```java
String s1 = "Java";
System.out.println(s1.length());
System.out.println(s1.toUpperCase());
```

### Math

```java
System.out.println(Math.sqrt(16));
System.out.println(Math.pow(2,3));
```

---

## 🧩 27. Object Class

All classes in Java implicitly inherit from `Object` class.

| Common Methods | Description               |
| -------------- | ------------------------- |
| `toString()`   | Converts object to string |
| `equals()`     | Compares two objects      |
| `hashCode()`   | Returns hash value        |

---

## 🧠 SUMMARY TABLE

| Concept       | Meaning                 | Keyword/Feature            |
| ------------- | ----------------------- | -------------------------- |
| Class         | Blueprint for objects   | `class`                    |
| Object        | Instance of class       | `new`                      |
| Inheritance   | Reuse code              | `extends`                  |
| Polymorphism  | One name, many forms    | Overloading / Overriding   |
| Encapsulation | Data hiding             | `private`, getters/setters |
| Abstraction   | Hiding internal details | `abstract`, `interface`    |

---

## 🧮 SAMPLE PROGRAMS

### 1️⃣ Simple Class and Object

```java
class Student {
    int id;
    String name;
}
```

### 2️⃣ Constructor Example

```java
class Student {
    int id;
    String name;
    Student(int i, String n) {
        id = i; name = n;
    }
}
```

### 3️⃣ Inheritance Example

```java
class A { void msg(){ System.out.println("A"); } }
class B extends A { void show(){ System.out.println("B"); } }
```

### 4️⃣ Polymorphism Example

```java
class Shape { void draw(){ System.out.println("Draw"); } }
class Circle extends Shape { void draw(){ System.out.println("Circle"); } }
```

---

## ✅ FINAL TAKEAWAYS

* Java = Object-Oriented + Platform Independent
* Everything is inside a class
* Master the 4 pillars: **Encapsulation, Inheritance, Polymorphism, Abstraction**
* Use constructors to initialize
* Use `this` and `super` carefully
* Understand difference between **compile-time** and **runtime polymorphism**

---

# 🏁 END OF MODULE 1 — JAVA BASICS + OOP COMPLETE

```

---

Would you like me to continue this same style for **Module 2 — Advanced Java (Interfaces, Packages, Threads, File Handling, Exception Handling in depth)** next?
```
