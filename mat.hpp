#ifndef MAT_H
#define MAT_H

#include <iostream>
#include <string>
#include <stdexcept>
#include <cctype>

using std::string;
using std::exception;
using namespace std;

namespace ariel
{   
    class MessageException : public exception
    {
        public:
            MessageException(string str) : _msg(str) { }
            const char* what() const noexcept {return _msg.c_str();}
        private:
            string _msg;

    };
    
    string mat(int cols, int rows, char a, char b);
    void rec_round_mat(int s_r, int s_c, int e_r, int e_c, string frame_chars, string mat[]);
}




#endif /* MAT_H */