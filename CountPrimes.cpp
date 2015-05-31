int countPrimes(int n)
{
    vector<int> vi(n, 1);
    for(int i = 2; i*i < n; i++)
    {
        if(!vi[i]) continue;
        for(int j = i*i; j < n; j += i)
            vi[j] = 0;
    }
    int count = 0;
    for(int i = 2; i < n; i++)
        if(vi[i])
            count++;
    return count;
}
