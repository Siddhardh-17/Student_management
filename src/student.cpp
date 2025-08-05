#include "../include/student.h"
#include <iostream>
using namespace std;

Student::Student() : id(0), name(""), marks(0), grade("F"), feesPaid(0) {}

void Student::inputDetails() {
    cout << "Enter ID: ";
    cin >> id;
    cin.ignore(); // Clear newline from buffer

    cout << "Enter Name: ";
    getline(cin, name);

    cout << "Enter Marks: ";
    cin >> marks;

    if (marks >= 90)
        grade = "A";
    else if (marks >= 75)
        grade = "B";
    else if (marks >= 60)
        grade = "C";
    else if (marks >= 40)
        grade = "D";
    else
        grade = "F";

    cout << "Enter Fees Paid (out of ₹50000): ";
    cin >> feesPaid;
}

void Student::displayDetails() const {
    cout << "ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Marks: " << marks << endl;
    cout << "Grade: " << grade << endl;
    cout << "Fees Paid: ₹" << feesPaid << endl;
}

int Student::getId() const {
    return id;
}

string Student::getName() const {
    return name;
}

int Student::getMarks() const {
    return marks;
}

string Student::getGrade() const {
    return grade;
}

int Student::getFeesPaid() const {
    return feesPaid;
}

void Student::saveToStream(ostream& os) const {
    os << id << '\n'
       << name << '\n'
       << marks << '\n'
       << grade << '\n'
       << feesPaid << '\n';
}

void Student::loadFromStream(istream& is) {
    is >> id;
    is.ignore();
    getline(is, name);
    is >> marks;
    is.ignore();
    getline(is, grade);
    is >> feesPaid;
}
