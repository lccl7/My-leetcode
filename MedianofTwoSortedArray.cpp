//when the total number is an odd, return the middle one
//while it is even, return the half of the middle two.

double findMedianSortedArray(vector<int>& num1, vector<int>& num2)
{
    int n1 = num1.size(), n2 = num2.size();
    int total = n1 + n2;
    if(total & 0x01)
        return findkthSortedArray(num1.begin(), n1, num2.begin(), n2, total/2);
    else {
        return (findkthSortedArray(num1.begin(), n1, num2.begin(), n2, total/2) +
                findkthSortedArray(num1.begin(), n1, num2.begin(), n2, total/2+1))/2;
    }
}

double findkthSortedArray(vector<int>::iterator iter1, size_t n1, vector<int>::iterator iter2, size_t n2, int k)
{
    if(n1 > n2)
        return findkthSortedArray(iter2, n2, iter1, n1, k);
    if(n1 == 0)
        return *(iter2 + k-1);
    if(k == 1)
        return min(*iter1, *iter2);
    size_t p1 = min(k/2, n1), p2 = k - p1;
    if(*(iter1+p1-1) < *(iter2 + p2-1))
        return findkthSortedArray(iter1+p1, n1 - p1, iter2, n2, k-p1);
    else if(*(iter1+p1-1) < *(iter2 + p2-1))
        return findkthSortedArray(iter1, n1, iter2+p2, n2-p2, k-p2);
    else {
        return *(iter1+p1-1);
    }
}
