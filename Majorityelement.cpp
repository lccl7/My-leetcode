#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(int argc, char *argv[])
{
    ifstream infile(argv[1]);
    vector<int> nums;
    int n;
    while(infile >> n)
        nums.push_back(n);
    int m = nums.size(), p = nums[0];
    int count = 1;
    for(int i = 0; i < n; i++)
    {
        if(nums[i] == p)
            count++;
        else {
            count--;
            if(count < 1)
            {
                p = nums[i];
                count = 1;
            }
        }
    }
    cout << p << endl;
}
