//BFS: 232ms

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
                    if(dict.count(s))
                    {
                        qstr.push(s);
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
    return 0;// not found
}

//two end BFS
class Solution
{
public:
    int ladderlength(string beginWord, string endWord, unordered_set<string> wordDict)
    {
        if(beginWord == endWord)
            return 1;
        unordered_set<string> word1, word2;//one is foward set, another provides the target node for set to search
        word1.insert(beginWord);
        word2.insert(endWord);
        wordDict.erase(beginWord);
        wordDict.erase(endWord);
        return ladder(word1, word2, wordDict, 1);
    }
private:
    int ladder(unordered_set<string>& word1, unordered_set<string>& word2, unordered_set<string>& dict, int level)
    {
        if(word1.empty())
            return 0;
        if(word1.size() > word2.size())
            return ladder(word2, word1, dict, level);
        unordered_set<string> tmp;
        for(auto it = word1.begin(); it != word1.end(); it++)
        {
            string word = *it;
            for(auto ch = word.begin(); ch != word.end(); ch++)
            {
                char c = *ch;
                for(*ch = 'a'; *ch <= 'z'; ++(*ch))
                {
                    if(*ch != c)
                        if(word2.count(word))
                            return level+1;
                        else if(dict.count(word))
                        {
                            dict.erase(word);
                            tmp.insert(word);
                        }
                }
                *ch = c;
            }
        }
        return ladder(word2, word3, dict, level+1);
    }
}
