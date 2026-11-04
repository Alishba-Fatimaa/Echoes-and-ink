# Echoes & Ink
### A Personal Digital Journaling Application

Echoes & Ink is a digital journaling project developed to provide a space for recording, organising and managing personal thoughts, reflections and memories.

Originally developed as a C++ Object-Oriented Programming project, it focuses on applying core OOP principles, structured data management and file handling. The project was later extended with a web-based interface to present the journaling experience in a more interactive and accessible format.

**Live Web Application:** https://echoes-and-ink.lovable.app/

---
##  Preview
(screenshots/login-page.png)


(screenshots/dashboard.png)


(screenshots/journal-entry.png)


---

## Project Overview

The project consists of two implementations:

1. **C++ Console Application:** The original academic implementation, demonstrating Object-Oriented Programming, class relationships, data management and file handling.
2. **Web Application:** A graphical implementation providing an interactive interface for managing journal entries.

## 1. C++ Implementation — Object-Oriented Programming

The original application was developed in C++ with an emphasis on applying the four fundamental principles of Object-Oriented Programming.

### Core OOP Concepts

| Concept | Implementation |
|---|---|
| Encapsulation | Private data members and public getter functions are used to control access to entry information. |
| Abstraction | An abstract `User` class defines essential operations through pure virtual functions. |
| Inheritance | `DiaryUser` publicly inherits from `User` and implements its functionality. |
| Runtime Polymorphism | Virtual function overriding allows derived-class behaviour through base-class references. |
| Compile-time Polymorphism | Constructor overloading in the `Entry` class provides multiple ways to initialise objects. |

### Class Structure

| Class | Description |
|---|---|
| `Entry` | Represents an individual journal entry and its attributes. |
| `Diary` | Manages the collection of journal entries and file operations. |
| `User` | Abstract base class defining user authentication operations. |
| `DiaryUser` | Derived class implementing the user operations. |

### Features

- User registration and login.
- Add, view, edit and delete journal entries.
- Mark entries as favourites.
- Password-protected secret vault.
- Search entries using keywords.
- Mood-based statistics.
- View saved journal entries.
- Daily inspirational quotes.

### Data Handling and File Management

File handling is used to maintain application data between program executions.

- `fstream`, `ifstream` and `ofstream` for reading and writing files.
- `diary.txt` for storing journal entries.
- `users.txt` for storing user account information.
- `vector<Entry>` for managing a dynamic collection of journal entries.
- `ctime` for date and time information.

These mechanisms demonstrate basic data persistence and the management of structured information in a C++ application.

---

## 2. Web Application — Interactive Interface

The web implementation extends the original journaling concept through a graphical interface.

### Features

- User registration and sign-in interface.
- Create and manage journal entries.
- Edit and delete existing entries.
- Organise entries by mood and category.
- Mark entries as favourites.
- Search journal entries.
- Manage secret entries.
- View mood statistics.

### Technology Stack

- React
- TypeScript
- Tailwind CSS
- Vite
- Browser Local Storage

The web interface was developed with assistance from Lovable, an AI-assisted application development platform. Its generated source code was reviewed and customised as part of the web implementation.

---



## 3. Learning Outcomes

This project provided practical exposure to:

- Applying encapsulation, abstraction, inheritance and polymorphism.
- Designing classes and defining relationships between objects.
- Implementing virtual functions and constructor overloading.
- Managing collections using vectors.
- Performing file input and output operations.
- Understanding data persistence.
- Exploring component-based web development.
- Working with React and TypeScript.
- Understanding browser-based data storage.
- Using AI-assisted development tools in an application development workflow.

