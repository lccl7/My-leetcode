//Several methods
//the first one costs 16ms
//the second 4ms

uint32_t reverseBits(uint32_t n)
{
    bitset<32> myset1(n), myset2;
    for(int i = 0, j = 31; i < 32; i++, j--)
        myset2[i] = myset1[j];
    return myset2.to_ullong();
}


uint32_t reverseBits(uint32_t n)
{
    bitset<32> myset1(n);
    unsigned long long sum = 0;
    for(int i = 0; i < 32; i++)
        sum = sum*2 + myset1[i];
    return sum;
}
