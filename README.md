# 📒 Address Book Application in C

## 📌 Project Overview
This project is a menu-driven Address Book application developed using the C programming language.
It allows users to store, search, edit, delete, and view contacts, with data persisted using file handling (CSV format).

The application focuses on real-world contact management, strong input validation, and modular programming,
making it suitable for C programming, Embedded Systems, and interview preparation.

--------------------------------------------------

## 🎯 Objectives
- Implement a real-world Address Book system
- Practice structures, file handling, and modular C
- Ensure data validation and integrity
- Handle duplicate entries and conflicts
- Build a menu-driven CLI application

--------------------------------------------------

## 🧠 Core Concepts Used
- Structures (struct)
- File handling using CSV
- String manipulation
- Input validation
- Modular programming
- Menu-driven control flow

--------------------------------------------------

## 🗂️ Project Structure

AddressBook-C/
├── main.c          - Menu and program flow
├── contact.c       - Core contact operations
├── contact.h       - Structure & function declarations
├── addfile.c       - File save/load logic
├── addfile.h       - File function declarations
└── README.md

--------------------------------------------------

## 📋 Features

➕ Add Contact
- Validates:
  - Name (numbers not allowed)
  - Phone number (exactly 10 digits and must be unique)
  - Email ID (valid format and must be unique)
- Prevents duplicate phone numbers and email IDs

🔍 Search Contact
- Search contacts using:
  - Name
  - Phone number
  - Email ID

👀 View Contacts
- Displays all saved contacts in a clean tabular format

✏️ Edit Contact
- Edit:
  - Name
  - Phone number
  - Email ID
- Handles multiple matching contacts
- Prompts the user to select the correct contact using the phone number

🗑️ Delete Contact
- Deletes contacts safely
- Handles duplicate matches before deletion

💾 File Handling
- Contacts are stored in addressbook.csv
- Data is loaded automatically when the program starts
- Ensures data persistence across multiple executions

--------------------------------------------------

## 🛠️ Compilation & Execution

Compile:
gcc main.c contact.c addfile.c

Run:
./a.out

--------------------------------------------------

## 📥 Data Storage Format

Contacts are stored in CSV format:

5
Name,PhoneNumber,EmailID

- First line  : Number of contacts
- Next lines : Contact details

--------------------------------------------------

## 🧪 Validations Implemented
- Name should not contain digits
- Phone number:
  - Exactly 10 digits
  - Numeric only
  - Must be unique
- Email ID:
  - Must contain @ and .
  - Must be unique
- Handles invalid menu inputs safely

--------------------------------------------------

## 👨‍💻 Author
Sugavelan G  
Electronics and Communication Engineer  
Interested in Embedded Systems & Embedded C
