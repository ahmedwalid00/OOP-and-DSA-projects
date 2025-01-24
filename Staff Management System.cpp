#include <iostream>
#include <string.h>
#include <sstream>
using namespace std;
class StaffManagementSystem;
class menu;
//class declarations :
//========================
class EmployeeValidator {
public:
void validate_id(int);
void validate_age(int);
void validate_salary(double);
void validate_name(string);
void validate_role(string);
void validate_address(string);
};
//-------------------------------------------------
class employee {
int id;
int age;
double salary;
string name;
string address;
string role;
public:
int get_id() { return id; }
int get_age() { return age; }
double get_salary() { return salary; }
string get_name() { return name; }
string get_address() { return address; }
string get_role() { return role; }
void set_id(int i) { id = i; }
void set_age(int a) { age = a; }
void set_salary(double s) { salary = s; }
void set_name(string n) { name = n; }
void set_address(string a) { address = a; }
void set_role(string r) { role = r; }
};
//-------------------------------------------------
class InputHandler {
public:
void get_input(int, double, int, string, string, string);
};
//-------------------------------------------------
class OutPutHandler : public employee {
public:
void display_employee_details(employee&);
};
//-------------------------------------------------
class StaffManagementSystem : public OutPutHandler, public EmployeeValidator, public InputHandler
{
static const int max_num_employees = 20;
employee emp[max_num_employees];
int num_employee = 0;
public:
void insert_employee(int, int, double, string, string, string);
void search_employee(int);
void edit_employee_details(int);
void delete_employee(int);
void search_employee_with_high_wage();
};
//-------------------------------------------------
class menu : public StaffManagementSystem, public EmployeeValidator
{
public:
void display_menu();
void select_option();
void execute_option(int);
void exit_system();
};
//-------------------------------------------------
class SalaryCalculator : public menu
{
public :
void calculate_salary(int);
};
//classes definitions :
//======================
void SalaryCalculator :: calculate_salary(int s)
{
}
int salary_year;
salary_year = s * 12 ;
cout << " The salary of the employee per year is : " << salary_year << endl;
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void EmployeeValidator::validate_id(int i_d) {
if (i_d < 0 || i_d >= 100000) {
cout << "Invalid ID, please make sure that the ID doesn't exceed 5 digits" << endl;
}
else
cout << "ID is inserted successfully" << endl;
}
void EmployeeValidator::validate_age(int age_) {
    if (age_ < 20 || age_ > 60) {
        cout << "Invalid age, Employee age should be between 20 - 60" << endl;
    }
    else
        cout << "Age is inserted successfully" << endl;
}

void EmployeeValidator::validate_salary(double salary_) {
    if (salary_ < 5000 || salary_ > 5000000) {
        cout << "Invalid salary, salaries should be between 5000 - 500000" << endl;
    }
    else
        cout << "Salary is inserted successfully" << endl;
}

void EmployeeValidator::validate_name(string n) {
    for (char b : n) {
        if (((b >= 'a' && b <= 'z') || (b >= 'A' && b <= 'Z')))
           {
              cout << "Name is inserted successfully" << endl;
            return;
           }
        else {
            cout << "Invalid name" << endl;
            return; // Exit the function if name is invalid
        }
    }
}

void EmployeeValidator::validate_role(string r) {
    for (char b : r) {
        if (((b >= 'a' && b <= 'z') || (b >= 'A' && b <= 'Z')))
           {
               cout << "Role is inserted successfully" << endl;
               return;
           }

        else {
            cout << "Invalid role" << endl;
            return; // Exit the function if role is invalid
        }
    }
}

