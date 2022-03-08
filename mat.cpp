#include "mat.hpp"

string ariel::mat(int cols, int rows, char a, char b)
{
    if (rows % 2 == 0 || cols % 2 == 0)
    {
        throw MessageException("Mat size is always odd");
    }
        
    
    string strMat[rows];
    for (int i = 0; i < rows; i++)
    {
        strMat[i] = string(cols, ' ');
    }
    string charsForMat = string() + a + b;
    rec_round_mat(0, 0, rows - 1, cols - 1, charsForMat, strMat);

    string retStr = "";
    for (int i = 0; i < rows; i++)
    {
        retStr += strMat[i];
        retStr += i < rows - 1 ? "\n" : "";
    }

    return retStr;
}

void ariel::rec_round_mat(int s_r, int s_c, int e_r, int e_c, string frame_chars, string mat[])
{
    if (e_r - s_r < 0 || e_c - s_c < 0)
    {
        return;
    }
    int len = frame_chars.length();
    char ch = len > 0 ? frame_chars[s_r % len] : ' ';
    int i = s_r, j = s_c;
    while (j < e_c)
    {
        mat[i][j++] = ch;
    }
    while (i < e_r)
    {
        mat[i++][j] = ch; 
    }
    while (s_c < j)
    {
        mat[i][j--] = ch; 
    }
    while (s_r < i)
    {
        mat[i--][j] = ch; 
    }
    rec_round_mat(s_r + 1, s_c + 1, e_r - 1, e_c - 1, frame_chars, mat);
}