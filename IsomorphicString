//Use two container map and set to remember
//which letter has been mapped, then we can
//determine whether the result is true or false

bool isIsomorphic(string s, string t)
{
    map<char, char> m;
    set<char> sc;
    int n = s.length();
    for(int i = 0; i < n; i++)
    {
        if(!m.count(s[i]))
        {
            if(sc.count(t[i]))
                return false;
            else
            {
                m.insert(make_pair(s[i], t[i]));
                sc.insert(t[i]);
            }
        }
        else
            if(m[s[i]] != t[i])
                return false;
    }
    return true;
}
