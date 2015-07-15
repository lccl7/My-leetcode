int candy(vector<int>& ratings)
{
    int count = 0;
    vector<int> v(ratings.size(), 1);
    for(int i = 1; i < ratings.size(); i++)
        if(ratings[i] > ratings[i-1])
            v[i] = v[i-1] + 1;
    for(int i = ratings.size()-2; i >= 0; i--)
        if(ratings[i] > ratings[i+1] && v[i] <= v[i+1])
            v[i] = v[i+1] + 1;
    for(int i = 0; i < v.size(); i++)
        count += v[i];
    return count;
}
