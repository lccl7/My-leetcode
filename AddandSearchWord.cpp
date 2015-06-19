void addWord(string word)
{
    stgmap.insert(pair<int,string>(word.size(), word));
}

bool search(string word)
{
    int n = word.size();
    if(stgmap.find(n) == stgmap.end())
        return false;
    pair<multimap<int,string>::iterator, multimap<int, string>::iterator> ret;
    ret = stgmap.find(n);
    for(multimap<int,string>::iterator iter = ret.first; iter != ret.second; iter++)
    {
        string s = iter->second;
        int i = 0;
        while(i < n)
        {
            if(word[i] == '.' || word[i] == s[i])
                i++;
            else {
                break;
            }
        }
        if(i == n)
            return true;
    }
    return false;
}

private:
    multimap<int, string> stgmap;
