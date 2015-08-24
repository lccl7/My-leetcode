int nthUglyNumber(int n)
{
    unordered_set<long long> Numset;
    priority_queue<long long, vector<long long>, greater<long, long>> ugpq;
    ugpq.push(1);
    int arr[] = {2, 3, 5};
    int i = 0;
    long long nthNum = 1;
    while(i < n)
    {
        nthNum = ugpq.top();
        ugpq.pop();
        if(++i == n)
        {
            break;
        }
        else {
            for(int j = 0; j < 3; j++)
            {
                if(!Numset.count(nthNum * arr[j]))
                {
                    ugpq.push(nthNum * arr[j]);
                    Numset.insert(nthNum * arr[j]);
                }
            }
        }
    }
    return nthNum;
}
