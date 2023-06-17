class Solution {
public:
    int minBitFlips(int start, int goal) {
        int flips = 0;
        for(int i = 0;i<=31;i++)
        {
            int a1 = (start & (1<<i)), a2 = (goal & (1<<i));
            if(a1 != a2) flips++;
        }
        return flips;
    }
};