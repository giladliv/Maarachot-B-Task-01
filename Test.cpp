/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: Gilad Livshitz
 * 
 * Date: 2022-03-07
 */

#include "doctest.h"
#include "mat.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}


TEST_CASE("Good input") {
	CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces( "@@@@@@@@@\n"
													 "@-------@\n"
													 "@-@@@@@-@\n"
													 "@-@---@-@\n"
													 "@-@@@@@-@\n"
													 "@-------@\n"
													 "@@@@@@@@@"));
	/* Add more test here */
}

TEST_CASE("Bad numbers")
{
	CHECK_THROWS(mat(1, 2, '@', '-'));          // right is even
    CHECK_THROWS(mat(4, 5, '&', '*'));          // left is even
    CHECK_THROWS(mat(122, 144, '=', '^'));      // both are even
    
    CHECK_THROWS(mat(-1, 3, '@', '-'));         // right is negative
    CHECK_THROWS(mat(4, -5, '&', '*'));         // left is negative
    CHECK_THROWS(mat(-122, -144, '=', '^'));    // both are negative
    CHECK_THROWS(mat(-11, -13, '=', '^'));      // both are negative

    CHECK_THROWS(mat(0, 3, '+', '-'));          // right is 0
    CHECK_THROWS(mat(4, 0, '/', '*'));          // left is 0
    CHECK_THROWS(mat(0, 0, '#', '%'));          // both are 0
    CHECK_THROWS(mat(-2, 0, 'G', 'L'));         // both are 0
}

TEST_CASE("Bad Letters")
{
    // the range of every the good letters (printable) are from 33-126
    // it means that (< 33) or (126 <) are the bad letters
    for (int i = -150; i < 256; i++)
    {
        if (i < 33 || 126 < i)
        {
            for (int j = -64; j < 256; j++)
            {
                if (j < 33 || 126 < j)
                {
                    CHECK_THROWS(mat(9, 7, i, j));
                }
            }
        }
    }

}

TEST_CASE("Good Letters")
{
    // the range of every the good letters (printable) are from 33-126
    for (int i = 33; i <= 126; i++)
    {
        for (int j = 33; j <= 126; j++)
        {
            CHECK(mat(9, 7, i, j) == string());
        }
    }

}

TEST_CASE("Bad input") {
    CHECK_THROWS(mat(10, 5, '$', '%'));
    /* Add more test here */
}


/* Add more test cases here */
