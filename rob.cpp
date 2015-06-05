//numnolast is the max sum that doesnot contain the last num
//numwithlast is the max sum that contain the last num.

int rob(vector<int>& nums)
{
    if(nums.size() == 0) return 0;
    int numwithlast = a[0], numnolast = 0;
    for(int i = 1; i < nums.size(); i++)
    {
        int n = numnolast;
        numnolast = max(numwithlast, numnolast);
        numwithlast = n + a[i];
    }
    return numwithlast > numnolast ? numwithlast : numnolast;
}
