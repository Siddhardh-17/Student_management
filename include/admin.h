// admin.h
#ifndef ADMIN_H
#define ADMIN_H

#include "student.h"
#include <vector>

class Admin {
private:
    std::vector<Student> studentList;

public:
    void addStudent();
    void deleteStudentById(int id);
    void viewAllStudents() const;
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
    void searchStudentById(int id) const;
    void updateStudentById(int id);
    void showTotalFeesPaid() const;
    void showFeesDueSummary() const;
    void generateFeeReceipt(int id) const;

};

#endif

