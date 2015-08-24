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

#include "drunk.h"

using namespace std;

/********************************
 * SELECTION SORT
 *******************************/
class SelectionSort
{
    public:
        // Constructor Function to call the actual sorting method.
        SelectionSort(vector<int>& A)
        {
            cout << "Selection Sort\n";
            sort(A);
        }

        void sort(vector<int>& A)
        {
            int iMin;

            for(int i = 0; i < A.size(); i++)
            {
                iMin = i;

                for(int j = i+1; j < A.size(); j++)
                {
                    
                    if(A[j] < A[iMin])
                        iMin = j;
                }

                if(iMin != i)
                    swap(A[i], A[iMin]);

            }
        }
};


/********************************
 * INSERTION SORT
 *******************************/
class InsertionSort
{
    public:
        InsertionSort(vector<int>& A)
        {
            cout << "Insertion Sort\n";
            sort(A);
        }

        void sort(vector<int>& A)
        {
            for(int i = 1; i < A.size() - 1; i++)
            {
                int x = A[i];
                int j = i;

                while(j > 0 && A[j - 1] > x)
                {
                    A[j] = A[j-1];
                    j = j - 1;
                }

                A[j] = x;
            }
        }
};

/********************************
 * QUICKSORT
 * TODO: Add parameter for pivot
 * count
 *******************************/
class QuickSort
{
    public:
        QuickSort(vector<int>& A)
        {
            cout << "QuickSort\n";
            sort(A, 0, A.size());
        }

        int partition(vector<int>& A, int left, int right, int p)
        {
            for(int i = left; i < right; i++)
            {
                if(A[i] <= p)
                {
                    swap(A[i], A[left]);
                    left++;
                }
            }

            return (left - 1);
        }

        void sort(vector<int>& A, int left, int right)
        {
            if(left >= right)
                return;

            int mid = left + (right - left) / 2;
            swap(A[mid], A[left]);
            int midpoint = partition(A, left + 1, right, A[left]);
            swap(A[left], A[midpoint]);
            sort(A, left, midpoint);
            sort(A, midpoint + 1, right);
        }
};

/********************************
 * BUBBLESORT
 *******************************/
class BubbleSort
{
    public: 
        BubbleSort(vector<int>& A)
        {
            cout << "BubbleSort\n";
            sort(A);
        }
        void sort(vector<int>& A)
        {
            int f = 1;
            for(int i = 1; i < A.size() && f; i++)
            {
                f = 0;
                for(int j = 0; j < A.size() - 1; j++)
                {
                    if(A[j+1] < A[j])
                    {
                        swap(A[j], A[j+1]);
                        f = 1;
                    }
                }
            }
        }
    
};

/********************************
 * MERGESORT
 *******************************/
class MergeSort
{
    public:
        MergeSort(vector<int>& A, bool topdown)
        {
            vector<int> B(A.size());
            merge(A, 0, A.size(), B);
        }

        void merge(vector<int>& A, int left, int right, vector<int>& B)
        {
            if(right == left + 1)
                return;
            
            int i = 0;
            int length = right - left;
            int midpoint_dist = length/2;
            int l = left;
            int r = left+midpoint_dist;

            merge(A, left, left+midpoint_dist, B);
            merge(A, left+midpoint_dist, right, B);
            for(i = 0; i < length; i++)
            {
                if(l < left + midpoint_dist && (r == right || max(A[l], A[r]) == A[l]))
                {
                    B[i] = A[l];
                    l++;
                } 
                else
                {
                    B[i] = A[r];
                    r++;
                }
            }

            for(i = left; i < right; i++)
                A[i] = B[i - left];
        }
};

int main()
{
    vector<int> A;

    // populate a vector with N values.
    // SORT_SIZE is defined in drunk.h
    for(int i = 0; i < SORT_SIZE; i++)
        A.push_back(i);

#ifdef OUTPUT
    cout << "Initial\n";
    printVector(A);
#endif

    shuffle(A);

    cout << "Sorting\n";
    MergeSort(A, false);

#ifdef OUTPUT
    printVector(A);
#endif

}
