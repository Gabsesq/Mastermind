
#include<iostream>
#include <stdlib.h>
#include "PegCode.h"

using namespace std;

PegCode::PegCode(PegColor peglist[], int length) {
    //Validate to ensure right number of pegs
    if (length != NUMBER_OF_PEGS)
    {
        cout << "Wrong length for pegcode!" << endl;
        exit(-1);
    }
    
    for (int i = 0; i < NUMBER_OF_PEGS; i++)
    {
        pegs[i] = peglist[i];
    }
    
    //Validate to ensure no empty pegs on object construction
    for (int i = 0; i < NUMBER_OF_PEGS; i++)
    {
        if (pegs[i] == EMPTY)
        {
            cout << "Empty Peg in created pegCode!" << endl;
            exit(-1);
        }
    }
}

void PegCode::clearPegAt(int index)
{
    pegs[index] = EMPTY;
}

void PegCode::print()
{
    for (int i = 0; i < NUMBER_OF_PEGS; i++)
    {
        switch (pegs[i])
        {
            case BLUE: cout << "Blue"; break;
            case RED: cout << "Red"; break;
            case YELLOW: cout << "Yellow"; break;
            case GREEN: cout << "Green"; break;
            case ORANGE: cout << "Orange"; break;
            case PURPLE: cout << "Purple"; break;
            case EMPTY: cout << "EMPTY"; break;
            default: cout << "Huh?"; break;
        }
        
        cout << " ";
    }
    cout << endl;
}

PegColor PegCode::getColorAt(int index) const
{
    return pegs[index];
}

int PegCode::getNumBlackResultPegs(PegCode guessCode) const
{
    int count = 0;
    for(int i = 0; i < NUMBER_OF_PEGS; i++)
    {
        if(guessCode.getColorAt(i) == pegs[i])
        {
            count ++;
        }
    }
    return count;
}


int PegCode::getNumWhiteResultPegs(PegCode guessCode) const
{
    
    // matchedBlack[i] = true if we have gotten a black peg
    // for index i of the master code
    bool matchedBlack[NUMBER_OF_PEGS];
    
    //Don't want to count cases that are counted for black pegs
    // so clear them out of the guess code as they've already been
    // accounted for
    // Also, keep track of which indexes in the black code have already been matched
    for (int i = 0; i < NUMBER_OF_PEGS; i++)
    {
        if (guessCode.getColorAt(i) == pegs[i])
        {
            guessCode.clearPegAt(i);//makes color empty
            matchedBlack[i] = true;
        }
        else
        {
            matchedBlack[i] = false;
        }
    }
    //YOUR CODE HERE
    //Hint: since the guessCode is passed by value, use
    // guessCode.clearPegAt() to make sure you don't double-count
    //  colors in the GUESSCODE
    //Hint 2: Check against matchedBlack to make sure we don't double-count
    // colors in the master code
    int count = 0;
    for(int i = 0; i < NUMBER_OF_PEGS; i++)
    {
        for(int j = 0; j < NUMBER_OF_PEGS; j++)
        {
            if(matchedBlack[i] == true)
            {
                i++;
            }
            if(matchedBlack[i] == false)
            {
                if(pegs[i] == guessCode.getColorAt(j))
                {
                    guessCode.clearPegAt(j); //empty/false pegs will determine count.
                    count ++; //count
                    i++; //so it doesn't count if there is another matching color in guesscode, moves onto next next position in peg
                }
            }
        }
    }
    
    return count; //change this once implemented
}

//Add something to overload the == operator for PegCodes
//YOUR CODE HERE
bool PegCode::operator ==(const PegCode &peg)const
{
    for(int i = 0; i < NUMBER_OF_PEGS; i++)
    {
        if (pegs[i] == peg.pegs[i])
        {
            return true;
        }
    }
    return false;
}
 


