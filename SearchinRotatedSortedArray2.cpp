//A difficult question.http://www.cnblogs.com/TenosDoIt/p/3465240.html
//
class Solution {
public:
    bool search(int A[], int n, int target) {
        int left = 0, right = n-1;
        while(left <= right)
        {
            int mid = left + (right - left)/2;
            if(target == A[mid]) return true;
            if(A[mid] > A[left])
            {
                if(A[left] <= target && A[mid] >= target)
                    right = mid-1;
                else
                    left = mid+1;
            }
            else if(A[left] > A[mid])
            {
                if(A[mid] < target && A[right] >= target)
                    left = mid+1;
                else
                    right = mid-1;
            }
            else
                ++left;
        }
        return false;
    }
};
