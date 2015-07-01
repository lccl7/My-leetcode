//For the ith, the volume is the min left and right of the A[i]
//For each A[i], the volume[i] is the min(left[i], right[i]) - A[i] 
//as an example, for [0,1,0,2,1,0,1,3,2,1,2,1], for i = 1, the left and right 
//both are zeros, so volume for i = 1 is 0, for i = 2, the left is 1 and 
//right is 2, so volume for i = 2 is 1, for i = 3, the left 2, the right 3,
//so volume is 0, for i = 4, the left 2, the right 3, so volume is 1, for i = 5,
//volume is min(2, 3) - 0 = 2, for i = 6, volume = min(2, 3) - 1 = 1, for i = 7,
//volume = 0, for i = 8, volume = min(2, 3)-2 = 0, for i = 9, volume = min(2, 3)-1=1,
//for i = 10, volume = min(2,3)-2 = 0, for i = 11, volume = (1, 2) -1 = 0
//so the sum = 1 + 1 + 2 + 1 + 1 = 6
class Solution {
public:
    int trap(int A[], int n) {
        if(n <= 0) return 0;
        vector<int> left(n);
        vector<int> right(n);
        int maxleft = 0;
        for(int i = 0; i < n; ++i)
        {
            if(maxleft > A[i]) left[i] = maxleft;
            else
            {
                maxleft = A[i];
                left[i] = A[i];
            }
        }
        
        int maxright = 0;
        for(int i = n-1; i >= 0; --i)
        {
            if(maxright > A[i]) right[i] = maxright;
            else
            {
                maxright = A[i];
                right[i] = A[i];
            }
        }
        int sum = 0;
        for(int i = 0; i < n; ++i)
        {
            sum += min(left[i], right[i]) - A[i];
        }
        
        return sum;
    }
};
