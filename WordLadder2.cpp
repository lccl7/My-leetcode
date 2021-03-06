class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        vector<vector<string>> paths;
        vector<string> path(1, start);
        if(start == end)
        {
            paths.push_back(path);
            return paths;
        }

        unordered_set<string> words1, words2;
        words1.insert(start);
        words2.insert(end);
        unordered_map<string, vector<string>> nexts;
        bool word1IsBegin = false;
        if(findLadderHelper(words1, words2, dict, nexts, word1IsBegin))
            getPath(start, end, nexts, path, paths);
        return paths;
    }
private:
    bool findLadderHelper(
            unordered_set<string>& words1, unordered_set<string>& words2, unordered_set<string>& dict,
            unordered_map<string, vector<string>>& nexts, bool &words1IsBegin)
    {
        words1IsBegin = !words1IsBegin;
        if(words1.empty())
            return false;
        if(words1.size() > words2.size())
            return findLadderHelper(words2, words1, dict, nexts, words1IsBegin);
        for(auto it = words1.begin(); it != words1.end(); it++)
            dict.erase(*it);
        for(auto it = words2.begin(); it != words2.end(); it++)
            dict.erase(*it);
        unordered_set<string> tmp;
        bool reach = false;
        for(auto it = words1.begin(); it != words1.end(); ++it)
        {
            string word = *it;
            for(auto ch = word.begin(); ch != word.end(); ++ch)
            {
                char c = *ch;
                for(*ch = 'a'; *ch <= 'z'; ++(*ch))
                {
                    if(words2.count(word))
                    {
                        reach = true;
                        words1IsBegin ? nexts[*it].push_back(word):nexts[word].push_back(*it);
                    }
                    else if(!reach && dict.count(word))
                    {
                        tmp.insert(word);
                        words1IsBegin ? nexts[*it].push_back(word):nexts[word].push_back(*it);
                    }
                }
                *ch = c;
            }
        }
        return reach || findLadderHelper(words2, tmp, dict, nexts, words1IsBegin);
    }
    
    void getPath(string beginWord, string& endWord, unordered_map<string, vector<string>>& nexts,
                vector<string>& path, vector<vector<string>>& paths)
    {
        if(beginWord == endWord)
            paths.push_back(path);
        else {
            for(auto it = nexts[beginWord].begin(); it != nexts[beginWord].end(); ++it)
            {
                path.push_back(*it);
                getPath(*it, endWord, nexts, path, paths);
                path.pop_back();
            }
        }
    }
};
