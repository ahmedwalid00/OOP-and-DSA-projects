#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>
using namespace std;

class Account
{
private:
    string account_name_holder;
    int account_number;
    double account_balance;
    vector<string> transaction_history;
public:
    Account(int number , string name , double initial_balance)
    {
        account_balance = initial_balance;
        account_number = number;
        account_name_holder = name;
    }

    void deposit(double amount)
    {
        if(amount <= 0)
        {
            cout << " you can't deposit a non-positive value " << endl;
            return;
        }

        account_balance += amount;
        ostringstream os;
        os << "Deposit : " << amount << " || New balance : " << account_balance;
        transaction_history.push_back(os.str());
    }

    void withdraw (double amount)
    {
        if( amount > account_balance)
        {
            cout << " You don't have enough money " << endl;
            return;
        }

        account_balance -= amount;
        ostringstream os;
        os << "Withdraw : " << amount << " || New balance : " << account_balance;
        transaction_history.push_back(os.str());
    }

    void transfer(Account &to_acc , double amount)
    {
        if(amount > this->account_balance)
        {
            cout << " You don't have enough money to transfer " << endl;
            return;
        }
        if(amount <= 0)
        {
            cout << " you can't transfer a non-positive value " << endl;
            return;
        }

        this ->withdraw(amount);
        to_acc.deposit(amount);
        ostringstream os;
        os << "Value transferred : " << amount << " to " << to_acc.get_account_name() << " || New balance is : " << to_acc.get_account_balance();
        transaction_history.push_back(os.str());
    }

    void display_details()
    {
        cout << " Account Name : " << account_name_holder << endl;
        cout << " Account number : " << account_number << endl;
        cout << " Account balance : " << account_balance << endl;
        cout << " Transaction history : " << endl;
        for(auto &str : transaction_history)
        {
            cout << str << endl;
        }
    }

    string get_account_name() {return account_name_holder;}
    int get_account_number() {return account_number;}
    double get_account_balance() {return account_balance;}
};

class Bank
{
private:
    unordered_map<int,Account> map_accounts;
    int accounts_numbers = 1000;
public:
    void add_account(string name , double initial_balance)
    {
        if(initial_balance <= 0)
        {
            cout << " you can't start with a non-positive initial balance " << endl;
            return;
        }
        Account new_account(accounts_numbers++,name,initial_balance);
        map_accounts[new_account.get_account_number()] = new_account;

        cout << " Account has been created successfully " << endl;
    }

    void delete_account(int account_number)
    {
        if(map_accounts.find(account_number) != map_accounts.end())
        {
            map_accounts.erase(account_number);
            cout << " Account has been deleted successfully " << endl;
        }
        else
        {
            cout << " Account number not found " << endl;
        }
    }

    void transfer(int from_account_number , int to_account_number , double amount)
    {
        if(account_exists(from_account_number) && account_exists(to_account_number))
        {
            Account &from_acc = map_accounts[from_account_number];
            Account &to_acc = map_accounts[to_account_number];
            from_acc.transfer(to_acc,amount);
        }
        else
        {
            cout << " Invalid account number...  " << endl;
        }
    }

    void deposit(int account_number , double amount)
    {
        if(account_exists(account_number))
        {
            Account &acc = map_accounts[account_number];
            acc.deposit(amount);
        }
        else
        {
            cout << " Invalid account number...  " << endl;
        }
    }

    void withdraw(int account_number , double amount)
    {
        if(account_exists(account_number))
        {
            Account &acc = map_accounts[account_number];
            acc.withdraw(amount);
        }
        else
        {
            cout << " Invalid account number...  " << endl;
        }
    }

    void display_details(int account_number)
    {
        if(account_exists(account_number))
        {
            Account &acc = map_accounts[account_number];
            acc.display_details();
        }
        else
        {
             cout << " Invalid account number...  " << endl;
        }
    }

    Account& get_account(int account_number)
    {
        return map_accounts.at(account_number);
    }

    bool account_exists(int account_number)
    {
        return map_accounts.find(account_number) != map_accounts.end();
    }
};

class Menu
{
private:
    Bank bank;
public:
    void display_menu()
    {
        cout << " Bank System " << endl;
        cout << " =========== " << endl;
        cout << "[1] Add account " << endl;
        cout << "[2] Delete account " << endl;
        cout << "[3] Transfer " << endl;
        cout << "[4] Deposit " << endl;
        cout << "[5] Withdraw " << endl;
        cout << "[6] Display account info " << endl;
        cout << "[7] Exit " << endl;
    }

    void select_option()
    {
        int choice;
        cout << " Please enter a number from 1-7: ";
        cin >> choice;
        execute_option(choice);
    }

     void execute_option(int choice)
     {
         switch(choice)
         {
         case 1:
            {
                string name;
                double initial_balance;

                cout << " Enter the name of the account holder: ";
                cin.ignore();
                getline(cin,name);

                cout << " Enter the initial balance of the account: ";
                cin >> initial_balance;

                bank.add_account(name,initial_balance);
                break;
            }

         case 2:
             {
                 int chosen_account;

                 cout << " Enter the account number: ";
                 cin >> chosen_account;
                 bank.delete_account(chosen_account);
                 break;
             }

         case 3 :
            {
                int from_num;
                int to_num;
                double amount;

                cout << " Enter the number of the account that will transfer the money: ";
                cin >> from_num;

                cout << " Enter the number of the account that will receive the money: ";
                cin >> to_num;

                cout << " Enter the amount of money: ";
                cin >> amount;

                bank.transfer(from_num,to_num,amount);
                break;
            }

         case 4 :
            {
                double amount;
                int acc_num;

                cout << " Enter the account number: ";
                cin >> acc_num;

                cout << " Enter the amount of money: ";
                cin >> amount;

                bank.deposit(acc_num,amount);
                break;
            }

         case 5 :
            {
                double amount;
                int acc_num;

                cout << " Enter the account number: ";
                cin >> acc_num;

                cout << " Enter the amount of money: ";
                cin >> amount;

                bank.withdraw(acc_num,amount);
                break;
            }

         case 6:
            {
                int acc_num;

                cout << " Enter the account number: ";
                cin >> acc_num;

                bank.display_details(acc_num);
                break;
            }

         case 7:
            {
                cout << " Thank you for using our system " << endl;
                exit(0);
                break;
            }

         default:
            cout << " Please enter a number from 1-7 " << endl;
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
