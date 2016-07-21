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

#include "../includes/drunk.h"
#include "sorting.h"
#include <algorithm>
#include <iostream>
#include <vector>


int main() {
	vector<int> A;

	// populate a vector with N values.
	// SORT_SIZE is defined in drunk.h
	for (int i = 0; i < SORT_SIZE; i++)
		A.push_back(i);

#ifdef OUTPUT
	cout << "Initial\n";
	printVector(A);
#endif

	shuffle(A);

	cout << "Sorting\n";
	//MergeSort M(A, false);
	// BubbleSort B(A);
	HeapSort H(A);

#ifdef OUTPUT
	printVector(A);
#endif

}
