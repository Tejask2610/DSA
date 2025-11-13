#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

// Function to check if stack is empty
int isEmpty() {
    return (top == NULL);
}

// Function to check if stack is full
int isFull() {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    if (temp == NULL)
        return 1;  // Memory not available → Stack Full
    else {
        free(temp);
        return 0;
    }
}

// Push function
void push(int val) {
    if (isFull()) {
        cout << "\nStack Overflow (No memory available)\n";
        return;
    }
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = val;
    new_node->next = top;
    top = new_node;
}

// Pop function
void pop() {
    if (isEmpty()) {
        cout << "\nStack Underflow\n";
    } else {
        cout << "\nThe popped element is: " << top->data << endl;
        top = top->next;
    }
}

// Peek function
void peek() {
    if (isEmpty()) {
        cout << "\nStack is empty\n";
    } else {
        cout << "\nTop element is: " << top->data << endl;
    }
}

// Display function
void display() {
    struct Node* ptr;
    if (isEmpty()) {
        cout << "\nStack is empty\n";
    } else {
        ptr = top;
        cout << "\nStack elements are: ";
        while (ptr != NULL) {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }
}

// Main method
int main() {
    int choice, val;

    while (1) {
        cout << "\n--- Stack Menu ---";
        cout << "\n1. Push";
        cout << "\n2. Pop";
        cout << "\n3. Peek";
        cout << "\n4. Display";
        cout << "\n5. Check if Empty";
        cout << "\n6. Check if Full";
        cout << "\n7. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> val;
                push(val);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                if (isEmpty())
                    cout << "\nStack is Empty\n";
                else
                    cout << "\nStack is Not Empty\n";
                break;

            case 6:
                if (isFull())
                    cout << "\nStack is Full (Memory not available)\n";
                else
                    cout << "\nStack is Not Full\n";
                break;

            case 7:
                exit(0);

            default:
                cout << "\nInvalid Choice!\n";
        }
    }

    return 0;
}
