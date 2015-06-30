class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        if(num.empty()) return 0;
        int n = num.size();
        return findPeak(num, 0, n-1);
    }
    int findPeak(const vector<int> &num, int begin, int end)
    {
        if(begin > end) return 0;
        if(begin == end) return begin;
        int mid = (begin+end)/2;
        if ((mid == 0 || num[mid-1] <= num[mid]) &&
            (mid == num.size()-1 || num[mid+1] <= num[mid])) // Compare middle element with its neighbours (if neighbours exist)
            return mid;
        else if (mid > 0 && num[mid-1] > num[mid]) // If middle element is not peak and its left neighbor is greater than it
                                                    // then left half must have a peak element
            return findPeak(num, begin, mid);
        else return findPeak(num, mid+1, end);  // If middle element is not peak and its right neighbor is greater than it
                                                // then right half must have a peak element
    }
};
