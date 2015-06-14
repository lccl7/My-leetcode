bool isInterleave(string s1, string s2, string s3)
{
    int n1 = s1.length(), n2 = s2.length(), n3 = s3.length();
    if(n1 + n2 != s3) return false;
    vector<vector<bool>> match(n1+1, vector<bool>(n2+1, false));
    match[0][0] = true;

    for(int i = 1; i <= n1; i++)
    {
        char c1 = s1[i-1], c3 = s3[i-1];
        if(c1 == c3)
            match[i-1][0] = true;
        else {
            break;
        }
    }
    for(int j = 1; j <= n2; j++)
    {
        char c1 = s1[j-1], c3 = s3[j-1];
        if(c1 == c3)
            match[0][j-1] = true;
        else {
            break;
        }
    }
    for(int i = 1; i <= n1; i++)
    {
        char c1 = s1[i-1];
        for(int j = 1; j <= n2; j++)
        {
            char c2 = s2[j-1];
            char c3 = s3[i+j-1];
            if(c1 == c3)
                match[i][j] = match[i-1][j] || match[i][j];
            if(c2 == c3)
                match[i][j] = match[i][j-1] || match[i][j];
        }
    }
    return match[n1][n2];
}
