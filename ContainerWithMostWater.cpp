//we give two point, initialize with the first one and the last.
//we know that the max container is the lowest height of the two line multiplyed
//by the distance the two. Then we move the point based on which is the lower of the two,
//that is because move the taller one cannot change the max container. we find one that is taller
//than the position we leave, then stop to calculate the container, for finding the largest.
class Solution {
public:
    int maxArea(vector<int> &height) {
        if(height.empty()) return 0;
        int left = 0, right = height.size()-1;
        int first = height[left], last = height[right];
        int maxcontain = 0;
        while(left < right)
        {
            maxcontain = max(maxcontain, min(first, last)*(right-left));
            if(first < last)
            {
                while(left < right && height[left] <= first)  left++;
                if(left < right) first = height[left];
            }
            else
            {
                while(left < right && height[right] <= last)  right--;
                if(left < right) last = height[right];
            }
        }
        return maxcontain;
    }
};
