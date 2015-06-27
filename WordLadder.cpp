//BFS

int ladderlength(string start, string end, unordered_set<string> &dict)
{
    queue<string> qstr;
    qstr.push(start); qstr.push("");
    int res = 1;
    while(!qstr.empty())
    {
        string s = qstr.front();
        qstr.pop();
        if(s != "")
        {
            for(int i = 0; i < s.length(); i++)
            {
                char tmp = s[i];
                for(char c = 'a'; c <= 'z'; c++)
                {
                    if(c == tmp) continue;
                    s[i] = c;
                    if(s == end) return res+1;
                    if(dict.find(s) != dict.end())
                    {
                        Q.push(s);
                        dict.earse(s);
                    }
                }
                s[i] = tmp;
            }
        }
        else if(!qstr.empty())
        {
            res++;
            qstr.push("");
        }
    }
    return 0;
}
