class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        bitset<32>b(n);
        bitset<32>ris(0);
        for(int i=0;i<32;i++)
            {
                ris[i]=b[31-i];
            }
        return ris.to_ulong();
    }
};
