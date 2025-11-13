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

// Sort by Roll Number (Ascending)
void sortByRoll(Student s[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (s[j].roll > s[j + 1].roll)
                swap(s[j], s[j + 1]);
        }
    }
}

// Binary Search by Roll Number
void binarySearch(Student s[], int n, int key) {
    int low = 0, high = n - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (s[mid].roll == key) {
            cout << "\nRecord Found:\n";
            cout << s[mid].roll << "\t" << s[mid].name << "\t" << s[mid].sgpa << endl;
            return;
        } else if (key < s[mid].roll)
            high = mid - 1;
        else
            low = mid + 1;
    }
    cout << "\nRecord Not Found!\n";
}

int main() {
    const int n = 10;
    Student s[n];

    createDatabase(s, n);

    cout << "\nBefore Sorting:\n";
    display(s, n);

    sortByRoll(s, n);

    cout << "\nAfter Sorting (by Roll Number):\n";
    display(s, n);

    int key;
    cout << "\nEnter Roll Number to search: ";
    cin >> key;

    binarySearch(s, n, key);

    return 0;
}
