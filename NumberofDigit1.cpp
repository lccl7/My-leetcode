//Number of Digit 1
//we just calculate 1 in every octal bit
//For the current bit in the number, it depends whether
//it equals to 0, or 1, or bigger than 1

int countDigitOne(int n)
{
    long long count = 0, iLower = 0, iCur = 0, iHigher = 0, iFac = 1;
    while(iFac <= n)
    {
        iLower = n - (n / iFac) * iFac;
        iCur = (n / iFac) % 10;
        iHigher = n / iFac / 10;
        if(iCur == 0)
            count += iHigher * iFac;
        else if(iCur == 1)
            count += iHigher * iFac + iLower + 1;
        else {
            count += (iHigher + 1)* 10;
        }
        iFac *= 10;
    }
    return count;
}
