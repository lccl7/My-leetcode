class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        if(n == 0) return 0;
     //   int num = 0;
     //   for(int i = 0; i < n; i++)
     //       if(A[i] != elem) A[num++] = A[i];
     //   return num;
         int* pbegin = A;
         int* pend = A + n;
         pend = remove(pbegin, pend, elem);
         return pend - A;
    }
};
