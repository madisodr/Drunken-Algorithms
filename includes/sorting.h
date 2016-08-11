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
 */

#ifndef __drunk_sorting_h__
#define __drunk_sorting_h__

#include <vector>

using namespace std;

/********************************
 * SELECTION SORT
 *******************************/
class SelectionSort {
  public:
    // Constructor Function to call the actual sorting method.
    SelectionSort(vector<int>& A);
    ~SelectionSort();

    void sort(vector<int>& A);
};

/********************************
 * INSERTION SORT
 *******************************/
class InsertionSort {
  public:
    InsertionSort(vector<int>& A);
    ~InsertionSort();
    void sort(vector<int>& A);
};

/********************************
 * QUICKSORT
 * TODO: Add parameter for pivot
 * count
 *******************************/
class QuickSort {
  public:
    QuickSort(vector<int>& A);
    ~QuickSort();

    int partition(vector<int>& A, int left, int right, int p);

    void sort(vector<int>& A, int left, int right);
};

/********************************
 * BUBBLESORT
 *******************************/
class BubbleSort {
  public:
    BubbleSort(vector<int>& A);
    ~BubbleSort();
    void sort(vector<int>& A);

};

/********************************
 * MERGESORT
 *******************************/
class MergeSort {
  public:
    ~MergeSort();
    MergeSort(vector<int>& A, bool topdown);
    void merge(vector<int>& A, int left, int right, vector<int>& B);
};

/********************************
 * HEAPSORT
 *******************************/
class HeapSort {
  public:
    HeapSort(vector<int>& A);
    ~HeapSort();
    void to_heap(vector<int>& a);

    void sink(vector<int>& a, int i, int max);
};

#endif // __sorting_h__
