# 🎓 Student Management System (C, Linked List Implementation)

## 📌 Overview
This project is a **Student Management System** written in **C**, designed to manage student records dynamically using **singly linked lists**.  
It provides a simple, console-based interface to perform operations such as **adding, updating, deleting, searching, and displaying student data**.

The project demonstrates:
- **Pointers and Dynamic Memory Allocation**
- **Struct-based Data Representation**
- **Linked List Data Structure**
- **Robust Error and Corner Case Handling**

---

## ✨ Features
- ➕ **Add new student records** (ID, Name, Age, GPA)  
- 🗑 **Delete student records** by ID  
- 🔎 **Search for students** by ID or name  
- ✏ **Update student information**  
- 📋 **Display all student records** in an organized way  
- 🧩 **Helper functions** for modular, reusable code  

---

## 🛡️ Corner Case Handling
To make the system more **robust and reliable**, I implemented explicit handling for edge scenarios:

- **Duplicate Entries**  
  - The program prevents insertion of students with the same ID.  
  - Prints a warning: `ID already exists`.

- **Update / Delete Non-Existent Records**  
  - The program checks if the student exists first.  
  - If not found, it prints: `ID do NOT exist`.  

- **Safe Pointer Management**  
  - The `exist()` helper function ensures null pointers are not dereferenced.  
  - Returns both the current and previous nodes safely.  

- **Input Validation**  
  - A custom `myFlush()` function clears input buffers.  
  - Prevents unintended characters (like `\n`) from breaking input.  

✅ These design choices ensure **data consistency**, avoid **program crashes**, and provide a **smooth user experience**.  

---

## 🛠 Tech Stack
- **Language:** C  
- **Data Structure:** Singly Linked List  
- **IDE/Compiler:** GCC / Eclipse  


