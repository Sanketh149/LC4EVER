class Solution {
public:
    bool rec(vector<int> &nums, int first, int last, int score1, int score2, bool p1)
    {
        if(last < first) {
            return score1>=score2;
        }
        if(p1)
        {
            return rec(nums, first+1, last, score1+nums[first], score2, !p1) or rec(nums, first, last-1, score1+nums[last], score2, !p1);
        }
        else
        {
            return rec(nums, first+1, last, score1, score2+nums[first], !p1) and rec(nums, first, last-1, score1, score2+nums[last],!p1);
        }
    }
    bool PredictTheWinner(vector<int>& nums) {
        bool p1 = true;
        return rec(nums, 0, nums.size()-1, 0, 0, p1);
    }
};