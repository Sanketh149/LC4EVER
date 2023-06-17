class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
            vector<int>flights(n+1, 0);
            for(auto flight:bookings)
            {
                int s = flight[0]-1, e = flight[1], no = flight[2];
                flights[s] += no;
                flights[e] -= no;
            }
        for(int i = 1;i<n+1;i++)
            flights[i] += flights[i-1];
        return {flights.begin(), flights.end()-1};
    }
};