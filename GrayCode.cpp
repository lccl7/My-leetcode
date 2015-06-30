//We should transform binary code into gray code.
//The first left bit keep unchanged, from the second to the last one,
//do the xor operation with adjacent bit, then we get gray code.
//For example: n = 3; then binary code as follows:
//000, 001, 010, 011, 100, 101, 110, 111
//Gray code is 000, 001, 011, 010, 110, 111, 101, 100
class Solution {
public:
    vector<int> grayCode(int n) {
        int size = (1 << n);
        vector<int> gcode;
        for(int i = 0; i < size; ++i)
        {
            gcode.push_back(i ^ (i >> 1));
        }
        return gcode;
    }
};
