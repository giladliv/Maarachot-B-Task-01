#ifndef MAT_H
#define MAT_H

#include <string>
#include <stdexcept>

using std::string;
using std::exception;

namespace ariel
{   
    class MessageException : public exception
    {
        public:
            MessageException(string str = "") : _msg(str.c_str()) { }
            const char* what() const noexcept {return _msg;}
        private:
            const char* _msg;

    };
    
    string mat(int cols, int rows, char a, char b);
    void rec_round_mat(int s_r, int s_c, int e_r, int e_c, string frame_chars, string mat[]);
}




#endif /* MAT_H */