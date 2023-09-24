#include <iostream>
#include <string>
#include "ReportCard.h"

using namespace std;

int main() {
        string name;
        int studentID, subject, numSubjects;
        float gpa;

        cout << "Enter student's name: ";
        getline(cin, name);
        cout << "Enter studentID: ";
        cin >> studentID;
        cout << "Enter the number of subjects: ";
        cin >> numSubjects;

        float *subjects = new float[numSubjects];
        for (int i = 0; i < numSubjects; ++i) {
            cout << "Enter score of subject" << i+1 << ": ";
            cin >> subjects[i];
            }

            Student student(name, studentID);
            student.CalcGPA(subjects, numSubjects);
            
        cin.ignore();
        student.displayReportCard();

        if (student.isEligible()) {
            cout << "Pass!" << endl;
        } else {
            cout << "Fail!" << endl;
        }
 
        student.displaySubjectsAndMarks(subjects, numSubjects);

        delete[] subjects;
        return 0;
    }