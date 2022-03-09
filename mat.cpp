#include "mat.hpp"

string ariel::mat(int cols, int rows, char a, char b)
{
    string retStr;
    
    if (rows <= 0 || cols <= 0)
    {
        throw MessageException("the rows and columns must be positive");
    }
    if (rows % 2 == 0 || cols % 2 == 0)
    {
        throw MessageException("Mat size is always odd");
    }
    if (a == ' ' || b == ' ' || isprint(a) == 0 || isprint(b) == 0)
    {
        throw MessageException("The symbols must be printable only");
    }

    return retStr;
}