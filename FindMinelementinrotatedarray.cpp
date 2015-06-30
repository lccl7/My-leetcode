//This code is for Find Min element in a rotated array:
//A recursive way to solve it.
//We can build a function that find the minimum element just like binary search.
//The trivial is that only one element (we can just return it)
//or the left element is less than the right
//(as we know that elements are sorted, so we return the left one).
//If the middle element is less than the left, we know that the min is in the left half,
//otherwise in the right half.
int find(vector<int> &num, int left, int right)
{
    if(left == right || num[left] < num[right]) return num[left];
    int mid = left + (right - left)/2;
    if(num[left] > num[mid])
        return find(num, left, mid);
    else
        return find(num, mid+1, right);
}

class Solution {
public:
    int findMin(vector<int> &num) {
       return find(num, 0, num.size()-1);
    }
};
