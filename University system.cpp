#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <string>
using namespace std;

// Forward declaration of classes :
class student;
class course;
class user;
class validation;

// Class Definitions :
// Validation class
class validation {
public:
    void validate_string(string name);
    void validate_password(int pass);
};

void validation::validate_string(string name) {
    string check_name;
    char check;
    if (name.empty()) {
        cout << "Invalid name, if you want to sign your name again press 'y', and if you want to exit press any button" << endl;
        cin >> check;
        if ((check == 'y') || (check == 'Y')) {
            cout << "User Name: " << endl;
            cin.sync();
            getline(cin, check_name);
            for (char ch : check_name) {
                if (!(ch >= 'A' && ch <= 'Z') && !(ch >= 'a' && ch <= 'z')) {
                    cout << "Invalid Name" << endl;
                    exit(0);
                }
            }
            cout << "Your name is inserted successfully" << endl;
            name = check_name;
        } else
            exit(0);
    }

    for (char ch : name) {
        if (!(ch >= 'A' && ch <= 'Z') && !(ch >= 'a' && ch <= 'z')) {
            cout << "Invalid name, if you want to sign your name again press 'y', and if you want to exit press any button" << endl;
            cin >> check;
            if ((check == 'y') || (check == 'Y')) {
                cout << "User Name: " << endl;
                cin.sync();
                getline(cin, check_name);
                for (char ch : check_name) {
                    if (!(ch >= 'A' && ch <= 'Z') && !(ch >= 'a' && ch <= 'z')) {
                        cout << "Invalid Name" << endl;
                        exit(0);
                    }
                }
                cout << "Your name is inserted successfully" << endl;
                name = check_name;
            } else
                exit(0);
        }
    }
}

void validation::validate_password(int pass) {
    int check_password;
    char check;
    if (!(pass <= 9999) && !(pass >= 1000)) {
        cout << "Invalid Password or ID, if you want to sign your password or ID again press 'y', and if you want to exit press any button" << endl;
        cin >> check;
        if (check == 'y' || check == 'Y') {
            cout << "Password or ID: " << endl;
            cin >> check_password;
            if (!(check_password <= 9999) && !(check_password >= 1000)) {
                cout << "Invalid Password or ID" << endl;
                exit(0);
            }
            cout << "Your Password or ID is inserted successfully" << endl;
            pass = check_password;
        } else
            exit(0);
    }
}
//==========================================================================================================================================

// Student class
class student : public validation {
private:
    int student_id;
    vector<string> student_courses;
    vector<double> grades;
protected:
    string student_name;

public:
    student();
    void enroll_courses();
    void display_student();
    double calculate_gpa();
    void update_grade();
    vector<string> get_student_courses();
    string get_student_name();
    int get_student_id();
};

student::student() {}

void student::enroll_courses() {
    cout << "Enter the courses you want to enroll in (maximum 6 courses): " << endl;
    string course;
    for (int i = 0; i < 6; i++) {
        cin >> course;
        student_courses.push_back(course);
    }
    cout << "Courses have been enrolled successfully" << endl;
}

void student::display_student() {
    cout << "Student Name: " << student_name << endl;
    cout << "Student ID: " << student_id << endl;
    cout << "Courses student enrolled in: " << endl;
    for (const string &course : student_courses) {
        cout << course << "   ";
    }
    cout << endl;
}

double student::calculate_gpa() {
    double sum = 0;
    double gpa = 0;
    cout << "Enter your grades respectively for 6 courses: " << endl;
    double grade;
    for (int i = 0; i < 6; i++) {
        cin >> grade;
        grades.push_back(grade);
    }
    for (double g : grades) {
        sum += g;
    }
    gpa = (sum / 600) * 100;
    return gpa;
}

void student::update_grade() {
    string updated_course;
    double new_grade;

    cout << "Enter the Exact name of course you want to update: " << endl;
    cin.sync();
    getline(cin, updated_course);
    validation::validate_string(updated_course);

    for (int i = 0; i < student_courses.size(); i++) {
        if (updated_course == student_courses.at(i)) {
            cout << "Enter the new grade for " << updated_course << ": " << endl;
            cin >> new_grade;
            grades.at(i) = new_grade;
            cout << "Grade has been updated successfully" << endl;
            return;
        }
    }
    cout << "Course not found" << endl;
}

vector<string> student::get_student_courses() {
    return student_courses;
}

string student::get_student_name() {
    return student_name;
}

int student::get_student_id() {
    return student_id;
}

//============================================================================================================================================
// User class
class user : public validation {
    string user_name;
    string email;
    int password = 0000;

public:
    user();
    void login();
    void logout();
    void change_password(int new_password);
};

