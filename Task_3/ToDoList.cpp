#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

void printMain() {
	cout << "\n\n\n========================================================================\n\n";
	cout << "Selections:\n1. for New Task\n2. to Display List\n3. to Delete Task\n0. to Exit Code\n\n";
	cout << "========================================================================\n\n";
}

int main()
{
	int choice, Priority;
	string Task;

	vector<pair<int, string>> ToDoList;
	int n = ToDoList.size(), pCount = 0;

	while (true) {
		printMain();
		cout << "Enter Selection: ";
		cin >> choice;
		cin.ignore(); // Clear the newline character from the input buffer

		switch (choice)
		{
		case 1:
			cout << "Enter Task: ";
			getline(cin, Task);

			do {
				cout << "Select Priority\n Low(1)\t\tMedium(2)\tHigh(3)\nPriority: ";
				cin >> Priority;
				cin.ignore(); 

			} while (Priority < 1 || Priority > 3);

			ToDoList.push_back(make_pair(Priority, Task));

			break;
		case 2:
			std::sort(ToDoList.begin(), ToDoList.end());
			pCount = -1; 
			for (int i = 0; i < ToDoList.size(); i++) {
				if (ToDoList[i].first == 1 && pCount < 0) {
					pCount = 0;
					cout << "========================================================================\n\n";
					cout << "Low Priority Tasks\n";
				}
				else if (ToDoList[i].first == 2 && pCount < 1) {
					pCount = 1;
					cout << "========================================================================\n\n";
					cout << "Medium Priority Tasks\n";
				}
				else if (ToDoList[i].first == 3 && pCount < 2) {
					pCount = 2;
					cout << "========================================================================\n\n";
					cout << "High Priority Tasks\n";
				}

				cout << "Task ID: " << i << "\nTask: " << ToDoList[i].second << "\n\n";
			}

			break;
		case 3:
			cout << "Enter Task ID to Delete: ";
			cin >> choice;
			cin.ignore(); 
			if (choice >= 0 && choice < ToDoList.size()) {
				ToDoList.erase(ToDoList.begin() + choice);
				cout << "Task Deleted\n";
			}
			else {
				cout << "Invalid Task ID\n";
			}
			break;
		case 0:
			cout << "Exiting...\n";
			return 0;
		default:
			cout << "Invalid Selection, try again\n";
			break;
		}
	}
}
