#include "../include/admin.h"
#include <iostream>
#include <fstream>
using namespace std;

void Admin::addStudent() {
    Student s;
    cout << "Enter student details:\n";
    s.inputDetails();
    studentList.push_back(s);
    cout << "Student added successfully!\n";
}

void Admin::deleteStudentById(int id) {
    for (auto it = studentList.begin(); it != studentList.end(); ++it) {
        if (it->getId() == id) {
            studentList.erase(it);
            cout << "Student deleted successfully.\n";
            return;
        }
    }
    cout << "Student with ID " << id << " not found.\n";
}

void Admin::viewAllStudents() const {
    if (studentList.empty()) {
        cout << "No students to display.\n";
        return;
    }
    cout << "\n--- Student Records ---\n";
    for (const auto& s : studentList) {
        s.displayDetails();
        cout << "-----------------------\n";
    }
}

void Admin::saveToFile(const string& filename) const {
    ofstream fout(filename);
    if (!fout) {
        cout << "Error opening file for writing.\n";
        return;
    }

    fout << studentList.size() << '\n';
    for (const auto& s : studentList) {
        s.saveToStream(fout);
    }

    cout << "Data saved to " << filename << endl;
}

void Admin::loadFromFile(const string& filename) {
    ifstream fin(filename);
    if (!fin) {
        cout << "No saved data found. Starting fresh.\n";
        return;
    }

    size_t count;
    fin >> count;
    studentList.clear();

    for (size_t i = 0; i < count; ++i) {
        Student s;
        s.loadFromStream(fin);
        studentList.push_back(s);
    }

    cout << "Loaded " << count << " student records from file.\n";
}

void Admin::searchStudentById(int id) const {
    for (const auto& s : studentList) {
        if (s.getId() == id) {
            cout << "--- Student Found ---\n";
            s.displayDetails();
            return;
        }
    }
    cout << "Student with ID " << id << " not found.\n";
}

void Admin::updateStudentById(int id) {
    for (auto& s : studentList) {
        if (s.getId() == id) {
            cout << "Enter updated details:\n";
            s.inputDetails();
            cout << "Student updated successfully.\n";
            return;
        }
    }
    cout << "Student with ID " << id << " not found.\n";
}

void Admin::showTotalFeesPaid() const {
    int total = 0;
    for (const auto& s : studentList) {
        total += s.getFeesPaid();
    }
    cout << "Total Fees Paid by All Students: ₹" << total << endl;
}

void Admin::showFeesDueSummary() const {
    const int totalFee = 50000; // fixed total fee per student
    cout << "\n--- Fee Dues Summary ---\n";
    for (const auto& s : studentList) {
        int due = totalFee - s.getFeesPaid();
        cout << "ID: " << s.getId() << ", Name: " << s.getName()
             << ", Due: ₹" << due << endl;
    }
}

#include <filesystem> // For directory creation

void Admin::generateFeeReceipt(int id) const {
    for (const auto& s : studentList) {
        if (s.getId() == id) {
            std::filesystem::create_directories("receipts");
            string filename = "receipts/" + to_string(id) + "_receipt.txt";
            ofstream fout(filename);
            if (!fout) {
                cout << "Error creating receipt file.\n";
                return;
            }

            fout << "----- Fee Receipt -----\n";
            fout << "Student ID: " << s.getId() << '\n';
            fout << "Name: " << s.getName() << '\n';
           // fout << "Course: " << s.getCourse() << '\n';
            fout << "Fees Paid: ₹" << s.getFeesPaid() << '\n';
            fout << "Total Fees: ₹30000\n";
            fout << "Balance Due: ₹" << (30000 - s.getFeesPaid()) << '\n';
            fout << "-----------------------\n";

            fout.close();

            cout << "Receipt generated at: " << filename << '\n';
            return;
        }
    }
    cout << "Student with ID " << id << " not found.\n";
}

