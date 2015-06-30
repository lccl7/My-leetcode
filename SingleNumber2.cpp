//Num2s is used for record the bit place where two 1 happen
//Num1s is for one 1 comes up.
//when a bit position has both two 1 and one 1, we should return it to 0.
//After clear 3 we should bring back those position that belongs to Num1s and Num2s.
class Solution {
public:
    int singleNumber(int A[], int n) {
        int Num1s = 0;
        int Num2s = 0;
        int Num3s = 0;
        for(int i = 0; i < n; ++i)
        {
            Num2s |= Num1s & A[i]; 
            Num1s ^= A[i];
            Num3s = ~(Num2s & Num1s);
            Num1s &= Num3s;
            Num2s &= Num3s;
        }
        return Num1s;
    }
};
