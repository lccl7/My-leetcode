#include <iostream>
#include <fstream>
#include <set>
#include <vector>
using namespace std;

int main(int argc, char** argv)
{
    multiset<int> largest;
    vector<int> nums;
    ifstream infile(argv[1]);
    int n;
    while(infile >> n)
        nums.push_back(n);
    vector<int>::const_iterator iter = nums.begin();
    int k;
    cin >> k;
    for(;iter != nums.end();iter++)
    {
        multiset<int>::iterator iterfirst = largest.begin();
        if(largest.size() < k)
            largest.insert(*iter);
        else {
            if(*iter > *iterfirst)
            {
                largest.erase(iterfirst);
                largest.insert(*iter);
            }
        }
    }
    cout << *largest.begin() << endl;
    return 0;
}
