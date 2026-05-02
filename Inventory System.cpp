
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <windows.h>
using namespace std;

// ========== GLOBAL VARIABLES ==========
int limit;
int countItems = 0;
string* items;
int* quantity;
int* price;

// ========== FUNCTION DECLARATIONS ==========
bool login();
void header();
void printDateTime();
int validateMenuChoice(int min, int max);
void initInventorySystem();

void addInventory();
void viewInventory();
void editInventory();
void deleteInventory();
void searchInventory();
void sortInventory();

void generateInvoice();
float applyDiscount(float total);
void viewInvoices();
void updateInventoryAfterSale(string soldItem, int soldQty);
int extractNumber(string text);
bool isDigitManual(char ch);

// ========== MAIN FUNCTION ==========
int main() {
    system("Color 0A");
    header();

    if (login()) {
        initInventorySystem();

        int choice;
        bool exitProgram = false;

        do {
            system("CLS");
            system("Color 0B");
            header();
            printDateTime();

            cout << "\n========== MAIN MENU ==========\n";
            cout << "1. Add Inventory\n2. View Inventory\n3. Edit Inventory\n4. Delete Inventory\n";
            cout << "5. Search Inventory\n6. Sort Inventory\n";
            cout << "7. Generate Invoice\n8. View Invoices\n9. Exit\n";
            cout << "================================\n";
            cout << "Enter your choice: ";
            choice = validateMenuChoice(1, 9);

            switch (choice) {
                case 1: addInventory(); break;
                case 2: viewInventory(); break;
                case 3: editInventory(); break;
                case 4: deleteInventory(); break;
                case 5: searchInventory(); break;
                case 6: sortInventory(); break;
                case 7: generateInvoice(); break;
                case 8: viewInvoices(); break;
                case 9: cout << "\n👋 Thank you for using the system!\n"; exitProgram = true; break;
            }

            if (!exitProgram) {
                cout << "\nPress Enter to return to menu...";
                cin.ignore();
                cin.get();
            }

        } while (!exitProgram);

        delete[] items;
        delete[] quantity;
        delete[] price;
    } else {
        cout << "\nToo many failed attempts. Exiting program.\n";
    }

    return 0;
}

// ========== MEMBER 1 FUNCTIONS ==========
bool login() {
    const string USERNAME = "admin";
    const string PASSWORD = "admin123";
    string username, password;
    int attempts = 3;

    cout << "\n--- LOGIN MENU ---\n";
    while (attempts--) {
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;

        if (username == USERNAME && password == PASSWORD) {
            cout << "\n✅ Login Successful! Welcome, " << username << "!\n";
            return true;
        } else {
            cout << "\n❌ Invalid username or password. Attempts left: " << attempts << "\n\n";
        }
    }
    return false;
}

void header() {
    cout << "=============================================\n";
    cout << "       INVENTORY MANAGEMENT SYSTEM (C++)     \n";
    cout << "=============================================\n";
}

void printDateTime() {
    time_t t; time(&t);
    cout << "🕒 " << ctime(&t);
}

int validateMenuChoice(int min, int max) {
    int ch;
    cin >> ch;
    while (ch < min || ch > max) {
        cout << "❌ Invalid choice. Enter " << min << "-" << max << ": ";
        cin >> ch;
    }
    cin.ignore();
    return ch;
}

void initInventorySystem() {
    cout << "Enter Inventory Limit: ";
    cin >> limit;
    items = new string[limit];
    quantity = new int[limit];
    price = new int[limit];
}

// ========== MEMBER 2 FUNCTIONS ==========
void addInventory() {
    if (countItems >= limit) {
        cout << "⚠ Inventory Limit Reached!\n";
        return;
    }

    int toAdd;
    cout << "\nHow many items do you want to add? ";
    cin >> toAdd;

    if (countItems + toAdd > limit) {
        cout << "⚠ You can only add " << (limit - countItems) << " more items.\n";
        return;
    }

    for (int i = 0; i < toAdd; i++) {
        cout << "\n--- Item " << (countItems + 1) << " ---\n";
        cout << "Enter Item Name: ";
        cin >> items[countItems];
        cout << "Enter Quantity: ";
        cin >> quantity[countItems];
        cout << "Enter Price: ";
        cin >> price[countItems];
        countItems++;
        cout << "✔ Item Added Successfully!\n";
    }
}

