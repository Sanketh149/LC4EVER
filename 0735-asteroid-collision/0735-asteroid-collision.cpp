class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>s;
        int n = asteroids.size();
        for(int i = 0; i < n; i++) {
            if(asteroids[i] > 0 || s.empty()) {
                s.push(asteroids[i]);
            }
            else {
                while(!s.empty() and s.top() > 0 and s.top() < abs(asteroids[i])) {
                    s.pop();
                }
                if(!s.empty() and s.top() == abs(asteroids[i])) {
                    s.pop();
                }
                else {
                    if(s.empty() || s.top() < 0) {
                        s.push(asteroids[i]);
                    }
                }
            }
        }
        vector<int>res;
        while(s.size())
        {
            auto curr = s.top();
            s.pop();
            res.push_back(curr);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};