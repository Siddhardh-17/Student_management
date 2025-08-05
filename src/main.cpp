// main.cpp
#include "../include/student.h"
#include "../include/admin.h"
#include <iostream>
using namespace std;

int main() {
    Admin admin;
    int choice;
    while (true) {
    cout << "\n==== Student Management Menu ====\n";
    cout << "1. Add Student\n";
    cout << "2. Delete Student by ID\n";
    cout << "3. View All Students\n";
    cout << "4. Save Students to File\n";
    cout << "5. Load Students from File\n";
    cout << "6. Search Student by ID\n";
    cout << "7. Update Student by ID\n";
    cout << "8. Show Total Fees Paid\n";
    cout << "9. Show Fees Due Summary\n";
    cout << "10. Exit\n";
    cout << "11. Generate Fee Receipt\n";
    
    cout << "Enter your choice: ";   // <-- Add this line
    cin >> choice;                   // <-- And this line

    switch (choice) {
        case 1:
            admin.addStudent();
            break;
        case 2: {
            int id;
            cout << "Enter ID to delete: ";
            cin >> id;
            admin.deleteStudentById(id);
            break;
        }
        case 3:
            admin.viewAllStudents();
            break;
        case 4:
            admin.saveToFile("data/students.txt");
            break;
        case 5:
            admin.loadFromFile("data/students.txt");
            break;
        case 6: {
            int id;
            cout << "Enter ID to search: ";
            cin >> id;
            admin.searchStudentById(id);
            break;
        }
        case 7: {
            int id;
            cout << "Enter ID to update: ";
            cin >> id;
            admin.updateStudentById(id);
            break;
        }
        case 8:
            admin.showTotalFeesPaid();
            break;
        case 9:
            admin.showFeesDueSummary();
            break;
        case 10:
            cout << "Exiting program. Goodbye!\n";
            return 0;
        case 11: {
            int id;
            cout << "Enter ID to generate receipt: ";
            cin >> id;
            admin.generateFeeReceipt(id);
            break;
        }

        default:
            cout << "Invalid choice. Please try again.\n";
    }
}
}