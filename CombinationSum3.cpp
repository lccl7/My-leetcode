#include <iostream>
#include <vector>
using namespace std;

void search(int k, int n, vector<int>& tmp, int pos)
{
    if(0 == n && k == 0)
    {
        for(int j = 0; j < tmp.size(); j++)
            cout << tmp[j] << " ";
        cout << endl;
        return;
    }
    for(int i = pos; i <= 9 && n >= i; i++)
    {
        tmp.push_back(i);
        k--;
        search(k, n-i, tmp, i+1);
        tmp.pop_back();
        k++;
    }
}

//vector<vector<int>> combinationSum3(int k, int n) {
//    vector<vector<int>> vvi;
//    if(n < k) return vvi;
//    vector<int> tmp(k, 0);
//    search(vvi, k, n, tmp);
//    return vvi;
//}

int main()
{
    int k, n;
    vector<int> tmp;
    while(cin >> k >> n)
        search(k, n, tmp, 1);
}
