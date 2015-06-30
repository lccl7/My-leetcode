//a typical backtracking problem.
//row: stands for which row we have reach. tmp is 1D where the position the queen stand on.
//for example: when the row = 0, tmp = {1, 0, 2, 3}, the position
//we can try is [0,1], [0,0], [0,2], [0,3].
//is_solution tests the place that is valid. the if statement is used for
//taking away in the same column, and in the same diagonal.(the row is grow every time,
//so we don't care for it.
//process_string is used at last when we can push_back the valid place.
//the valid place is that (row, tmp[row]), so we test that j == tmp[i]
class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string>> res;
        vector<int> tmp(n);
        dfs(n, 0, res, tmp);
        return res;
    }

    void process_string(int n, vector<vector<string>> &res, vector<int> tmp)
    {
        vector<string> vs;
        for(int i = 0; i < n; ++i)
        {
            string s;
            for(int j = 0; j < n; ++j)
            {
                if(j == tmp[i])
                    s += "Q";
                else
                    s += ".";
            }
            vs.push_back(s);
        }
        res.push_back(vs);
    }

    bool is_solution(int row, vector<int> tmp)
    {
        for(int i = 0; i < row; ++i)
        {
            if(tmp[i] == tmp[row] || abs(tmp[i]-tmp[row]) == row - i)
                return false;
        }
        return true;
    }

    void dfs(int n, int row, vector<vector<string>> &res, vector<int> tmp)
    {
        if(n == row)
        {
            process_string(n, res, tmp);
            return;
        }
        else
        {
            for(int i = 0; i < n; ++i)
            {
                tmp[row] = i;
                if(is_solution(row, tmp))
                {
                    dfs(n, row+1, res, tmp);
                }
            }
        }
    }
};

//second solution for the N-queens (4ms)
void search2(int cur, int n, int& tot, vector<vector<int> >& vv, vector<int>& v)
{
    if(cur == n)
    {
        tot++;
        vector<string> vs;
        for(int i = 0; i < n; i++)
        {
            string s = "........";
            s[v[i]] = 'Q';
            vs.push_back(s);
        }
        if(tot < 3)
        {
            for(int i = 0; i < n; i++)
            {
                cout << vs[i] << endl;
            }
        }
    }
    else {
        for(int i = 0; i < n; i++)
            if(vv[0][i] == 0 && vv[1][(cur+i)] == 0 && vv[2][(cur-i+n)] == 0)
            {
                v[cur] = i;
                vv[0][i] = vv[1][(cur+i)] = vv[2][(cur-i+n)] = 1;
                search2(cur+1, n, tot, vv, v);
                vv[0][i] = vv[1][(cur+i)] = vv[2][(cur-i+n)] = 0;
            }
    }
}

//third solution for N-queens
void search1(int cur, int n, int& tot, vector<int>& v)
{
    if(cur == n)
    {
        tot++;
        vector<string> vs;
        for(int i = 0; i < cur; i++)
        {
            cout << v[i] << " ";
            string s(n, '.');
            s[v[i]] = 'Q';
            vs.push_back(s);
        }
        cout << endl;
        if(tot < 3)
        for(int j = 0; j < n; j++)
        {
            cout << vs[j] << endl;
        }
        cout << endl;
    }
    else for(int i = 0; i < n; i++)
    {
        bool flag = true;
        v[cur] = i;
        for(int j = 0; j < cur; j++)
            if(v[cur] == v[j] || cur - v[cur] == j - v[j] || cur + v[cur] == j + v[j])
            {
                flag = false; break;
            }
        if(flag)
            search1(cur+1, n, tot, v);
    }
}