void viewInventory() {
    if (countItems == 0) {
        cout << "\n⚠ Inventory is Empty!\n";
        return;
    }
    cout << "\n--- Inventory List ---\n";
    cout << "Name\tQty\tPrice\n";
    for (int i = 0; i < countItems; i++) {
        cout << items[i] << "\t" << quantity[i] << "\t" << price[i] << endl;
    }
}

void searchInventory() {
    string name;
    cout << "\nEnter Item Name to Search: ";
    cin >> name;
    for (int i = 0; i < countItems; i++) {
        if (items[i] == name) {
            cout << "\n✅ Item Found:\n";
            cout << "Name: " << items[i] << endl;
            cout << "Quantity: " << quantity[i] << endl;
            cout << "Price: " << price[i] << endl;
            return;
        }
    }
    cout << "\n❌ Item Not Found!\n";
}

void editInventory() {
    string name;
    cout << "\nEnter Item Name to Edit: ";
    cin >> name;
    for (int i = 0; i < countItems; i++) {
        if (items[i] == name) {
            cout << "Enter New Quantity: ";
            cin >> quantity[i];
            cout << "Enter New Price: ";
            cin >> price[i];
            cout << "✔ Item Updated Successfully!\n";
            return;
        }
    }
    cout << "\n❌ Item Not Found!\n";
}

void deleteInventory() {
    string name;
    cout << "\nEnter Item Name to Delete: ";
    cin >> name;
    for (int i = 0; i < countItems; i++) {
        if (items[i] == name) {
            for (int j = i; j < countItems - 1; j++) {
                items[j] = items[j + 1];
                quantity[j] = quantity[j + 1];
                price[j] = price[j + 1];
            }
            countItems--;
            cout << "✔ Item Deleted Successfully!\n";
            return;
        }
    }
    cout << "\n❌ Item Not Found!\n";
}

void sortInventory() {
    for (int i = 0; i < countItems - 1; i++) {
        for (int j = i + 1; j < countItems; j++) {
            if (items[i] > items[j]) {
                swap(items[i], items[j]);
                swap(quantity[i], quantity[j]);
                swap(price[i], price[j]);
            }
        }
    }
    cout << "✅ Inventory sorted by name successfully!\n";
}

// ========== MEMBER 3 FUNCTIONS ==========
bool isDigitManual(char ch) {
    return (ch >= '0' && ch <= '9');
}

int extractNumber(string text) {
    int number = 0;
    for (char ch : text) {
        if (isDigitManual(ch))
            number = number * 10 + (ch - '0');
    }
    return number;
}

float applyDiscount(float total) {
    char choice;
    cout << "Apply discount? (y/n): ";
    cin >> choice;
    if (choice == 'y' || choice == 'Y') {
        float discount;
        do {
            cout << "Enter discount percentage (0-100): ";
            cin >> discount;
        } while (discount < 0 || discount > 100);
        total -= total * discount / 100;
        cout << "💸 Discount applied! New Total: " << total << endl;
    }
    return total;
}

void updateInventoryAfterSale(string soldItem, int soldQty) {
    for (int i = 0; i < countItems; i++) {
        if (items[i] == soldItem) {
            if (quantity[i] >= soldQty)
                quantity[i] -= soldQty;
            else
                cout << "⚠ Not enough stock for " << soldItem << "\n";
            return;
        }
    }
}

