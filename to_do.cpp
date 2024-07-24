/*....A small program to save and organize your tasks....*/


#include <iostream>
#include <vector>
#include <string>
using namespace std;
//     ==========...[...The category definition section...]...==========
class Class_ToDoList {
private:
    vector<string> tasks; // list to store task
    vector<string> completedTasks; //list to store completed tasks

public:
    //   .....[...Add a New task...]...
    void addTask(const string& task)
    {
        tasks.push_back(task); // Add the task to the task list
        cout << task << " task added."<<endl;
    }
    //  .....[...Complete a Task...].....
    void completeTask(int index)
    {
        if (index >= 0 && index < tasks.size()) {
            completedTasks.push_back(tasks[index]); // store the completed task into the completedTasks list
            tasks.erase(tasks.begin()+index); //remove the completed task from the tasks
            cout << "task " << index+1 << " completed."<<endl;
        }
        else {
            cout << "Invalid task index" << endl;// Error message for invalid choice
        }
    }
    //  .....[...View all completed tasks...].....
    void viewCompletedTasks()
    {
        if (completedTasks.empty()) {
            cout << "No tasks yet" << endl;// message for no tasks
        }
        else {
            cout << "===== COMPLETED TASKS =====" << endl;
            for (int i = 0; i < completedTasks.size(); ++i) {
                cout << i + 1 << ". " << completedTasks[i] << endl;// display completed tasks with index
            }
        }
    }

    //  .....[...View all uncompleted tasks...].....
    void viewUncompletedTasks(){
        if (tasks.empty()) {
            cout << "No tasks yet" << endl;// message for no tasks
        }
        else {
            cout << "===== CURRENT TASKS =====" << endl;
            for (int i = 0; i < tasks.size(); ++i) {
                cout << i + 1 << ". " << tasks[i] << endl;// display uncompleted tasks with index
            }
        }
    }
};
//....[...Part Two: Main Function Dealing with the user interface...]....
int main() {
    Class_ToDoList To_do_list; // create an interface of the to do list class

    while (true) {
        cout << "\n===== TO-DO LIST =====" << endl;
        cout << "1. Add a Task" <<endl;
        cout << "2. Complete a Task" << endl;
        cout << "3. View  Uncompleted Tasks" << endl;
        cout << "4. View  Completed Tasks" << endl;
        cout << "5. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string task;
                cout << "Enter the task: ";
                cin.ignore(); // ignore the previous input
                getline(cin, task);// read the task from user
                To_do_list.addTask(task);
                break;
            }
            case 2: {
                int index;
                cout << "Enter the index of the task to complete: ";
                cin >> index;
                To_do_list.completeTask(index - 1);// complete a task
                break;
            }
            case 3:
                To_do_list.viewUncompletedTasks(); // view all uncompleted tasks
                break;
            case 4:
                To_do_list.viewCompletedTasks(); // view all completed tasks
                break;
            case 5:
                cout << "Exiting..." << endl;// Exit  the program
                return 0;
            default:
                cout << "Invalid choice" << endl;// message for invalid choice
        }
    }
}
