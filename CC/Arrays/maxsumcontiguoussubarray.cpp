#include<iostream>
using namespace std;

int maxSubArray(const int* A, int n1) {
    int M_S_F=INT32_MIN, M_E_H=0,i;
    for(i=0;i<n1;i++)
        {
            M_E_H += A[i];
            if(M_S_F<M_E_H)
                M_S_F = M_E_H;
                
            if(M_E_H < 0) {
                M_E_H = 0;
            }
        }
    return M_S_F;
}

int main()
    {
        int A[] = {-10, -200, -50};
        int n = sizeof(A)/sizeof(A[0]);
        cout<<maxSubArray(A,n);
    }