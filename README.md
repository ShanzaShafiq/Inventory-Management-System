
# 📦 Inventory Management System (C++)

A console-based Inventory Management System built in C++ that allows users to efficiently manage products, generate invoices, and track stock using file handling and dynamic memory allocation.


## 🚀 Features

- 🔐 Secure Login System (Admin authentication)
- 📦 Add, View, Edit, and Delete Inventory Items
- 🔍 Search and Sort Inventory
- 🧾 Generate Customer Invoices
- 💾 Persistent Data Storage using Files (`inventory.txt`, `invoices.txt`)
- 📉 Automatic Stock Update after Sales
- 💸 Discount System for Invoices
- 🕒 Real-time Date & Time display
- ✔ Input validation (phone number, quantities, etc.)

---

## 🛠️ Technologies Used

- C++
- File Handling (`fstream`)
- Dynamic Memory Allocation (`new/delete`)
- Standard Template Library (STL - string, time)

---

## 📁 Project Structure

```

Inventory System
│
├── merge.cpp            # Main source code
├── inventory.txt        # Stores inventory data
├── invoices.txt         # Stores generated invoices
└── README.md            # Project documentation

````

---

## ⚙️ How to Run

### 1. Compile the program:
```bash
g++ merge.cpp -o inventory.exe
````

### 2. Run the executable:

```bash
./inventory.exe
```

---

## 🔑 Default Login

```
Username: admin
Password: admin123
```

---

## 📊 How It Works

1. Login to system
2. Add inventory items
3. Manage stock (edit/delete/search/sort)
4. Generate invoice for customers
5. System automatically updates stock & saves data

---

## 🎯 Future Improvements

* Database integration (MySQL)
* Role-based authentication (Admin / Staff)
* Barcode scanning system
* Cloud backup for inventory data

---

## 👨‍💻 Developer Notes

This project demonstrates:

* Real-world inventory system logic
* File handling in C++
* Dynamic memory usage
* Structured programming approach


```

