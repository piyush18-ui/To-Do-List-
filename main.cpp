#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Todo {
private:
    string task;

public:
    void addTask() {
        ofstream file("todo.txt", ios::app);
        cout << "Enter new task: ";
        cin.ignore();
        getline(cin, task);
        file << task << endl;
        file.close();
        cout << "Task added successfully!\n";
    }

    void viewTask() {
        ifstream file("todo.txt");
        cout << "\nYour Tasks:\n";
        int i = 1;
        while (getline(file, task)) {
            cout << i++ << ". " << task << endl;
        }
        file.close();
    }

    void deleteTask() {
        ifstream file("todo.txt");
        ofstream temp("temp.txt");
        int del, i = 1;
        cout << "Enter task number to delete: ";
        cin >> del;

        while (getline(file, task)) {
            if (i != del)
                temp << task << endl;
            i++;
        }

        file.close();
        temp.close();
        remove("todo.txt");
        rename("temp.txt", "todo.txt");
        cout << "Task deleted successfully!\n";
    }
};

int main() {
    Todo t;
    int choice;

    do {
        cout << "\n--- TO DO LIST ---\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Delete Task\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1: t.addTask(); break;
        case 2: t.viewTask(); break;
        case 3: t.deleteTask(); break;
        case 4: cout << "Exiting...\n"; break;
        default: cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}
