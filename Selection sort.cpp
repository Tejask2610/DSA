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

// Selection Sort by Name (Ascending)
void selectionSort(Student s[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (s[j].name < s[minIndex].name)
                minIndex = j;
        }
        swap(s[i], s[minIndex]);
    }
}

int main() {
    const int n = 10;
    Student s[n];

    createDatabase(s, n);

    cout << "\nBefore Sorting:\n";
    display(s, n);

    selectionSort(s, n);

    cout << "\nAfter Selection Sort (by Name Ascending):\n";
    display(s, n);

    return 0;
}
