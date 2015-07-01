//It is about a question how to use binary search.
//we first have to know that there are two nodecreasing intervals.
//We first determine the position where the mid is(in the first interval or the second).
//If in the first one(that means A[left] < A[mid]), then we find whether the target is.
//If it is between A[left] and A[mid], then go on search(right = mid-1)
//or beyond it(left = mid+1).
//The second interval is search in the same way.
class Solution {
public:
    int search(int A[], int n, int target) {
        if(n < 0) return -1;
        int left = 0, right = n-1;
        while(left <= right)
        {
            int mid = left + (right-left)/2;
            if(target == A[mid]) return mid;
            if(A[left] <= A[mid])
            {
                if(A[left] <= target && A[mid] >= target)
                    right = mid-1;
                else
                    left = mid+1;
            }
            else
            {
                if(A[mid] <= target && A[right] >= target)
                    left = mid+1;
                else
                    right = mid-1;
            }
        }
        return -1;
    }
};
