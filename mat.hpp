#ifndef MAT_H
#define MAT_H

#include <string>
#include <stdexcept>

using std::string;
using std::exception;

namespace ariel
{   
    class SizeException : public exception
    {
        public:
            const char* what() const noexcept {return "Mat size is always odd";}
    };
    
    string mat(int cols, int rows, char a, char b);
    void rec_round_mat(int s_r, int s_c, int e_r, int e_c, string frame_chars, string mat[]);
}




#endif /* MAT_H */