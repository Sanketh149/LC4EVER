class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>s;
        for(auto &it:asteroids)
        {
            while(s.size() and s.top()>0 and it<0)
            {
                int diff = it+s.top();
                if(diff<0) s.pop();
                else if(diff>0) it = 0;
                else {
                    it = 0;
                    s.pop();
                }
            }
            if(it) s.push(it);
        }
        int n2 = s.size();
        vector<int>res(n2);
        for(int i = n2-1;i>=0;i--)
            res[i] = s.top(), s.pop();
        return res;
    }
};