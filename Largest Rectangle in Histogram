// The main function to find the maximum rectangular area under given histogram with n bars
// This is O(n) * (max height).
// Create an empty stack. The stack holds indexes of height vector
// The bars stored in stack are always in increasing order of their heights.
// If this bar is higher than the bar on top stack, push it to stack
// If this bar is lower than top of stack, then calculate area of rectangle 
// with stack top as the smallest (or minimum height) bar.
//  'i' is 'right index' for the top and element before top in stack is 'left index'
// i is the index what now reached and s.top is index before the element just pop.
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        height.push_back(0);
        int len = height.size();
        stack<int> st;
        int maxarea = 0;
        int i = 0;
        while(i < len)
        {
            if(st.empty() || height[st.top()] <= height[i])
                st.push(i++);
            else
            {
                int t = st.top();
                st.pop();
                // Calculate the area with hist[tp] stack as smallest bar
                int area = height[t]*(st.empty() ? i : i-st.top()-1);
                if(area > maxarea)
                    maxarea = area;
            }
        }
//        while(!st.empty())
//        {
//            int t = st.top();
//            st.pop();
//            int area = height[t]*(st.empty() ? i : i-st.top()-1);
//            if(area > maxarea)
//                maxarea = area;
//        }
        return maxarea;

    }
};
