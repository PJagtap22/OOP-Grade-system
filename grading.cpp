
#include <iostream>
#include <string>
#include <vector>
#include "ReportCard.h"

using namespace std;

Student::Student(string n, int id) : name(n), studentID(id), gpa(0.0) {}

void Student::addSubject(int subject)
{
    subjects.push_back(subject);
}

bool Student::isEligible()
{
    return (gpa >= 3.5);
}

void Student::CalcGPA(float subjects[], int numSubjects)
{
    float total = 0.0;
    for (int i = 0; i < numSubjects; ++i)
    {
        total += subjects[i];
    }
    gpa = (total / numSubjects) / 10;
}

void Student::displayReportCard() const
{
    cout << "Report card for " << name << endl;
    cout << "StudentID: " << studentID << endl;
    cout << "GPA: " << gpa << endl;
}

void Student::displaySubjectsAndMarks(float subjects[], int numSubjects) const
{
    cout << "Subjects and Marks for " << name << endl;
    for (int i = 0; i < numSubjects; ++i)
    {
        cout << "Subject" << i + 1 << ":" << subjects[i] << endl;
    }
}
// end of the 'student' class
