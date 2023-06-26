using ll = long long int;
class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        cout<<n<<endl;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        int l = 0, r = n - 1;
        for(int i = 0;i<candidates;i++)
        {
            pq.push({costs[l],l});
            l++;
            if(l>r) break;
            pq.push({costs[r],r});
            r--;
            if(l>r) break;
        }
        ll hiringCost = 0;
        for(int i = 0;i < k; i++)
        {
            auto [cost, idx] = pq.top();
            pq.pop();
            hiringCost += cost;
            if(idx < l and l<=r)
                pq.push({costs[l], l++});
            else if(idx > r and l<=r)
                pq.push({costs[r], r--});
        }
        return hiringCost;
    }
};