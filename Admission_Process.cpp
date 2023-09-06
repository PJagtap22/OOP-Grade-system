//Develop a c++ program to describe the 
//admission process for students at krea Uni

#include <iostream>
#include <string>
#include <iomanip>

//defines the class admissions taking private data members name, age, gpa.
using namespace std;

class Admissions {
    private:
    string name;
    int age;
    float gpa;

    //constructor admissions, initializes these members. If name provided is > 
    // 25 or < 0 the function truncates and displays a message. The substring stores 
    //no. of chars to be entered from 0 to 25
    public:
    Admissions(string n, int a) : name(n), age(a), gpa(0.0) {
    if (n.length() <= 25) {
        name = n;
        } else {
        cout << "Please enter characters between 0 to 25." << endl;
        name = n.substr(0, 25);
         }
    }

    //Using member function bool, checks if student is eligible based on given min gpa.
    //if condition not meet, it displays false result towards the end.
    bool isEligible() {
        return (gpa >= 3.5);
    }
    
    //Using member function CalcGPA, calculates the GPA based on array of grades and the no. of subjects.
    void CalcGPA(float grades[], int num_subjects) {
        float total = 0.0;
        for(int i = 0; i < num_subjects; ++i) {
            total += grades[i];
        }
        gpa = (total/num_subjects)/10;
    }
    
    //displays student information with name, age, gpa with fixed precision on 2 digits.
    void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << fixed << setprecision(2) << "GPA: " << gpa << endl; 
    }
//The Admission class ends here with };
};
//
    int main() {

        //dispay student information
        string name;
        int age, num_subjects;
        float gpa;

        cout << "Welcome to Krea University Adimission process" << endl;

        cout << "Enter Full name: ";
        getline(cin, name);
//ensures that the name is not longer than 25 chars
        if (name.length() > 25) {
            cout << "Invalid! Enter characters between 1 to 25." << endl;
            name = name.substr(0,25);
        }

        cout << "Enter student age: ";
        cin >> age;
//ensure that the age is not less than 17
        while (age < 17) {
            cout << "Invalid! Applicants must be above 17 years. Enter the age: ";
            cin >> age;
        } 

        cout << "Enter the number of subjects: ";
        cin >> num_subjects;

// grades are inputted and stored iin the grades' array.
        float *grades = new float[num_subjects];
        for (int i = 0; i < num_subjects; ++i) 
        {
            cout << "Enter grade for subject " << i+1 << ": ";
            cin >> grades[i];
        }
//Admissions class named student is created with the provided name and age.
            Admissions student(name, age);
            student.CalcGPA(grades, num_subjects);
//CalcGPA function calculates the GPA. student information is displayed by this func below.
            student.displayInfo();    
//Student's eligibility is checked using isEligible() func and appropriate msg is displayed.  
        if (student.isEligible()) {
            cout << "Congratulations! Krea welcomes you to its next round, we will shortly announce your interview dates, stay tuned!" << endl;
        } else {
            cout << "Sorry, you don't meet the eligibility criteria." << endl;
        }
// dynamically allocated grades array is deleted to prevent memory leaks.        
        delete[] grades;
        return 0;
    }


