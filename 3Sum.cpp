As a extension of 2sum, this version can be a bad code.
class Solution {
public:
vector<vector<int> > threeSum(vector<int> &num) {
vector<int> vi;
vector<vector<int> > vvi;
if(num.size() < 3) return vvi;
sort(num.begin(), num.end());
for(vector<int>::size_type i = 0; i < num.size(); i++)
{
int sum2 = -num[i];
int x = i+1, y = num.size()-1;
while(x < y)
{
if(sum2 == num[x] + num[y])
{
vi.clear();
vi.push_back(num[i]);
vi.push_back(num[x]);
vi.push_back(num[y]);
vvi.push_back(vi);
}
if(sum2 > num[x] + num[y])
x++;
else
y--;
}
}
return vvi;
}
};
The Submission Result: Output Limit Exceeded.
I have also tried the code in my vi&g++ platform, the result is not good enough even for the example provided.
Here lists the print of return value:
-1, -1, 2
-1, 0, 1
-1, 0, 1.
because of double -1, the result is reduplicative. This is not what we intend to see.
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
       vector<vector<int> > vvi;
       if(num.size() < 3) return vvi;
       std::sort(num.begin(), num.end());
       vector<int> tmp;
       for(vector<int>::size_type i = 0; i < num.size()-2; i++)
       {
           if(i > 0 && num[i] == num[i-1]) continue;
           int x = i + 1, y = num.size() - 1;
           while(x < y)
           {
               if(num[x] + num[y] + num[i] < 0)
                   x++;
               else
               if(num[x] + num[y] + num[i] > 0)
                   y--;
               else
               {
                   tmp.clear();
                   tmp.push_back(num[i]);
                   tmp.push_back(num[x]);
                   tmp.push_back(num[y]);
                   vvi.push_back(tmp);
                   ++x; --y;
                   while(x < y && num[x] == num[x-1])
                        x++;
                   while(x < y && num[y] == num[y+1])
                        y--;
               }
           }
       }
       return vvi;
    }
};
