vector<string> fullJustify(vector<string> &words, int L)
{
    vector<string> rs;

    for (int i = 0; i < words.size(); )
    {
        int j = i+1;
        int len = words[i].length();
        for (; j < words.size() && len+words[j].length()<L; j++)
            len += 1 + words[j].length();

        if (j == words.size())
        {
            string s(words[i]);
            for (i++ ; i < j; i++) s +=" "+words[i];
            while (s.length() < L) s.push_back(' ');
            rs.push_back(s);
            return rs;
        }
        if (j-i == 1)
        {
            rs.push_back(words[i++]);
            rs.back().append(L-rs.back().length(), ' ');
            continue;
        }

        int a = (L-len) / (j-i-1) + 1;
        int b = (L-len) % (j-i-1);
        string s(words[i]);
        for (i++; i < j; i++, b--)
        {
            s.append(a,' ');
            if (b>0) s.push_back(' ');
            s.append(words[i]);
        }
        rs.push_back(s);
    }
    return rs;
}