void EmployeeValidator::validate_address(string a) {
    for (char b : a) {
        if (((b >= 'a' && b <= 'z') || (b >= 'A' && b <= 'Z')))
           {
               cout << "Address is inserted successfully" << endl;
               return;
           }
        else {
            cout << "Invalid address" << endl;
            return; // Exit the function if address is invalid
        }
    }
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void InputHandler::get_input(int i, double s, int ag, string n, string r, string a) {
cout << "\n\tThis is the inputs that have been retrieved by the user" << endl;
cout << "Name: " << n << endl;
cout << "ID: " << i << endl;
cout << "Salary: " << s << endl;
cout << "Age: " << ag << endl;
cout << "Role: " << r << endl;
cout << "Address: " << a << endl;
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void OutPutHandler::display_employee_details(employee &empl) {
cout << "\tEmployee details" << endl;
cout << "Name: " << empl.get_name() << endl;
cout << "ID: " << empl.get_id() << endl;
cout << "Age: " << empl.get_age() << endl;
cout << "Role: " << empl.get_role() << endl;
cout << "Salary: " << empl.get_salary() << endl;
cout << "Address: " << empl.get_address() << endl;
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void StaffManagementSystem::insert_employee(int i, int a, double s, string n, string aa, string r) {
    if (max_num_employees > num_employee) {
        emp[num_employee].set_id(i);
        emp[num_employee].set_age(a);
        emp[num_employee].set_salary(s);
        emp[num_employee].set_name(n);
        emp[num_employee].set_address(aa);
        emp[num_employee].set_role(r);
        cout << "New employee has been added successfully" << endl;
        num_employee++;
    }
    else if (max_num_employees < num_employee)
        cout << "You have reached the maximum number of employees" << endl;
}

void StaffManagementSystem::search_employee(int idd) {
    bool found = false;
    for (int i = 0; i < num_employee; i++) {
        if (emp[i].get_id() == idd) {
            cout << "Employee with ID: " << idd << " is found." << endl;
           display_employee_details(emp[i]);
            found = true;
            break;
        }
    }
    if (!found)
        cout << "Employee with this ID is not found." << endl;
}

void StaffManagementSystem::edit_employee_details(int idd) {
    for (int i = 0; i < num_employee; i++) {
        if (emp[i].get_id() == idd) {
            int new_id, new_age;
            double new_salary;
            string new_name, new_role, new_address;
            cout << "Enter the new ID: " << endl;
            cin >> new_id;
            validate_id(new_id);
            cout << "Enter the new age: " << endl;
            cin >> new_age;
            validate_age(new_age);
            cout << "Enter the new salary: " << endl;
            cin >> new_salary;
            validate_salary(new_salary);
            cout << "Enter the new name: " << endl;
            cin.ignore();
            getline(cin,new_name);
            validate_name(new_name);
            cout << "Enter the new role: " << endl;
            cin.ignore();
            getline(cin,new_role) ;
            validate_role(new_role);
            cout << "Enter the new address: " << endl;
            cin.ignore();
            getline(cin,new_address) ;
            validate_address(new_address);
            emp[i].set_id(new_id);
            emp[i].set_age(new_age);
            emp[i].set_salary(new_salary);
            emp[i].set_name(new_name);
            emp[i].set_role(new_role);
            emp[i].set_address(new_address);
            cout << "The employee details have been updated successfully" << endl;
            display_employee_details(emp[i]);
            break;
             if((emp[i].get_id() != idd) && (i <= num_employee -1) )
            cout << "This ID is not found" << endl;
        }

    }

}

void StaffManagementSystem::delete_employee(int idd) {
    for (int i = 0; i < num_employee; i++) {
        if (emp[i].get_id() == idd) {
            emp[i].set_id(0);
            emp[i].set_age(0);
            emp[i].set_salary(0);
            emp[i].set_name("");
            emp[i].set_role("");
            emp[i].set_address("");
            cout << "The Employee has been deleted successfully" << endl;
            display_employee_details(emp[i]);
            num_employee--;
            break;
        }
    }
}

void StaffManagementSystem::search_employee_with_high_wage() {
    bool found = false;
    for (int i = 0; i < num_employee; i++) {
        if (emp[i].get_salary() > 20000) {
            cout << emp[i].get_name() << " has a wage higher than 20k" << endl;
            display_employee_details(emp[i]);
            found = true;
        }
    }
    if (!found)
        cout << "No employees have a wage higher than 20k" << endl;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void menu::display_menu() {
    cout << "\tStaff Management System" << endl;
    cout << "\t======================" << endl;
    cout << "[1] Insert employee" << endl;
    cout << "[2] Search for an employee by ID" << endl;
    cout << "[3] Edit employee details" << endl;
    cout << "[4] Delete employee" << endl;
    cout << "[5] Search for an employee with a wage higher than 20k" << endl;
    cout << "[6] Exit" << endl;
}

void menu::select_option() {
    int choice;
    cout << "Choose a number from 1 to 6: " << endl;
    cin >> choice;
    execute_option(choice);
}

void menu::execute_option(int c) {
    EmployeeValidator employee_validator; // Instantiate the validator
    switch (c) {
        case 1: {
            int iddd, agee;
            double salaryy;
            string namee, rolee, addressss;
            bool valid_name = false;
            SalaryCalculator calculate_salary;
            while (!valid_name) {
                cin.ignore();
                cout << "Enter the name of the employee: " << endl;
                getline(cin , namee);
                employee_validator.validate_name(namee); // Use the validator
                valid_name = true; // Assume name is valid
                for (char b : namee) {
                    if (!((b >= 'a' && b <= 'z') || (b >= 'A' && b <= 'Z') || ("\0"))) {
                        valid_name = false; // If any character is invalid, set flag to false
                        break;
                    }
                }
                if (!valid_name) {
                    cout << "Invalid name. Please enter a valid name." << endl;
                    char choice;
                    cout << "Do you want to try again? (Y/N): ";
                    cin >> choice;
                    if (choice != 'Y' && choice != 'y') {
                        cout << "Exiting application..." << endl;
                        exit(0);
                    }
                }
            }
            cout << "Enter the ID of the employee: " << endl;
            cin >> iddd;
            employee_validator.validate_id(iddd); // Use the validator
            cout << "Enter the age of the employee: " << endl;
            cin >> agee;
            employee_validator.validate_age(agee); // Use the validator
            cout << "Enter the role of the employee: " << endl;
            cin.ignore();
            getline(cin,rolee);
            employee_validator.validate_role(rolee); // Use the validator
            cout << "Enter the salary of the employee: " << endl;
            cin >> salaryy;
            employee_validator.validate_salary(salaryy); // Use the validator
            calculate_salary.calculate_salary(salaryy);
            cout << "Enter the address of the employee: " << endl;
            cin.ignore();
            getline(cin,addressss);
            employee_validator.validate_address(addressss); // Use the validator
            insert_employee(iddd, agee, salaryy, namee, addressss, rolee);
            break;
        }
        case 2: {
            int iidd;
            cout << "Enter the ID of the employee: " << endl;
            cin >> iidd;
            search_employee(iidd);
            break;
        }
        case 3: {
            int iiidd;
            cout << "Enter the ID of the employee that you want to edit their details: " << endl;
            cin >> iiidd;
            edit_employee_details(iiidd);
            break;
        }
        case 4: {
            int iiiddd;
            cout << "Enter the ID of the employee that you want to delete: " << endl;
            cin >> iiiddd;
            delete_employee(iiiddd);
            break;
        }
        case 5: {
            search_employee_with_high_wage( );
            break;
        }
        case 6: {
            exit_system();
            break;
        }
        default:
            cout << "Invalid choice, please try again with a number from 1 to 6." << endl;
    }
}


void menu::exit_system() {
    cout << "Thank you for using our system!" << endl;
    exit(0);
}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


int main() {
    menu s;
    while (true) {
        s.display_menu();
        s.select_option();
    }
    return 0;
}
