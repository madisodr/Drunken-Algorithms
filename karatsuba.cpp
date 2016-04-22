#include <iostream>
#include <vector>
#include <algorithm>

#include "drunk.h"

using namespace std;

class Integer { 
    public:
        Integer(){this->push(0); }
        Integer(vector<int> _digits) { this->digits = _digits; }
        Integer(int v) { 
            if(v == 0)
                digits.push_back(0);
            while(v > 0) { 
                digits.push_back(v % 10);
                v /= 10;
            }
        }

        ~Integer(){ }

        vector<int> getDigits() { return this->digits; }
        void setDigit(int val, int pos) { this->digits[pos] = val; }
        int getDigit(int pos) { return this->digits[pos]; }
        int size() { return this->digits.size(); }
        void push(int x) { this->digits.push_back(x); }

        void trimZeros() { 
            for(int i = this->digits.size() - 1; i >= 0 && digits[i] == 0; i--) { 
                this->digits.pop_back();
            }

            if(digits.empty())
                this->push(0);
        }

        void makeEqualSize(Integer* b) {
            int sT = this->getDigits().size();
            int sB = b->getDigits().size();
            int m = drunk_max(sT, sB);

            while(this->getDigits().size() < m)
                this->push(0);

            cout << sB << "\n";

            while(b->getDigits().size() < m)
                b->push(0);
        }

        Integer* slice(int low, int high) { 
            Integer* answer;
            for(int i = low; i <= high; i++) { 
                answer->push(this->digits[i]);
            }

            return answer;
        }

        Integer add(Integer* b) { 
            Integer answer;
            makeEqualSize(b);
            cout << "max donea\n";
            makeEqualSize(&answer);
            cout << "max doneb\n";

            int carry = 0;

            for(int i = 0; i < this->size(); i++) { 
                int sum = this->getDigit(i) + b->getDigit(i) + carry;
                if(sum > 0)  { 
                    carry = 1;
                    answer->setDigit(sum - 10, i);
                } else { 
                    carry = 0;
                    answer->setDigit(sum, i);
                }
            }

            if(carry == 1)
                answer->push(1);

            return answer;
        }

        Integer* subtract(Integer* b) {
            Integer* answer;
            makeEqualSize(b);
            makeEqualSize(answer);

            bool borrow = 0;
            for(int i = 0; i < this->size(); i++) { 
                int top = this->getDigit(i);
                int bottom = b->getDigit(i);
                if(borrow)
                    top--;

                if(top >= bottom) { 
                    borrow = false;
                    answer->setDigit(top-bottom, i);
                } else { 
                    borrow = true;
                    answer->setDigit(10 + top - bottom, i);
                }
            }

            if(borrow == true) { 
                cerr << "ERROR: Can't subtract a larger number from a smaller one.\n";
                exit(1);
            }
        }

        Integer* karatsuba(Integer* b) { 
            /*  int n = A->size();
                int m = int(n/2);

                if(n == 1)
                { 
                Integer answer(A->getDigits()[0] * B->getDigits()[0]);
                return answer;
                }
                Integer a0 = A->Slice(0, m-1);
                Integer a1 = A->slice(m, n-1);
                Integer b0 = B->Slice(0, m-1);
                Integer b1 = B->slice(m, n-1);

                Integer c2 = multiply(a1, b1);
                Integer c0 = multiply(a0, b0);
                Integer c1 = multiply(plus(a1, a0), plus(b1, b0));
                */

            return b;
        }

        void to_string() { 
            for(int i = 0; i < this->size(); i++)
                cout << this->digits[i];

            cout << "\n";
        }


    private:
        vector<int> digits;
};

int main() {
    Integer a(5678);
    Integer b(1234);

    Integer* addi = a.add(&b);
    //Integer* subi = a.subtract(&b);

   // addi->to_string();
   // subi->to_string();
    return 0;
}
