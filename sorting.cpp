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

    QuickSort ss(A);
    printVector(A);

}
