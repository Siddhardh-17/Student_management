#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>

class Student {
private:
    int id;
    std::string name;
    int marks;
    std::string grade;
    int feesPaid;

public:
    Student();

    void inputDetails();
    void displayDetails() const;

    int getId() const;
    std::string getName() const;
    int getMarks() const;
    std::string getGrade() const;
    int getFeesPaid() const;

    void saveToStream(std::ostream& os) const;
    void loadFromStream(std::istream& is);
};

#endif // STUDENT_H
