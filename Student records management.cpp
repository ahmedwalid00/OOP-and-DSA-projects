#include <iostream>
using namespace std;

struct student {
    int id;
    string name;
    float gpa;

    student() {}

    student(int i, string n, float g) {
        id = i;
        name = n;
        gpa = g;
    }
};

struct Node {
    student* st;
    Node* left;
    Node* right;

    Node(student* s) {
        st = s;
        left = nullptr;
        right = nullptr;
    }
};

class BTS {
    Node* root;

public:
    BTS() : root(nullptr) {}

    void Insert(student* s) {
        root = insert_node(root, s);
    }

    Node* insert_node(Node* r, student* s) {
        if (r == nullptr) {
            return new Node(s);
        }

        if (r->st->id < s->id) {
            r->right = insert_node(r->right, s);
        } else if (r->st->id > s->id) {
            r->left = insert_node(r->left, s);
        }

        return r;
    }

    bool Search(int item) {
        Node* temp = search_node(root, item);
        return temp != nullptr;
    }

    Node* search_node(Node* r, int value) {
        if (r == nullptr) {
            return nullptr;
        }

        if (r->st->id < value) {
            return search_node(r->right, value);
        } else if (r->st->id > value) {
            return search_node(r->left, value);
        } else {
            return r;
        }
    }

    void delete_item(student* item) {
        root = Delete(root, item);
    }

    Node* Delete(Node* r, student* item) {
        if (r == nullptr) {
            return r;
        }

        if (r->st->id < item->id) {
            r->right = Delete(r->right, item);
        } else if (r->st->id > item->id) {
            r->left = Delete(r->left, item);
        } else {
            if (r->left == nullptr) {
                Node* temp = r->right;
                delete r->st;
                delete r;
                return temp;
            } else if (r->right == nullptr) {
                Node* temp = r->left;
                delete r->st;
                delete r;
                return temp;
            } else {
                student* pred = Get_predecessor(r->left);
                r->st = pred;
                r->left = Delete(r->left, pred);
            }
        }
        return r;
    }

    student* Get_predecessor(Node* r) {
        while (r && r->right != nullptr) {
            r = r->right;
        }
        return r->st;
    }

    void inorder_display(Node* r) {
        if (r != nullptr) {
            inorder_display(r->left);
            cout << "Name: " << r->st->name << endl;
            cout << "ID: " << r->st->id << endl;
            cout << "GPA: " << r->st->gpa << endl;
            inorder_display(r->right);
        }
    }

    void display() {
        inorder_display(root);
    }
};

int main() {
    BTS bst;
    int choice;
    int id;
    string name;
    float gpa;

    do {
        cout << "\nStudent Record Management System\n";
        cout << "1. Insert a Student\n";
        cout << "2. Search a Student by ID\n";
        cout << "3. Delete a Student by ID\n";
        cout << "4. Display all Students\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter student ID: ";
                cin >> id;
                cin.ignore();
                cout << "Enter student name: ";
                getline(cin, name);
                cout << "Enter student GPA: ";
                cin >> gpa;

                student* newStudent = new student(id, name, gpa);
                bst.Insert(newStudent);
                cout << "Student inserted successfully!\n";
                break;
            }

            case 2: {
                cout << "Enter student ID to search: ";
                cin >> id;

                if (bst.Search(id)) {
                    cout << "Student found!\n";
                } else {
                    cout << "Student not found!\n";
                }
                break;
            }

            case 3: {
                cout << "Enter student ID to delete: ";
                cin >> id;

                student* studentToDelete = new student(id, "", 0.0);
                bst.delete_item(studentToDelete);
                delete studentToDelete;
                cout << "Student deleted successfully \n";
                break;
            }

            case 4: {
                cout << "\nDisplaying all students:\n";
                bst.display();
                break;
            }

            case 5: {
                cout << "Exiting the program. Goodbye!\n";
                break;
            }

            default:
                cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}
