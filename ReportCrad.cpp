
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Class student is defined. It has private member, name, studentID, 
//subjects(i.e a vector of int) and floating point gpa. 
class Student {
    private:
    string name;
    int studentID;
    vector<int> subjects;
    float gpa;

//public section contains a constructor Student that initializes name,
//studentID, sets gpa to 0.0. 
    public:
    Student(string n, int id) : name(n), studentID(id), gpa(0.0) {}
    
//addsubject, a member function allows to add subject score to subjects.
    void addSubject(int subject) {
        subjects.push_back(subject);
    }

//checks if the function is eligible based on gpa. If gpa >= 3.5 it passes
//otherwise fails    
    bool isEligible() {
        return (gpa >= 3.5);
    }

//calculates GPA based on an array od subject scores and no. of subjects
//It iterates and adds upto score to total, then divides total by no. subjects.   
    void CalcGPA(float subjects[], int numSubjects) {
        float total = 0.0;
        for(int i = 0; i < numSubjects; ++i) {
            total += subjects[i];
        }
        gpa = (total/numSubjects)/10;
    }
    
//Displays the student's report card information including name, studentID, GPA.
    void displayReportCard() const {
        cout << "Report card for " << name << endl;
        cout << "StudentID: " << studentID << endl;
        cout << "GPA: " << gpa << endl;
        
    }

//Display subjects and their corresponding marks.
    void displaySubjectsAndMarks(float subjects[], int numSubjects) const {
        cout << "Subjects and Marks for " << name << endl;
        for(int i=0; i< numSubjects; ++i) {
        cout << "Subject" << i+1 << ":" << subjects[i] << endl;
        }
    }
//end of the 'student' class 
};
//the program starts executing 
//int main declares the variables to store user input for name, studentID, numSubjects.
int main() {
        string name;
        int studentID, subject, numSubjects;
        float gpa;
//prompts the user to input values acc to the commands.
        cout << "Enter student's name: ";
        getline(cin, name);
        cout << "Enter studentID: ";
        cin >> studentID;
        cout << "Enter the number of subjects: ";
        cin >> numSubjects;

//Dynamic memory allocation is used to create an array to store subject scores.        
        float *subjects = new float[numSubjects];
        for (int i = 0; i < numSubjects; ++i) {
            cout << "Enter score of subject" << i+1 << ": ";
            cin >> subjects[i];
            }
//Student class is created using the inputs provided above and the GPA is calculated.
            Student student(name, studentID);
            student.CalcGPA(subjects, numSubjects);
            
        cin.ignore();
        student.displayReportCard();
//report card is displayed.
//Eligibility criteria is checked and printed.          

        if (student.isEligible()) {
            cout << "Pass!" << endl;
        } else {
            cout << "Fail!" << endl;
        }
//Subject marks are displayed.    
        student.displaySubjectsAndMarks(subjects, numSubjects);

//Using Delete[], dynamically allocated memory is released.        
        delete[] subjects;
        return 0;
    }