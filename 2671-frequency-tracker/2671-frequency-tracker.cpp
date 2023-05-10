class FrequencyTracker {
public:
    map<int,int>mp;
    map<int, int>s;
    FrequencyTracker() {
        
    }
    
    void add(int number) {
        int x = mp[number];
        s[x]--;
        mp[number]++;
        s[mp[number]]++;
    }
    
    void deleteOne(int number) {
        if(mp.find(number) != mp.end())
        {
            int x = mp[number];
            if(x == 0) return;
            mp[number]--;
            s[x]--;
            s[mp[number]]++;
        }
    }
    
    bool hasFrequency(int frequency) {
        return s[frequency]>0;
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */