using ll = long long;
class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        priority_queue<ll>maxi;
        priority_queue<ll,vector<ll>, greater<ll>>mini;
        ll n = weights.size();
        for(int i = 0;i<n-1;i++)
        {
            ll currSum = weights[i]+weights[i+1];
            maxi.push(currSum);
            if(maxi.size() > k-1)
                maxi.pop();
            mini.push(currSum);
            if(mini.size() > k-1)
                mini.pop();
        }
        ll diff = 0;
        while(k > 1)
        {
            diff += (mini.top() - maxi.top());
            maxi.pop();
            mini.pop();
            k--;
        }
        return diff;
    }
};