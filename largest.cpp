//use a compare function to decide which
//number should come first. Then we just link
//all the number. Be careful that all the number
//in the vector are zeros. Another problem is
//that compare function should define as a static
//one or the compile will give a bug.
static bool comp(string &s1, string &s2)
{
    return s1+s2 > s2+s1;
}

string largestNumber(vector<int> &nums)
{
    string s = "";
    vector<string> vs;
    for(int i = 0; i < nums.size(); i++)
        vs.push_back(to_string(nums[i]));
    sort(vs.begin(), vs.end(), comp);
    for(int i = 0; i < vs.size(); i++)
    {
        s += vs[i];
    }
    if(s[0] == '0') return t0_string(0);
    return s;
}
