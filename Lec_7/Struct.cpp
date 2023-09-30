#include <iostream>

using namespace std;

struct Stu {
    char* first_name = new char[10];
    char* last_name = new char[10];
    int arabic;
    int english;
    int math;
};

Stu setStudentData() {
        cout << "=============Enter Student Data =================== \n";
        Stu student;
        cout << "Enter Student First name \n";
        cin >> student.first_name;
        cout << "Enter Student Last name \n";
        cin >> student.last_name;
        cout << "Enter Student Arabic degree \n";
        cin >> student.arabic;
        cout << "Enter Student English degree \n";
        cin >> student.english;
        cout << "Enter Student Math degree \n";
        cin >> student.math;

    return student;
}

void getStudentData(Stu* student, int size) {
        cout << "\n ============Student Data==============\n";
        for(int i = 0; i < size; i++) {
            cout << "\n ==============Student Data #"<< i+1 << " is:==============\n";
            cout << "First name: ";
            cout << student[i].first_name << endl;
            cout << "Last name: ";
            cout << student[i].last_name << endl;
            cout << "Arabic degree: ";
            cout << student[i].arabic << endl;
            cout << "English degree: ";
            cout << student[i].english << endl;
            cout << "Math degree: ";
            cout << student[i].math << endl;
        }
}

void getStudentAverageGrades(Stu* student, int size) {
    for(int i = 0; i < size; i++) {
        cout << "\n ==============Average grades for Student #"<< i+1 << "==============\n";
        int Avg = 0;
        Avg = student[i].arabic + student[i].english + student[i].math;
        Avg /= 3;
        cout << "is = " << Avg << endl;
    }
}

void getStudentmaxGrade(Stu* student, int size) {
    for(int i = 0; i < size; i++) {
        cout << "\n Max grade for student #"<< i+1 << " is: ";
        int Max = student[i].arabic;
        if(student[i].arabic < student[i].math || student[i].arabic < student[i].english) {
            Max = student[i].math;
            if(student[i].math < student[i].english)
                Max = student[i].english;
        }
        cout << Max << endl;
    }
}

void getStudentinGrade(Stu* student, int size) {
    for(int i = 0; i < size; i++) {
        cout << "\n Min grade for student #"<< i+1 << " is: ";
        int Min = student[i].arabic;
        if(student[i].arabic > student[i].math || student[i].arabic > student[i].english) {
            Min = student[i].math;
            if(student[i].math > student[i].english)
                Min = student[i].english;
        }
        cout << Min << endl;
    }
}




int main() {
    int size;
    cout << "Enter Students numbers \n";
    cin >> size;

    Stu* students = new Stu[size];

    for(int i = 0; i < size; i++) {
        students[i] = setStudentData();
    }

    getStudentData(students, size);

    getStudentAverageGrades(students, size);

    getStudentmaxGrade(students, size);

    getStudentinGrade(students, size);

    delete [] students;


    return 0;
}