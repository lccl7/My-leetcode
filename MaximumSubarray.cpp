//Divide and Conquer
int maxSum(int A[], int left, int right)
{
    int center;
    if(left == right) return A[left];
    center = (left + right) / 2;
    int maxLeftsum, maxRightsum;
    maxLeftsum = maxSum(A, left, center);
    maxRightsum = maxSum(A, center + 1, right);
    int min = numeric_limits<int>::min();
    int maxLeftborder = min, maxRightborder = min;
    int Leftborder = 0, Rightborder = 0;
    for(int i = center; i >= left; i--)
    {
        Leftborder += A[i];
        if(Leftborder > maxLeftborder)
            maxLeftborder = Leftborder;
    }
    for(int j = center + 1; j <= right; j++)
    {
        Rightborder += A[j];
        if(Rightborder > maxRightborder)
            maxRightborder = Rightborder;
    }
    return max(max(maxLeftsum, maxRightsum), maxLeftborder + maxRightborder);
}
class Solution {
public:
    int maxSubArray(int A[], int n) {
        return maxSum(A, 0, n-1); 
    }
};
