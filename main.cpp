#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct User {
    int id;
    string name;
};

vector<User> users;

void createUser();
void readUsers();
void updateUser();
void deleteUser();

int main() {
    int choice;

    do {
        cout << "\nCRUD Menu:\n";
        cout << "1. Create User\n";
        cout << "2. Read Users\n";
        cout << "3. Update User\n";
        cout << "4. Delete User\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: createUser(); break;
            case 2: readUsers(); break;
            case 3: updateUser(); break;
            case 4: deleteUser(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid option. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}

void createUser(){
    User newUser;
    cout<<"Enter User ID: ";
    cin >> newUser.id;
    cout<<"Enter User Name: ";
    cin.ignore();
    getline(cin, newUser.name);
    users.push_back(newUser);
    cout<<"User created successfully!\n";          
}
 
void readUsers() {
    if (users.empty()) {
        cout << "No users available.\n";
        return;
    }

    cout << "List of Users:\n";
    for (const auto& user : users) {
        cout << "ID: " << user.id << ", Name: " << user.name << "\n";
    }
}

 
void updateUser(){
	int userId;
    cout << "Enter the ID of the user you want to update: ";
    cin >> userId;

    
    bool found = false;
    for (auto& user : users) {
        if (user.id == userId) {
            found = true;
            cout << "User found! Current name: " << user.name << "\n";
            cout << "Enter new name for the user: ";
            cin.ignore();
            getline(cin, user.name);
            cout << "User updated successfully!\n";
            break;
        }
    }

    if (!found) {
        cout << "User with ID " << userId << " not found.\n";
    }
}
void deleteUser(){
}
