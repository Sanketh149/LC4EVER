class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int total = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        int mini = 0,currSum = 0;
        int n = cardPoints.size();
        
        for(int i = 0;i<n-k;i++)
            currSum += cardPoints[i];
        mini = currSum;
        for(int i = n-k;i<n;i++)
        {
            currSum += (cardPoints[i] - cardPoints[i+k-n]);
            mini = min(mini, currSum);
        }
        return total - mini;
    }
};