void generateInvoice() {
    string storeName, storeAddress, storePhone;
    cin.ignore();
    cout << "\nEnter store name: ";
    getline(cin, storeName);
    cout << "Enter store address: ";
    getline(cin, storeAddress);
    cout << "Enter store phone: ";
    getline(cin, storePhone);

    string custName, custPhone;
    cout << "\nEnter customer name: ";
    getline(cin, custName);

    // Validate phone number (11 digits)
    bool valid = false;
    do {
        cout << "Enter 11-digit phone number: ";
        cin >> custPhone;
        valid = (custPhone.length() == 11);
        for (int i = 0; i < (int)custPhone.size() && valid; i++) {
            if (!isDigitManual(custPhone[i])) valid = false;
        }
        if (!valid) cout << "❌ Invalid phone number! Try again.\n";
    } while (!valid);

    int itemCount;
    cout << "\nEnter number of items: ";
    cin >> itemCount;
    cin.ignore();

    // Dynamic memory allocation
    string *itemNames = new string[itemCount];
    int *quantities = new int[itemCount];
    float *prices = new float[itemCount];
    float total = 0;

    for (int i = 0; i < itemCount; i++) {
        cout << "\nEnter item name: ";
        getline(cin, itemNames[i]);

        cout << "Enter quantity (e.g., 2kg or 3pcs): ";
        string qtyText;
        getline(cin, qtyText);
        quantities[i] = extractNumber(qtyText);

        ifstream fin("inventory.txt");
        if (!fin) {
            cout << "❌ Inventory file missing.\n";
            delete[] itemNames;
            delete[] quantities;
            delete[] prices;
            return;
        }

        string name;
        int stock;
        float price;
        bool found = false;

        while (fin >> name >> stock >> price) {
            if (name == itemNames[i]) {
                if (stock >= quantities[i]) {
                    prices[i] = price;
                    total += quantities[i] * price;
                    updateInventoryAfterSale(name, quantities[i]);
                    found = true;
                } else {
                    cout << "⚠ Not enough stock for " << name << "\n";
                    i--;
                }
            }
        }
        fin.close();
        if (!found) {
            cout << "❌ Item not found.\n";
            i--;
        }
    }

    total = applyDiscount(total);

    // Print invoice
    cout << "\n=============================================\n";
    cout << "             " << storeName << "\n";
    cout << "             " << storeAddress << "\n";
    cout << "             Contact: " << storePhone << "\n";
    cout << "---------------------------------------------\n";
    cout << "Date & Time: " << ctime(nullptr);
    cout << "Customer: " << custName << " | Phone: " << custPhone << "\n";
    cout << "---------------------------------------------\n";
    cout << "Item\tQty\tPrice\n";
    cout << "---------------------------------------------\n";
    for (int i = 0; i < itemCount; i++)
        cout << itemNames[i] << "\t" << quantities[i] << "\t" << prices[i] << "\n";
    cout << "---------------------------------------------\n";
    cout << "Total: " << total << "\n";
    cout << "=============================================\n";

    // Save to file
    ofstream fout("invoices.txt", ios::app);
    fout << "\n=============================================\n";
    fout << "             " << storeName << "\n";
    fout << "             " << storeAddress << "\n";
    fout << "             Contact: " << storePhone << "\n";
    fout << "---------------------------------------------\n";
    fout << "Date & Time: " << ctime(nullptr);
    fout << "Customer: " << custName << " | Phone: " << custPhone << "\n";
    fout << "---------------------------------------------\n";
    fout << "Item\tQty\tPrice\n";
    for (int i = 0; i < itemCount; i++)
        fout << itemNames[i] << "\t" << quantities[i] << "\t" << prices[i] << "\n";
    fout << "---------------------------------------------\n";
    fout << "Total: " << total << "\n";
    fout << "=============================================\n";
    fout.close();

    cout << "✅ Invoice saved successfully!\n";

    delete[] itemNames;
    delete[] quantities;
    delete[] prices;
}

void viewInvoices() {
    ifstream fin("invoices.txt");
    if (!fin) {
        cout << "❌ No invoices found.\n";
        return;
    }

    string line;
    cout << "\n========== SAVED INVOICES ==========\n";
    while (getline(fin, line)) {
        cout << line << endl;
    }
    fin.close();
}