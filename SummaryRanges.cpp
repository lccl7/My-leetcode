//for string class, push_back function use a character as a parameter
//while append use another string as a parameter
vector<string> summaryRanges(vector<int>& nums)
{
    vector<string> vs;
    if(nums.empty()) return vs;
    for(int i = 0; i < nums.size(); i++)
    {
        int n1 = nums[i], n2 = n1;
        while(i < nums.size() && n1 == nums[i])
        {
            n1++;
            i++;
        }
        i--;
        string s = "";
        s.append(to_string(n2));
        if(n2 != nums[i])
            s.append("->" + to_string(nums[i]));
        vs.push_back(s);
    }
    return vs;
}