user::user() {}

void user::login() {
    cout << "User Name: " << endl;
    cin.sync();
    getline(cin, user_name);
    validation::validate_string(user_name);

    cout << "Email: " << endl;
    cin.sync();
    getline(cin, email);
    // Assuming email doesn't need validation

    cout << "Password: " << endl;
    cin >> password;
    validation::validate_password(password);

    cout << "You have been logged in successfully" << endl;
}

void user::logout() {
    cout << "Thank you for using our system" << endl;
    exit(0);
}

void user::change_password(int new_password) {
    validation::validate_password(new_password);
    password = new_password;
    cout << "Password has been updated successfully" << endl;
}

//============================================================================================================================================

// Course class
class course {
    int course_code;
    string course_name;
    string course_department;
    int course_credits;

public:
    void insert_course_data();
    void display_course_data();
    void list_student_course(vector<student> &students); // Pass the list of students
};

void course::insert_course_data() {
    cout << "Course Name: " << endl;
    cin.sync();
    getline(cin, course_name);
    validation v;
    v.validate_string(course_name);

    cout << "Course code: " << endl;
    cin >> course_code;
    v.validate_password(course_code);

    cout << "Course Department: " << endl;
    cin.sync();
    getline(cin, course_department);
    v.validate_string(course_department);

    cout << "Course credits: " << endl;
    cin >> course_credits;
    v.validate_password(course_credits);
}

void course::display_course_data() {
    cout << "Course Name: " << course_name << endl;
    cout << "Course code: " << course_code << endl;
    cout << "Course Department: " << course_department << endl;
    cout << "Course credits: " << course_credits << endl;
}

void course::list_student_course(vector<student> &students) {
    string checker_course_string;

    cout << "Enter the course that you want to view the students that enrolled in that course: " << endl;
    cin >> checker_course_string;

    for (student &stud : students) {
        vector<string> checker = stud.get_student_courses();
        for (const string &course : checker) {
            if (course == checker_course_string) {
                cout << stud.get_student_name() << "  ";
            }
        }
    }
    cout << endl;
}

//==============================================================================================================================================
class university : public user {
    string uni_name;
    string location;
    vector<string> colleges;
    vector<string> departments;

public:
    university();
    void add_college(string new_college);
    void add_departments(string new_department);
    vector<string> get_college();
    vector<string> get_departments();
    string get_uni_name();
    string get_location();
};

university::university() {
    uni_name = "MSA university";
    location = "wahat road";
}

void university::add_college(string new_college) {
    colleges.push_back(new_college);
}

void university::add_departments(string new_department) {
    departments.push_back(new_department);
}

vector<string> university::get_college() {
    return colleges;
}

vector<string> university::get_departments() {
    return departments;
}

string university::get_uni_name() {
    return uni_name;
}

string university::get_location() {
    return location;
}
//==================================================================================================

// AcademicStaff class
class AcademicStaff : public university {
    int staff_id;
    string staff_name;
    string staff_department;
    vector<string> courses_taught;

public:
    void insert_staff_data();
    void office_hours();
    void display_staff_data();
    void view_student_list(vector<student> &students); // Pass the list of students
};

void AcademicStaff::insert_staff_data() {
    validation v;
    cout << "Staff Name: " << endl;
    cin.sync();
    getline(cin, staff_name);
    v.validate_string(staff_name);

    cout << "Staff ID: " << endl;
    cin >> staff_id;
    v.validate_password(staff_id);

    cout << "Staff department: " << endl;
    cin.sync();
    getline(cin, staff_department);
    v.validate_string(staff_department);

    cout << "Courses taught (maximum 6 courses): " << endl;
    string course;
    for (int i = 0; i < 6; i++) {
        cin >> course;
        courses_taught.push_back(course);
    }

    cout << "All information has been inserted successfully" << endl;
}

void AcademicStaff::office_hours() {
    string day;
    int time;

    cout << "Enter the day that you are free in: " << endl;
    cin >> day;

    cout << "Enter the time in that day: " << endl;
    cin >> time;

    cout << "Your office hours have been updated successfully" << endl;
}

void AcademicStaff::display_staff_data() {
    cout << "Name: " << staff_name << endl;
    cout << "ID: " << staff_id << endl;
    cout << "Department: " << staff_department << endl;
    cout << "Courses taught: " << endl;

    for (const string &course : courses_taught) {
        cout << course << "  ";
    }
    cout << endl;
}

