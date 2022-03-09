#include "mat.hpp"


/**
 * @brief this function returns the string of the carpet output.
 * the rows and cols must be odd and positive.
 * the symbols must be printable and not spaces type (space, tab, new line)
 * 
 * @param cols number of columns
 * @param rows number of rows
 * @param a the first symbol
 * @param b the second symbol
 * @return string 
 */
string ariel::mat(int cols, int rows, char a, char b)
{
    string retStr;
    
    if (rows <= 0 || cols <= 0)
    {
        // if one (or more) of the rows or cols is not positive throw exception
        throw MessageException("the rows and columns must be positive");
    }
    if (rows % 2 == 0 || cols % 2 == 0)
    {
        // if one (or more) of the rows or cols is not odd throw exception
        throw MessageException("Mat size is always odd");
    }
    if (a == ' ' || b == ' ' || isprint(a) == 0 || isprint(b) == 0)
    {
        // if one (or more) of the symbols is space or not printable throw exception
        throw MessageException("The symbols must be printable only");
    }

    return retStr;
}