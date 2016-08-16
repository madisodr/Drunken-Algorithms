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
#include <functional> 
#include <cctype>
#include <locale>

#define SORT_SIZE 100 // number of elements to use when populating vectors and arrays
#define OUTPUT true // display the vector output or not in console.


#ifndef __drunk_h__
#define __drunk_h__

static inline void debug(const std::string& msg) {
#ifdef OUTPUT
  std::cout << msg;
#endif
}

/********************
 * output a vector of integers
 * TODO: print a vector of any object provided it has a class method to_string or is
 * a standard library type.
 * *****************/

static void printVector(std::vector<int>& A) {
  for(size_t i = 0; i < A.size(); i++)
    debug(A[i] + " ");

  debug("\n");
}

//suffle a vector of integers.
static inline void shuffle(std::vector<int>& A) {
  random_shuffle (A.begin(), A.end());
  debug("Suffleing Vector\n");
}


/********************
 * drunk_max takes two integers and returns the larger of the two. 
 * If they are equal, it returns the value passed second.
 * *****************/
static int drunk_max(int x, int y) {
  if(x > y)
    return x;
  else
    return y;
}

/* Code used from user Evan Teran - http://stackoverflow.com/users/13430/evan-teran

http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring 
*/
// trim from start
static inline std::string &ltrim(std::string &s) {
  s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
  return s;
}

// trim from end
static inline std::string &rtrim(std::string &s) {
  s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
  return s;
}

// trim from both ends
static inline std::string &trim(std::string &s) {
  return ltrim(rtrim(s));
}

#endif // __drunk_h__
