#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <fstream>
using namespace std;

string minWindow(string s, string t)
{
    map<char, int> needtoFind, hasFound;
    int begin = 0, end = 0, count = 0;
    int minWinBegin = -1, minWinEnd = s.length();
    for(int i = 0; i < t.length(); i++)
        if(!needtoFind.count(t[i]))
            needtoFind[t[i]] = 1;
        else needtoFind[t[i]]++;
    while(end < s.length())
    {
        char c = s[end];
        if(needtoFind[c])
        {
            hasFound[c]++;
            if(hasFound[c] <= needtoFind[c])
                count++;
        }
        if(count == t.length())
        {
            //this while loop is the same as the one followed
            //but the next one use less time
//            while(needtoFind[s[begin]]== 0 || hasFound[s[begin]] > needtoFind[s[begin]])
//            {
//                if(needtoFind[s[begin]] && hasFound[s[begin]] > needtoFind[s[begin]])
//                    hasFound[s[begin]]--;
//                begin++;
//            }
            while(begin <= end)
            {
                if(needtoFind[s[begin]] == 0)
                    begin++;
                else if(hasFound[s[begin]] > needtoFind[s[begin]])
                        hasFound[s[begin]]--, begin++;
                else break;
            }
            if(end - begin < minWinEnd - minWinBegin)
            {
                minWinEnd = end;
                minWinBegin = begin;
            }
        }
        end++;
    }
    return minWinBegin == -1 ? "" : s.substr(minWinBegin, minWinEnd-minWinBegin+1);
}

int main(int argc, char** argv)
{
    fstream infile(argv[1]);
    string s1, s2;
    infile >> s1 >> s2;
    string s = minWindow(s1, s2);
    cout << s << endl;
}
