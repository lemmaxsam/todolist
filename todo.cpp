#include <iostream>
#include <string>
#include <list>
#include <ctime>

using namespace std;

class Task {

    private:

    // attributes
    int id;
    string name;
    bool completed;

    public: 

    Task() : id(0), name(""), completed(false) {}
    ~Task() = default;

    // getting attribute information
    int getID() { return id; }
    string getName() { return name; }
    bool isCompleted() { return completed; }
    void markCompleted(bool value) { completed = value; }

    bool add(string newName) {
        // assigning a number between 1-100
        id = rand() % 100 + 1;
        name = newName;
        return true;
    }

};

int main() {

    list<Task> taskList;
    list<Task>::iterator it;
    char userChoice;
    int inputID;
    string inputName;

    srand(time(NULL));
    taskList.clear();

    while (1) {
        system("clear");

        cout << "Task List Creator: v1\n";
        cout << endl;

        // iterating through tasks
        for (it = taskList.begin(); it != taskList.end(); it++) {
            string completed = it->isCompleted() ? "Completed ;)" : "Incomplete :(";
            cout << it->getID() << " | " << it->getName() << " | " << completed << "\n\n";
        }

        // checking if task list is empty
        if (taskList.empty()) {
            cout << "Task list is currently empty. Add more tasks!\n\n";
        }

        // creating a menu
        cout << "[a]dd a task\n";
        cout << "[c]omplete a task\n";
        cout << "[q]uit the program\n\n";

        // user choice
        cout << "Choice: ";
        cin >> userChoice;
        cout << "\n";

        if (userChoice == 'a') {
            cout << "Add a new task: ";
            cin.clear();
            cin.ignore();
            getline(cin, inputName);
            cout << "\n";

            // creating a new object
            Task newTask;
            newTask.add(inputName);
            taskList.push_back(newTask);

        } else if (userChoice == 'c') {
            cout << "Enter ID of completed task: ";
            cin >> inputID;

            for (it = taskList.begin(); it != taskList.end(); it++) {
                if (inputID == it->getID()) {
                    it->markCompleted(true);
                    break;
                }
            }
        } else if (userChoice == 'q') {
            cout << "Task List Creator is closing!\n";
            break;
        } else {
            // error message isn't staying on screen
            cout << "Option not recognized.\n";
        }
    }

    return 0;
}