#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
using namespace std;
class Student
{
private:
    string name;
    int studentID;
    vector<int> subjects;
    float gpa;

public:
    Student(string n, int id) : name(n), studentID(id), gpa(0.0) {}

    void addSubject(int subject);

    bool isEligible();

    void CalcGPA(float subjects[], int numSubjects);

    void displayReportCard() const;

    void displaySubjectsAndMarks(float subjects[], int numSubjects) const;
};

#endif