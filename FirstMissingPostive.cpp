//Remember that we return the first missing positive number.
//For example 4, 5, 7, 8, we should return 1
//so we first reorder the element in the array.
class Solution {
public:
    int firstMissingPositive(int A[], int n)
    {
        for(int i = 0; i < n; ++i)
        {
            if(A[i] > 0 && A[i] <= n && A[A[i]-1] != A[i])
            {
                int tmp = A[A[i]-1];
                A[A[i]-1] = A[i];
                A[i] = tmp;
                --i;
            }
        }
        for(int i = 0; i < n; ++i)
        {
            if(A[i] != i+1)
                return i+1;
        }
        return n+1;
    }
};
