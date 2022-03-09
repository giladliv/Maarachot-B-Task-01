#ifndef MAT_H
#define MAT_H

#include <iostream>
#include <string>
#include <stdexcept>
#include <cctype>


using namespace std;

namespace ariel
{   
    class MessageException : public exception
    {
        // this class is for throwing exceptions by given string
        // the what method will return the given string
        // altough the best solution is to create for each case its own exception'
        // in this task it would be easier and more efficient
        // to just make an exception that returns its given string

        public:
            MessageException(string str) : _msg(str) {}     // using init line (for c'tor)
            const char* what() const noexcept {return _msg.c_str();}    // return the saved string as const char *
        private:
            string _msg;

    };
    
    string mat(int cols, int rows, char a, char b);
}




#endif /* MAT_H */