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

// Linear Search by Name
void linearSearch(Student s[], int n, string key) {
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (s[i].name == key) {
            cout << "\nRecord Found:\n";
            cout << s[i].roll << "\t" << s[i].name << "\t" << s[i].sgpa << endl;
            found = true;
        }
    }
    if (!found)
        cout << "\nRecord Not Found!\n";
}

int main() {
    const int n = 10;
    Student s[n];

    createDatabase(s, n);

    cout << "\nStudent Database:\n";
    display(s, n);

    string key;
    cout << "\nEnter Name to search: ";
    cin >> key;

    linearSearch(s, n, key);

    return 0;
}
