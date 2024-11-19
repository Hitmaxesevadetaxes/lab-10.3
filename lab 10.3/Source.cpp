#include <iostream>
#include <string>

using namespace std;

const int MAX_EMPLOYEES = 4; // Максимальна кількість службовців в одному приміщенні

// Структура для зберігання запису телефонного довідника
struct PhoneRecord {
    int phoneNumber;
    int roomNumber;
    string employees[MAX_EMPLOYEES];
    int employeeCount; // Кількість службовців в приміщенні
};

// Функції для роботи з довідником
void displayMenu();
void addRecord(PhoneRecord* records, int& count, int maxCount);
void editRecord(PhoneRecord* records, int count);
void deleteRecord(PhoneRecord* records, int& count);
void searchByPhoneNumber(PhoneRecord* records, int count);
void searchByRoomNumber(PhoneRecord* records, int count);
void searchByEmployeeName(PhoneRecord* records, int count);

int main() {
    int maxRecords;
    cout << "Enter the maximum number of records: ";
    cin >> maxRecords;

    PhoneRecord* records = new PhoneRecord[maxRecords];
    int recordCount = 0; // Поточна кількість записів

    int choice;
    do {
        displayMenu();
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
        case 1: addRecord(records, recordCount, maxRecords); break;
        case 2: editRecord(records, recordCount); break;
        case 3: deleteRecord(records, recordCount); break;
        case 4: searchByPhoneNumber(records, recordCount); break;
        case 5: searchByRoomNumber(records, recordCount); break;
        case 6: searchByEmployeeName(records, recordCount); break;
        case 0: cout << "Exiting program.\n"; break;
        default: cout << "Invalid option. Please try again.\n";
        }
    } while (choice != 0);

    delete[] records; // Звільнення виділеної пам'яті
    return 0;
}

void displayMenu() {
    cout << "\nPhone Directory Menu:\n";
    cout << "1. Add Record\n";
    cout << "2. Edit Record\n";
    cout << "3. Delete Record\n";
    cout << "4. Search by Phone Number\n";
    cout << "5. Search by Room Number\n";
    cout << "6. Search by Employee Name\n";
    cout << "0. Exit\n";
}

void addRecord(PhoneRecord* records, int& count, int maxCount) {
    if (count >= maxCount) {
        cout << "Error: Maximum records reached.\n";
        return;
    }

    cout << "Enter phone number (two-digit): ";
    cin >> records[count].phoneNumber;

    cout << "Enter room number: ";
    cin >> records[count].roomNumber;

    cout << "Enter number of employees in the room (1-4): ";
    cin >> records[count].employeeCount;

    for (int i = 0; i < records[count].employeeCount; i++) {
        cout << "Enter employee " << i + 1 << " name: ";
        cin.ignore();
        getline(cin, records[count].employees[i]);
    }
    count++;
    cout << "Record added successfully.\n";
}

void editRecord(PhoneRecord* records, int count) {
    int phoneNumber;
    cout << "Enter phone number of the record to edit: ";
    cin >> phoneNumber;

    for (int i = 0; i < count; i++) {
        if (records[i].phoneNumber == phoneNumber) {
            cout << "Editing record for phone number " << phoneNumber << ".\n";
            cout << "Enter new room number: ";
            cin >> records[i].roomNumber;

            cout << "Enter new number of employees in the room (1-4): ";
            cin >> records[i].employeeCount;

            for (int j = 0; j < records[i].employeeCount; j++) {
                cout << "Enter employee " << j + 1 << " name: ";
                cin.ignore();
                getline(cin, records[i].employees[j]);
            }
            cout << "Record updated successfully.\n";
            return;
        }
    }
    cout << "Record not found.\n";
}

void deleteRecord(PhoneRecord* records, int& count) {
    int phoneNumber;
    cout << "Enter phone number of the record to delete: ";
    cin >> phoneNumber;

    for (int i = 0; i < count; i++) {
        if (records[i].phoneNumber == phoneNumber) {
            for (int j = i; j < count - 1; j++) {
                records[j] = records[j + 1];
            }
            count--;
            cout << "Record deleted successfully.\n";
            return;
        }
    }
    cout << "Record not found.\n";
}

void searchByPhoneNumber(PhoneRecord* records, int count) {
    int phoneNumber;
    cout << "Enter phone number to search: ";
    cin >> phoneNumber;

    for (int i = 0; i < count; i++) {
        if (records[i].phoneNumber == phoneNumber) {
            cout << "Room Number: " << records[i].roomNumber << endl;
            cout << "Employees: ";
            for (int j = 0; j < records[i].employeeCount; j++) {
                cout << records[i].employees[j] << " ";
            }
            cout << endl;
            return;
        }
    }
    cout << "Record not found.\n";
}

void searchByRoomNumber(PhoneRecord* records, int count) {
    int roomNumber;
    cout << "Enter room number to search: ";
    cin >> roomNumber;

    for (int i = 0; i < count; i++) {
        if (records[i].roomNumber == roomNumber) {
            cout << "Phone Number: " << records[i].phoneNumber << endl;
            return;
        }
    }
    cout << "Record not found.\n";
}

void searchByEmployeeName(PhoneRecord* records, int count) {
    string name;
    cout << "Enter employee name to search: ";
    cin.ignore();
    getline(cin, name);

    for (int i = 0; i < count; i++) {
        for (int j = 0; j < records[i].employeeCount; j++) {
            if (records[i].employees[j] == name) {
                cout << "Phone Number: " << records[i].phoneNumber << ", Room Number: " << records[i].roomNumber << endl;
                return;
            }
        }
    }
    cout << "Employee not found.\n";
}
