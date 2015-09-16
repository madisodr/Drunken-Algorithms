/* 
 * Author: Daniel R Madison
 * Copyright (C) 2015
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
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class BinarySearch
{
    public:
        BinarySearch(vector<int>& A, int key)
        {
            cout << "Binary Search\n";
            search(A, 0, A.size(), key);
        }

        int search(vector<int>& A, int imin, int imax, int key)
        {
            if(A.size() == 0)
                return 0;

            int mid = A.size() / 2;

            if(A[mid] > key)
                return search(A, imin, mid - 1, key);
            else if(A[mid] < key)
                return search(A, mid + 1, imax, key);
            else
                return mid;
        }
};
