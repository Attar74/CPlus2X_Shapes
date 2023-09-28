#include <iostream>
using namespace std;

void AVG(float ** grades, int studentArrSize, int subjectArrSize) {
    for(int i=0;i<studentArrSize;i++) {
        cout << "Avg for student: " << i+1 <<" is: ";
        float sum = 0;
        for(int j=0; j < subjectArrSize; j++) {
            sum+= grades[i][j];
        }
        cout << "Avg: " <<  (float) sum/subjectArrSize << endl;
    }
}

void theFirstStudent(float ** grades, int studentArrSize, int subjectArrSize) {
    float maxGrades = 0;
    float minGrades = 0;
    int oneStStudent = 0;
    int lastStStudent = 0;
    for(int i=0;i<studentArrSize;i++) {
        float sum = 0;
        for(int j=0; j < subjectArrSize; j++) {
            sum+= grades[i][j];
        }
        if(sum > maxGrades) {
            maxGrades = sum;
            oneStStudent = i;
        }
        if (i == 0 || minGrades > sum) {
            minGrades = sum;
            lastStStudent = i;
        }
    }
    cout << "The max grades is: " <<  maxGrades << " ,For student number "<< oneStStudent+1 << endl;
    cout << "The min grades is: " <<  minGrades << " ,For student number "<< lastStStudent+1 << endl;
}

void maxMInSubject(float ** grades, int studentArrSize, int subjectArrSize) {
    for(int i = 0; i < studentArrSize; i++) {

        float maxSubject = 0;
        float minSubject = 0;
        for(int j = 0; j < subjectArrSize; j++) {
            if(j==0 || grades[i][j] < minSubject) {
                minSubject = grades[i][j];
            }
            if(grades[i][j] > maxSubject) {
                maxSubject = grades[i][j];
            }
        }
        cout << "//////////////////// \n";
        cout << "Max subject grade for student number " << i << " is: " << maxSubject << endl;
        cout << "Min subject grade for student number " << i << " is: " << minSubject << endl;
        cout << "//////////////////// \n";
    }
}
int main () {
    cout << "Enter number of students \n";
    int studentArrSize;
    cin >> studentArrSize;

    cout << "Enter number of Subjects per student \n";
    int subjectArrSize;
    cin >> subjectArrSize;

    float** grades = new float * [studentArrSize];

    for(int i=0;i<studentArrSize;i++) {
        grades[i] = new float [subjectArrSize];
    }
    for(int i=0;i<studentArrSize;i++) {
        cout << "Please enter the " << subjectArrSize << " grades of student separated by space number " << i+1 << endl;
        for(int j=0; j < subjectArrSize; j++) {
            cin >> grades[i][j];
        }
    }

    cout << "/********** the students Avg Grades ********/\n";
    AVG(grades, studentArrSize, subjectArrSize);
    cout << "/****************************/ \n\n";

    cout << "/********** the max and min grade students ********/ \n";
    theFirstStudent(grades, studentArrSize, subjectArrSize);
    cout << "/****************************/ \n\n";

    cout << "/********** the max and min subjects for every students ********/ \n";
    maxMInSubject(grades, studentArrSize, subjectArrSize);
    cout << "/****************************/ \n\n";

    for(int i=0;i<studentArrSize;i++) {
        delete [] grades[i];
    }
    delete [] grades;

    return 0;
}