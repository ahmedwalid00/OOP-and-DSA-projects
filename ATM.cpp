#include <iostream>

using namespace std;

//**********variables*********//
int balance = 1000 ;
int deposite  ;
int withDraw  ;
int passWord = 0000 ;
//**********variables*********//


void show()
{
    cout << " *******menu*******" << endl ;
    cout << " 1.balance " << endl;
    cout << " 2.deposite " << endl ;
    cout << " 3.with draw " << endl ;
    cout << " 4. exit " << endl ;
    cout << " ******************* " << endl ;
}

void process ()
{
    int pass , counter = 0 , choice  ;


    cout << " enter your password " << endl ;
    cin >> pass ;

    if ( pass == passWord)
    {
        cout << " correct password " << endl ;
        cout << " choose the operation you want " << endl ;
        cout << " *******menu*******" << endl ;
        cout << " 1.balance " << endl;
        cout << " 2.with draw " << endl ;
        cout << " 3.deposite " << endl ;
        cout << " 4. exit " << endl ;
        cout << " ******************* " << endl ;


do {
        cin >> choice ;
        switch (choice)
        {
        case 1 :
            cout << " your balance is " << balance << " $ " << endl ;
            break ;
        case 2 :
            cout << " your balance is " <<  balance << " $ " << endl ;
            cout << " enter the value you want to withdraw it " << endl ;
            cin >> withDraw ;
                if ( withDraw > balance)
                    cout << " you dont have enough money " << endl ;
                else
                {
                    balance -= withDraw ;
                    cout << " your balance is " <<  balance << " $ " << endl ;

                }
                break ;
        case 3 :
            cout << " enter the value you want to deposite " << endl ;
            cin >> deposite ;

            balance += deposite ;
            cout << " your balance is " << balance << " $ " << endl ;
            break ;
        case 4 :
            cout << " thank you " << endl ;
            break ;
        default : cout << " enter number from 1 to 4 " << endl ;

         }
       } while ( choice != 4 ) ;
    }
    else
    {
        do
             {
                 cout << " incorrect password , try again " << endl ;
                  cout << " enter your password " << endl ;
                   cin >> pass ;
                 counter ++ ;
             }

        while ( pass != passWord && counter <= 3 ) ;

        if ( pass == passWord )
             {

         cout << " correct password " << endl ;
        cout << " choose the operation you want " << endl ;
        cout << " *******menu*******" << endl ;
        cout << " 1.balance " << endl;
        cout << " 2.with draw " << endl ;
        cout << " 3.deposite " << endl ;
        cout << " 4. exit " << endl ;
        cout << " ******************* " << endl ;


do {
        cin >> choice ;
        switch (choice)
        {
        case 1 :
            cout << " your balance is " << balance << " $ " << endl ;
            break ;
        case 2 :
            cout << " your balance is " <<  balance << " $ " << endl ;
            cout << " enter the value you want to withdraw it " << endl ;
            cin >> withDraw ;
                if ( withDraw > balance)
                    cout << " you dont have enough money " << endl ;
                else
                {
                    balance -= withDraw ;
                    cout << " your balance is " <<  balance << " $ " << endl ;

                }
                break ;
        case 3 :
            cout << " enter the value you want to deposite " << endl ;
            cin >> deposite ;

            balance += deposite ;
            cout << " your balance is " << balance << " $ " << endl ;
            break ;
        case 4 :
            cout << " thank you " << endl ;
            break ;
        default : cout << " enter number from 1 to 4 " << endl ;

         }
} while ( choice != 4) ;
             }
             else
                cout << " wrong password " << endl ;

    }





}

int main()
{
     show () ;
     process () ;
    return 0;
}
