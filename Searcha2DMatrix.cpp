This is what I code for the problem: Search a 2D Matrix
In the first we give false if the target is less than the first or larger than the last one.
In the next, we solve in two steps:
step1: find the row that target is no less than the first of the row and no bigger than the last of the row.
step2: find whether a element is equal to target.
Both of the steps do in a binary search way.

bool searchMatrix(vector<vector<int> > &matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    if(target < matrix[0][0] || target > matrix[m-1][n-1])
        return false;

    int low = 0, high = m-1;
    while(low < high)
    {
        int mid = (low + high)/2;
        if(target < matrix[mid][0])
            high = mid-1;
        else if(target > matrix[mid][n-1])
            low = mid + 1;
        else
        {
            low = mid;
            break;
        }
    }

    int lownum = 0, highnum = n-1;
    while(lownum <= highnum)
    {
        int mid = (lownum+highnum)/2;
        if(target < matrix[low][mid])
            highnum = mid - 1;
        else if(target > matrix[low][mid])
            lownum = mid + 1;
        else
            return true;
    }
    return false;
}
