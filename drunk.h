/* 
 * Author: Daniel R Madison
 * Copyright (C) 2016
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *
 *
 * Contains various functions used through the project.
 */

#include <vector>
#include <iostream>
#include <algorithm>

#define SORT_SIZE 100 // number of elements to use when populating vectors and arrays
#define OUTPUT true // display the vector output or not in console.

#define DATA_COMMENT "##"
#define NODE_DELIM ":"
#define NODE_LINK_DELIM ","

using namespace std;

/********************
 * output a vector of integers
 * TODO: print a vector of any object provided it has a class method to_string or is
 * a standard library type.
 * *****************/

void printVector(std::vector<int>& A) {
    for(int i = 0; i < A.size(); i++)
        cout << A[i] << " ";

    cout << "\n\n";
}

/********************
 * suffle a vector of integers.
 * *****************/

void shuffle(vector<int>& A) {
    random_shuffle (A.begin(), A.end());

#ifdef OUTPUT
    cout << "Suffleing Vector\n";
#endif
}


/********************
 * drunk_max takes two integers and returns the larger of the two. 
 * If they are equal, it returns the value passed second.
 * *****************/
int drunk_max(int x, int y) {
    if(x > y)
        return x;
    else
        return y;
}

// trim from start
static inline string &ltrim(string &s) {
    s.erase(s.begin(), find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));
    return s;
}

// trim from end
static inline string &rtrim(string &s) {
    s.erase(find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(), s.end());
    return s;
}

// trim from both ends
static inline string &trim(string &s) {
    return ltrim(rtrim(s));
}
