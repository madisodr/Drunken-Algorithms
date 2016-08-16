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

/********************************
 * SELECTION SORT
 *******************************/
class SelectionSort {
  public:
    // Constructor Function to call the actual sorting method.
    SelectionSort(std::vector<int>& A);
    ~SelectionSort();

    void sort(std::vector<int>& A);
};

/********************************
 * INSERTION SORT
 *******************************/
class InsertionSort {
  public:
    InsertionSort(std::vector<int>& A);
    ~InsertionSort();
    void sort(std::vector<int>& A);
};

/********************************
 * QUICKSORT
 * TODO: Add parameter for pivot
 * count
 *******************************/
class QuickSort {
  public:
    QuickSort(std::vector<int>& A);
    ~QuickSort();

    int partition(std::vector<int>& A, int left, int right, int p);

    void sort(std::vector<int>& A, int left, int right);
};

/********************************
 * BUBBLESORT
 *******************************/
class BubbleSort {
  public:
    BubbleSort(std::vector<int>& A);
    ~BubbleSort();
    void sort(std::vector<int>& A);

};

/********************************
 * MERGESORT
 *******************************/
class MergeSort {
  public:
    ~MergeSort();
    MergeSort(std::vector<int>& A, bool topdown);
    void merge(std::vector<int>& A, int left, int right, std::vector<int>& B);
};

/********************************
 * HEAPSORT
 *******************************/
class HeapSort {
  public:
    HeapSort(std::vector<int>& A);
    ~HeapSort();
    void to_heap(std::vector<int>& a);

    void sink(std::vector<int>& a, int i, int max);
};

#endif // __sorting_h__
