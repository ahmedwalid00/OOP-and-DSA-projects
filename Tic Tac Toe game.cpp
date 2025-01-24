#include <iostream>

using namespace std;

char matrix [3][3] = { {'1','2','3'} , {'4','5','6'} , {'7','8','9'} } ;
char pos ;
char player = 'x' ;

void show ()
{
    system("cls") ;
    cout << "  -------" << endl ;
     for ( int i = 0 ; i < 3 ; i++ )
    {
        cout << " | " ;
        for ( int j = 0 ; j < 3 ; j++)
            cout << matrix [i][j] << " " ;
             cout << "| " ;
        cout << endl ;
    }
    cout << "  -------" << endl ;
}
//----------------------------------------------------------------------------------

void input ()
{
    cout << " Enter your position -- player ( " << player << " )" << endl;
    cin >> pos ;

    for ( int i = 0 ; i < 3 ; i++)
    {
        for ( int j = 0 ; j < 3 ; j++)
        {
            if ( pos == matrix [i][j])
                matrix [i][j] = player ;
        }

    }

 if ( player == 'x')
    player = 'o' ;
 else
    player = 'x' ;

}


//---------------------------------------------------------------------------

char replacee ()
{
    int x = 0 , o = 0 , counter = 0 ;

    for ( int i = 0 ; i < 3 ; i++)
    {
        for ( int j = 0 ; j < 3 ; j++)
           {
            if ( matrix[i][j] == 'x')
                 x++;
            if ( matrix[i][j] == 'o')
                 o++;
            if (x == 3)
                return 'x' ;
            if (o == 3)
                return 'o' ;
           }
        x = 0 ;
        o = 0 ;
    }

   //===========================================================

   for ( int k = 0 ; k < 3 ; k++)
   {
       for ( int d = 0 ; d < 3 ; d++)
       {
           if ( matrix [d][k] == 'x')
               x++ ;
           if ( matrix [d][k] == 'o')
               o++ ;
           if ( x == 3)
            return 'x' ;
           if ( o == 3)
            return 'o' ;
       }
       x = 0 , o = 0 ;
   }

    //=============================================================

    for ( int z = 0 ; z < 3 ; z++ )
    {
        if ( matrix [z][z] == 'x')
            x++;
        if ( matrix [z][z] == 'o')
            o++;
        if ( x == 3)
            return 'x' ;
        if ( o == 3)
            return 'o' ;

    }

    //===============================================================

if ( matrix[0][2] == 'x' && matrix [1][1] == 'x' && matrix [2][0] == 'x')
    return 'x' ;
if ( matrix[0][2] == 'o' && matrix [1][1] == 'o' && matrix [2][0] == 'o')
    return 'o' ;

    //=================================================================
    for ( int t = 0 ; t < 3 ; t++)
    {
        for ( int y = 0 ; y < 3 ; y++)
        {
            if ( matrix[t][y] != 'x' && matrix[t][y] != 'o')
                counter++ ;
        }
    }
    if ( counter == 0 )
        return '=' ;
return '*' ;

int main()
{

while (replacee() == '*')
{
    show() ;
    input () ;
    replacee ();
}
show ();
if ( replacee() == 'x')
    cout << " The Winner is player (X) " << endl ;
if ( replacee () == 'o')
    cout << " The Winner is player (o) " << endl ;
if ( replacee() == '=')
    cout << " Draw " << endl ;




 return 0;
}
