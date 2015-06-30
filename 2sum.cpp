This is my first version:
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> vi;
        if(numbers.size() == 0) return vi;
        for(vector<int>::size_type i = 0; i < numbers.size(); i++)
        {
            if(numbers[i] <= target)
            {
                for(vector<int>::size_type j = i+1; j < numbers.size(); j++)
                {
                    if(numbers[i] + numbers[j] == target)
                    {
                        vi.push_back(i+1);
                        vi.push_back(j+1);
                        return vi;
                    }
                }
            }
        }
        return vi;
    }
};

The Submission Result: Time Limit Exceeded.
Some data that is tried can pass, maybe the complexity is too high(O(n^2)), the brute force is not a good choice.
Then there comes the sort solution, but it may disturb the index of the original vector.
So a good solution must remember the primary index of sorted vector. Here we use a pair.
we can make-pair the value of numbers and the index. When return the vector of the index, make sure that
the first index is less than the second one.

Here is the code:
bool compare(pair<int, int> x, pair<int,int> y)
{
    return x.first < y.first;
}
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> vi;
        if(numbers.size() == 0) return vi;
        vector<pair<int, int> > n;
        int index = 1;
        for(vector<int>::iterator iter = numbers.begin(); iter != numbers.end(); iter++, index++)
        {
            n.push_back(make_pair(*iter, index));
        }
        sort(n.begin(), n.end(), compare);
        vector<pair<int,int> >::size_type i = 0, j = n.size()-1;
        while(i < j)
        {
           int sum = n[i].first + n[j].first;
           if(sum == target)
            {
                if(n[i].second < n[j].second)
                {   vi.push_back(n[i].second);
                    vi.push_back(n[j].second);
                    return vi;
                }
                else
                {
                    vi.push_back(n[j].second);
                    vi.push_back(n[i].second);
                    return vi;
                }
            }
            if(sum < target)
                i++;
            else
                j--;
        }
        return vi;
    }
};
