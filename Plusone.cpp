Solution:
the trivial: if all the digits are 9, we can just give one bigger size than the orignal,
then push one 1 and all the next 0s.
In the next step: we find the last number that is not equal to 9, then add 1 to the number,
and all the next 0s.
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        if(digits == vector<int>(digits.size(), 9))
        {
            vector<int> Plus(digits.size()+1, 0);
            Plus[0] = 1;
            return Plus;
        }
        for(int i = digits.size()-1; i >= 0; -- i)
        {
            if(digits[i] != 9)
            {
                ++digits[i];
                int j = i+1;
                while(j != digits.size())
                {
                    digits[j++] = 0;
                }
                return digits;
            }
        }
    }
};
