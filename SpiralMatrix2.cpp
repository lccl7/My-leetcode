//:first I use memset(v, 0, sizeof(v)) to initialize v, but it doesnot work.
//another way is to define 2D array a[n][n] first, then push back a[x][y] to v.
//this is four loops consist a cicle that each loop gives a row or a column.
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > v;
        if(n <= 0) return v;
        vector<int> vi(n, 0);
        for(int i = 0; i < n; ++i)
            v.push_back(vi);
        int tot = v[0][0] = 1;
        int x = 0, y = 0;
        while(tot < n*n)
        {
            while(y+1 < n && !v[x][y+1]) v[x][++y] = ++tot; // the first row
            while(x+1 < n && !v[x+1][y]) v[++x][y] = ++tot; // the last column
            while(y-1 >= 0 && !v[x][y-1]) v[x][--y] = ++tot;// the last row
            while(x-1 >= 0 && !v[x-1][y]) v[--x][y] = ++tot;// the first column
        }
        return v;
    }
};
