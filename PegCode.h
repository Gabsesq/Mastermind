
#ifndef PEGCODE_H
#define PEGCODE_H

using namespace std;

//The number of pegs in Mastermind peg codes - Change this to make the game easier or harder
const int NUMBER_OF_PEGS = 4;

const int NUMBER_OF_COLORS = 6;
enum PegColor
{
    BLUE,
    RED,
    YELLOW,
    GREEN,
    ORANGE,
    PURPLE,
    EMPTY //should never appear in a "real" PegCode - might be useful as a temporary value
};


class PegCode
{
public:
    /*Initializes the list of pegs*/
    PegCode(PegColor peglist[], int length);
    
    /*Changes the PegColor at a specified index to EMPTY.*/
    void clearPegAt(int index);
    
    /*Prints out the PegCode*/
    void print();
    
    /*Gets the PegColor at a specified index.  index=0 should be the first peg.
     * The last "const" is there to indicate to C++ we are not modifying the object.
     */
    PegColor getColorAt(int index) const;
    
    /* Gets the number of pegs exactly the same (color+ location) as other*/
    int getNumBlackResultPegs(PegCode guessCode) const;
    
    /* Gets the number of pegs in guessCode the same color as this one, but not in the correct location*/
    int getNumWhiteResultPegs(PegCode guessCode) const;
    
    //TODO: Add something here to overload the == operator
    bool operator ==(const PegCode &peg)const;
    //CONST OR &????? GABBY MADE THIS COMMENT
private:
    PegColor pegs[NUMBER_OF_PEGS];
};

#endif

