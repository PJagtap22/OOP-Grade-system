
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student
{
private:
    string name;
    int studentID;
    vector<int> subjects; //"vector<int>" dynamic array that automatically manages memory allocation
    float gpa;

public:
    Student(const string &n, int id) : name(n), studentID(id), gpa(0.0) {} //pointer used for reference

    void addSubject(int subject)
    {
        subjects.push_back(subject);
    }
    // addsubject, a member function allows to add subject score to subjects.

    bool isEligible()
    {
        return (gpa >= 3.5);
    }

    void CalcGPA(float subjects[], int numSubjects)
    {
        float total = 0.0;
        for (int i = 0; i < numSubjects; ++i)
        {
            total += subjects[i];
        }
        gpa = (total / numSubjects) / 10;
    }
    // This function calculates GPA based on an array of subject scores and no. of subjects
    // It iterates and adds upto score to total, then divides total by no. subjects.

    void displayReportCard() const
    {
        cout << "Report card for " << name << endl;
        cout << "StudentID: " << studentID << endl;
        cout << "GPA: " << gpa << endl;
    }
    // Display subjects and their corresponding marks.
    void displaySubjectsAndMarks(float subjects[], int numSubjects) const
    {
        cout << "Subjects and Marks for " << name << endl;
        for (int i = 0; i < numSubjects; ++i)
        {
            cout << "Subject" << i + 1 << ":" << subjects[i] << endl;
        }
    }
};
// the program starts executing
// int main declares the variables to store user input for name, studentID, numSubjects.
int main()
{
    string name;
    int studentID, subject, numSubjects;
    float gpa;

    // prompts the user to input values acc to the commands.
    cout << "Enter student's name: ";
    getline(cin, name);
    cout << "Enter studentID: ";
    cin >> studentID;
    cout << "Enter the number of subjects: ";
    cin >> numSubjects;

    // Dynamic memory allocation is used to create an array to store subject scores.
    float *subjects = new float[numSubjects]; //Pointer used to refer to subjects 

    for (int i = 0; i < numSubjects; ++i)
    {
        cout << "Enter score of subject" << i + 1 << ": ";
        cin >> subjects[i];
    }
    // Student class is created using the inputs provided above and the GPA is calculated.
    Student student(name, studentID);
    student.CalcGPA(subjects, numSubjects);

    cin.ignore();
    student.displayReportCard();

    if (student.isEligible())
    {
        cout << "Pass!" << endl;
    }
    else
    {
        cout << "Fail!" << endl;
    }

    student.displaySubjectsAndMarks(subjects, numSubjects);

    // Using Delete[], dynamically allocated memory is released.
    delete[] subjects;
    return 0;
}
