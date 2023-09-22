#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int h = 31;
    int w = 11;

    char one, two, three, four, five, six, seven, eight, nine;

    int position;

    bool noOneWon = true;

    bool isPlayer1 = true;
    

    while(noOneWon) {
        if(isPlayer1) {
            cout << "Player 1, Please enter X Position \n";
        } else {
            cout << "Player 2, Please enter O Position \n";
        }
        cin >> position;
        while(position < 1 || position > 9) {
            cout << "Please enter a valid position from 1 to 9 \n";
            cin >> position;
        }        

        switch (position)
        {
        case 1:
            one = isPlayer1 ? 'x' : 'o';
            break;
        case 2:
            two = isPlayer1 ? 'x' : 'o';
            break;
        case 3:
            three = isPlayer1 ? 'x' : 'o';
            break;
        case 4:
            four = isPlayer1 ? 'x' : 'o';
            break;
        case 5:
            five = isPlayer1 ? 'x' : 'o';
            break;
        case 6:
            six = isPlayer1 ? 'x' : 'o';
            break;
        case 7:
            seven = isPlayer1 ? 'x' : 'o';
            break;
        case 8:
            eight = isPlayer1 ? 'x' : 'o';
            break;
        case 9:
            nine = isPlayer1 ? 'x' : 'o';
            break;
        
        default:
            cout << "Please enter a valid position from 1 to 9 \n";
        }
        
        for(int t=0; t<3; t++) {
            for (int i = 0; i < w; i++) {
                for(int j = 0; j < h; j++) {
                    if(
                        (i==0 || i==(w-1)) || 
                        (j==0 || j==(h-1))
                    ) {
                        cout << "* ";
                    } else if (
                        (((i==j) || (i+j == 10)) && ((one == 'x' && t==0) || (four == 'x' && t==1) || (seven == 'x' && t==2)) ) ||
                        (((i == h-(j+1)) || (j-i == 20)) && ((three == 'x' && t==0) || (six == 'x' && t==1) || (nine == 'x' && t==2))) || 
                        (((i+j == 20) || (j-i == 10)) && ((two == 'x' && t==0) || (five == 'x' && t==1) || (eight == 'x' && t==2)))
                    ) {
                        cout <<"* ";
                    } else if (
                        ((((i==2 || i==7) && (j==3 || j==4 || j==5 || j==6)) || ((j==2 || j==7) && (i==3 || i==4 || i==5 || i==6))) && ((one == 'o' && t==0) || (four == 'o' && t==1) || (seven == 'o' && t==2)) ) ||
                        ((((i==2 || i==7) && (j==23 || j==24 || j==25 || j==26)) || ((j==22 || j==27) && (i==3 || i==4 || i==5 || i==6)))&& ((three == 'o' && t==0) || (six == 'o' && t==1) || (nine == 'o' && t==2))) || 
                        ((((i==2 || i==7) && (j==13 || j==14 || j==15 || j==16)) || ((j==12 || j==17) && (i==3 || i==4 || i==5 || i==6)))&& ((two == 'o' && t==0) || (five == 'o' && t==1) || (eight == 'o' && t==2)))
                    ) {
                        cout << "o ";
                    } else if (
                        (j==10 || j==20)
                    ) {
                        cout << "* ";
                    } else {
                        cout << "  ";
                    }
                }
                cout << endl;
            }
        }

        if(
            one == two && two == three ||
            one == four && four == seven ||
            one == five && five == nine ||
            two == five && five == eight ||
            three == six && six == nine ||
            three == five && five == seven ||
            four == five && five == six ||
            seven == eight && eight == nine
        ) {
            noOneWon = false;
            if(isPlayer1) {
                cout << "Player one won the Game WOOOO! \n";
            } 
            else {
                cout << "Player two won the Game WOOOO! \n";
            }
        }
        isPlayer1 = !isPlayer1;
    }
    
    return 0;
}