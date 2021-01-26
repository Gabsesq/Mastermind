
#include<iostream>
#include <string>
#include <ctime>
#include "PegCode.h"

using namespace std;



//The number of rounds the user gets to guess before they lose and the solution is revealed
/// - Change this to make the game easier or harder
const int NUMBER_OF_ROUNDS = 12;


int main()
{
    srand ( time(NULL) );
    PegColor pegs[NUMBER_OF_PEGS];
    PegColor UserPegs[NUMBER_OF_PEGS];
    //new array for user. It is the guessCode object. will pass into get num white and black
    
    for(int i = 0; i < 4; i++)
    {
        int RandomNumber;
        RandomNumber = rand()%(NUMBER_OF_COLORS+1);//NEVER PRINTS ORANGE OR PURPLE
        switch (RandomNumber)
        {
            case 1: pegs[RandomNumber] = BLUE;
                break;
            case 2: pegs[RandomNumber] = RED;
                break;
            case 3: pegs[RandomNumber] = YELLOW;
                break;
            case 4: pegs[RandomNumber]= GREEN;
                break;
            case 5: pegs[RandomNumber]= ORANGE;
                break;
            case 6: pegs[RandomNumber]= PURPLE;
                break;
        }
        cout << pegs[i];// TO TEST CODE
    }
    PegCode(pegs, NUMBER_OF_PEGS);
    
    //user section
for (int runs = 0; runs < NUMBER_OF_ROUNDS; runs ++)
{
    int positionCount = 1;//to tell user which position they are guessing for
    char userChoice;
    for(int i = 0; i < NUMBER_OF_PEGS; i++)
    {
        cout << "select b, r, y, g, o, or p for position " << positionCount << " " << endl;
        cin >> userChoice;
        
    switch (userChoice)
    {
        case 'b':
        case 'B': UserPegs[i] = BLUE;
            break;
        case 'r':
        case 'R': UserPegs[i] = RED;
            break;
        case 'y':
        case 'Y': UserPegs[i] = YELLOW;
            break;
        case 'g':
        case 'G' :UserPegs[i] = GREEN;
            break;
        case 'o':
        case 'O': UserPegs[i] = ORANGE;
            break;
        case 'p':
        case 'P':UserPegs[i] = PURPLE;
            break;
        default: cout << "Not an option, try again";
            i--;
            positionCount --;
    }
        cout << UserPegs[i]; //TO TEST CODE
        cout << pegs[i]; //TO TEST CODE
        positionCount++;
        for(int i = 0; i < NUMBER_OF_PEGS; i++)
            {
        if(UserPegs == pegs )
        {
            cout << "you win!";
        }
            }
    }
    
    for(int i = 0; i < NUMBER_OF_PEGS; i++)
    {
        cout << pegs[i] << " ";
    }
   
    int getNumBlackResultPegs(PegCode UserPegs);
    int getNumWhiteResultPegs(PegCode UserPegs);
    cout << "black: " << getNumBlackResultPegs;//ALWAYS PRINTS 1
    cout << "white: " << getNumWhiteResultPegs;
}
    
    return 0;
}
