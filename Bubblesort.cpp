#include <iostream>
#include <string>
using namespace std;

struct Student {
    int roll;
    string name;
    float sgpa;
};

// Function to create database of 10 students
void createDatabase(Student s[], int n) {
    cout << "\nEnter details of " << n << " students:\n";
    for (int i = 0; i < n; i++) {
        cout << "\nStudent " << i + 1 << ":\n";
        cout << "Roll No: ";
        cin >> s[i].roll;
        cout << "Name: ";
        cin >> s[i].name;
        cout << "SGPA: ";
        cin >> s[i].sgpa;
    }
}

// Display function
void display(Student s[], int n) {
    cout << "\nRoll No\tName\tSGPA\n";
    for (int i = 0; i < n; i++) {
        cout << s[i].roll << "\t" << s[i].name << "\t" << s[i].sgpa << endl;
    }
}

// Bubble Sort by SGPA (Descending)
void bubbleSort(Student s[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (s[j].sgpa < s[j + 1].sgpa) {
                swap(s[j], s[j + 1]);
            }
        }
    }
}

int main() {
    const int n = 10;
    Student s[n];

    createDatabase(s, n);

    cout << "\nBefore Sorting:\n";
    display(s, n);

    bubbleSort(s, n);

    cout << "\nAfter Bubble Sort (by SGPA Descending):\n";
    display(s, n);

    return 0;
}
