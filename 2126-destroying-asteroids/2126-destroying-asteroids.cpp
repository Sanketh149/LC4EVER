class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        int n = asteroids.size();
        long long masss = mass;
        for(int i = 0;i<n;i++)
        {
            if(asteroids[i] > masss) return false;
            masss += asteroids[i];
        }
        return true;
    }
};