void AcademicStaff::view_student_list(vector<student> &students) {
    string course_check;

    cout << "Enter the course to view students enrolled in that course: " << endl;
    cin >> course_check;

    for (student &stud : students) {
        vector<string> checker = stud.get_student_courses();
        for (const string &course : checker) {
            if (course == course_check)
                cout << stud.get_student_name() << "  ";
        }
    }
    cout << endl;
}


// Menu class
class menu {
public:
    void display_menu();
    void select_option();
    void execute_option(int choice);
};

void menu::display_menu() {
    cout << "University Management System" << endl;
    cout << "============================" << endl;
    cout << "[1] Admin" << endl;
    cout << "[2] Academic Staff" << endl;
    cout << "[3] Student" << endl;
    cout << "[4] Exit" << endl;
    cout << endl;
}

void menu::select_option() {
    int choice;
    char checker;

    cout << "Choose number from 1-4: " << endl;
    cin >> choice;

    if (choice < 1 || choice > 4) {
        cout << "Invalid choice, if you want to continue press 'y', if you want to exit press any button" << endl;
        cin >> checker;

        if (checker == 'y' || checker == 'Y') {
            cout << "Choose number from 1-4: " << endl;
            cin >> choice;
            if (choice < 1 || choice > 4) {
                cout << "Invalid choice, Thank you for using our system" << endl;
                exit(0);
            }
            execute_option(choice);
        }
    } else {
        execute_option(choice);
    }
}

void menu::execute_option(int choice) {
    const int uni_max_number = 5;
    university uni[uni_max_number];
    static int number_uni = 0;
    int choice_2;
    int new_password;
    vector<student> students; // Maintain a list of students
    vector<course> courses;   // Maintain a list of courses

    switch (choice) {
        case 1:
            if (number_uni < uni_max_number) {
                do {
                    cout << "[1] login" << endl;
                    cout << "[2] logout" << endl;
                    cout << "[3] change password" << endl;
                    cout << endl;
                    cout << "Choose number from 1-3: " << endl;

                    cin >> choice_2;

                    switch (choice_2) {
                        case 1:
                            uni[number_uni].login();
                            break;
                        case 2:
                            uni[number_uni].logout();
                            break;
                        case 3:
                            cout << "Enter the new password: " << endl;
                            cin >> new_password;
                            uni[number_uni].change_password(new_password);
                            break;
                        default:
                            cout << "Please enter number from 1-3" << endl;
                    }
                } while (choice_2 != 1);
                number_uni++;
            } else {
                cout << "You exceeded the number of admins" << endl;
                cout << "Thank you for using our system" << endl;
                exit(0);
            }
            break;
        case 2: {
            AcademicStaff staff;
            int staff_choice;
            do {
                cout << "[1] Insert Staff Data" << endl;
                cout << "[2] Office Hours" << endl;
                cout << "[3] Display Staff Data" << endl;
                cout << "[4] View Student List" << endl;
                cout << "[5] Back to Main Menu" << endl;
                cout << "Choose an option: " << endl;
                cin >> staff_choice;

                switch (staff_choice) {
                    case 1:
                        staff.insert_staff_data();
                        break;
                    case 2:
                        staff.office_hours();
                        break;
                    case 3:
                        staff.display_staff_data();
                        break;
                    case 4:
                        staff.view_student_list(students);
                        break;
                    case 5:
                        break;
                    default:
                        cout << "Invalid option, please choose again." << endl;
                }
            } while (staff_choice != 5);
            break;
        }
        case 3: {
            student stud;
            int student_choice;
            do {
                cout << "[1] Enroll Courses" << endl;
                cout << "[2] Display Student Info" << endl;
                cout << "[3] Calculate GPA" << endl;
                cout << "[4] Update Grade" << endl;
                cout << "[5] Back to Main Menu" << endl;
                cout << "Choose an option: " << endl;
                cin >> student_choice;

                switch (student_choice) {
                    case 1:
                        stud.enroll_courses();
                        students.push_back(stud); // Add the student to the list
                        break;
                    case 2:
                        stud.display_student();
                        break;
                    case 3:
                        cout << "GPA: " << stud.calculate_gpa() << endl;
                        break;
                    case 4:
                        stud.update_grade();
                        break;
                    case 5:
                        break;
                    default:
                        cout << "Invalid option, please choose again." << endl;
                }
            } while (student_choice != 5);
            break;
        }
        case 4:
            cout << "Thank you for using the University Management System" << endl;
            exit(0);
        default:
            cout << "Invalid option" << endl;
    }
}

int main() {
    menu m;
    while (true) {
        m.display_menu();
        m.select_option();
    }

    return 0;
}
