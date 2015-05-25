#include <vector>

using namespace std;

/********************************
 * SELECTION SORT
 *******************************/
class Selection
{
    protected:
        mutable vector<int> unsorted;

    public:
    Selection(vector<int> A)
    {
        this->unsorted = A;
    }
        
    vector<int> Sort()
    {
        vector<int> A = this->unsorted;

        int i,j;
        int f, temp;

        for(i = A.size(); i > 0; i--)
        {
            f = 0;
            for(j = 1; j <= i; j++)
            {
                if(A[i] < A[f])
                    f = j;
            }

            temp = A[f];
            A[f] = A[i];
            A[i] = temp;
        }

        return A;
    }
};


/********************************
 * INSERTION SORT
 *******************************/
class Insertion
{
    protected:
        mutable vector<int> unsorted;

    public:
        Insertion(vector<int> A)
        {
            this->unsorted = A;
        }

        vector<int> Sort()
        {
            vector<int> A = this->unsorted;
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

            return A;
        }
};

class QuickSort
{
    protected: 
        mutable vector<int> unsorted;
    public:
        QuickSort(vector<int> A)
        {
            this->unsorted = A;
        }

        vector<int> Sort()
        {
            vector<int> A = this->unsorted;
            return A;
        }
};
