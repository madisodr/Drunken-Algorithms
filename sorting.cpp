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

/********************************
 * SELECTION SORT
 *******************************/
class SelectionSort
{
    public:
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
        MergeSort(vector<int>& A, bool Y)
        {
            cout << "MergeSort: ";
            if(Y)
            {
                cout << "Top Down\n";
                sortTopDown(A);
            }
            else
            {
                cout << "Bottom Up\n";
                sortBottomUp(A);
            }
        }

        void sortTopDown(vector<int>& A)
        {

        }

        void sortBottomUp(vector<int> A)
        {

        }
};
void printVector(vector<int>& A)
{
    for(int i = 0; i < A.size(); i++)
    cout << A[i] << " ";

    cout << "\n\n";
}

void shuffle(vector<int>& A)
{
    random_shuffle (A.begin(), A.end());
    
    cout << "Suffleing Vector\n";
    printVector(A);
}

int main()
{
    vector<int> A;
    for(int i = 0; i < 10; i++)
        A.push_back(i);

    cout << "Initial\n";
    printVector(A);
    shuffle(A);

    BubbleSort ss(A);
    printVector(A);

}
