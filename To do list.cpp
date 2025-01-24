#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class operations
{
private:
    struct task
    {
        string task_name;
        task *next_task;
    };

    struct category
    {
        string category_name;
        task *first_task;
        task *last_task;
        category *next_category;
    };
    int task_counter;
    int category_counter;
    category *first;
    category *last;

public:
    operations()
    {
        task_counter = 0;
        category_counter = 0 ;
        first = nullptr;
        last = nullptr;
        first_task = nullptr;
        last_task = nullptr;
    }

    void add_category(string new_name)
    {
        category *new_category = new category;
        new_category ->category_name = new_name;
        if(category_counter == 0)
        {
            first = last = new_category;
            new_category ->next_category = nullptr;
            new_category ->first_task = nullptr;
        }
        else
        {
            last ->next_category = new_category;
            new_category ->next_category = nullptr;
            new_category ->first_task = nullptr;
            last = new_category;
        }
        category_counter++;
    }

  void add_task(string new_task_name , string category_new_name)
  {
       category *current = first;

       while(current != nullptr)
       {
           if(current->category_name == category_new_name)
           {
               break;
           }
           current = current -> next_category;
       }
       if(current == nullptr)
       {
           cout << " This category is not found " << endl;
           return;
       }

       task *new_task = new task;
       new_task->task_name = new_task_name;
       new_task->next_task = nullptr;

       if(current->first_task == nullptr)
       {
           current->first_task = new_task;
           current->last_task = new_task;
       }
       else
       {
          current->last_task->next_task = new_task;
          current->last_task = new_task;
       }
       task_counter++;
  }

  void remove_category(string name)
  {
      if(category_counter == 0)
      {
          cout << " No categories found... " << endl;
          return;
      }
      else if(category_counter == 1)
      {
          category *temp = first;
          first = last = nullptr;
          delete temp;
      }
      else
      {

      category *curr = first;
      category *before_curr = nullptr;
       bool flag = false;

          while(curr != nullptr)
          {
              if(curr ->category_name == name)
              {
                  flag = true;
                  break;
              }
               before_curr = curr;
              curr = curr ->next_category;
          }
          if(flag)
          {
              before_curr ->next_category = curr ->next_category;
              curr ->next_category = nullptr;
              delete curr;
          }
          else
          {
              cout << " This category is not found... " << endl;
              return;
          }
          category_counter--;
      }
  }

  void bubble_sort()
  {
      if(first == nullptr) return;
      category* current;
      category* last_sorted = nullptr;
      bool swapped;

      do
      {
          swapped = false;
          current = first;

          while(current ->next_category != last_sorted)
          {
              string s1 = current ->category_name;
              string s2 = current ->next_category->category_name;
              if(s1[0] < s2[0])
              {
                  swap(current->category_name,current->next_category->category_name);
                  swap(current->first_task, current->next_category->first_task);
                  swapped = true;
              }
              current = current ->next_category;
          }

          last_sorted = current;

      }while(swapped);
  }

  bool linear_search(string item)
  {
      category* current = first;

      while(current != nullptr)
      {
          if(current->category_name == item)
          {
              return true;
          }
          current = current ->next_category;
      }
      return false;
  }

  void display()
  {
      category* temp = first;
      while(temp != nullptr)
      {
          cout << temp ->category_name << " " ;
          temp = temp ->next_category;
      }
      cout << endl;
  }

  int category_number() {return category_counter;}
  int task_number() {return task_counter;}

};

class Menu : public operations
{
public:

   void display_menu()
   {
       cout << "  TO DO LIST " << endl;
       cout << "  =========== " << endl;
       cout << "[1] add category " << endl;
       cout << "[2] add task " << endl;
       cout << "[3] remove category " << endl;
       cout << "[4] sort categories " << endl;
       cout << "[5] display the categories " << endl;
       cout << "[6] search for a category " << endl;
       cout << "[7] Exit " << endl;
   }

 void select_option()
{
    int choice;
    while (true)
    {
        cout << "Please enter a number from 1-7: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number from 1-7." << endl;
        } else if (choice >= 1 && choice <= 7) {
            execute_option(choice);
        } else {
            cout << "Invalid choice. Please choose a number from 1-7." << endl;
        }
    }
}

   void  execute_option(int choice)
   {
       switch(choice)
       {
       case 1 : {
           string choosed_name;

           cout << " enter the category name " << endl;
           cin.ignore();
           getline(cin,choosed_name);
           add_category(choosed_name);
           break;
       }

       case 2 : {

         string catg_name;
         string task_name;

         cout << " Enter the category name " << endl;
         cin.ignore();
         getline(cin,catg_name);

         cout << " Enter the task name " << endl;
         cin.ignore();
         getline(cin,task_name);

         add_task(task_name,catg_name);
         break;
       }

       case 3 : {

           string removed_catg;

           cout << " Enter the name of the category " << endl;
           cin.ignore();
           getline(cin,removed_catg);
           remove_category(removed_catg);
           break;
       }

       case 4 : {

           cout << " the categories now are sorted " << endl;
           bubble_sort();
           break;
       }

       case 5 : {

       display();
       break;
       }

       case 6 : {

       string searched_catg;

       cout << " Enter the name of the category " << endl;
       cin.ignore();
       getline(cin,searched_catg);

       bool flag = linear_search(searched_catg);

       if(flag)
       {
           cout << " the item is found " << endl;
       }
       else
       {
           cout << " the item is not found..." << endl;
       }

       break;
       }

       case 7 : {

        cout << " Thank you for using our TO DO LIST " << endl;
        exit(0);
        break;
       }

       default:
        cout << " please choose number from 1-7" << endl;
       }
   }

};


int main()
{
    Menu m;

    while(true)
    {
        m.display_menu();
        m.select_option();
    }
    return 0;
}
