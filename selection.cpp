#include <iostream>
#include <vector>

using namespace std;

class QuickSelect
{
    public:
        QuickSelect(vector<int>& A, int key)
        {
            cout << "QuickSelect\n";
            search(A, 0, A.size(), key);
        }

        int search(vector<int>& A, int imin, int imax, int key)
        {

        }
};

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
