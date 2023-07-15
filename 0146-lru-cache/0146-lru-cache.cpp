class LRUCache {
public:
    int cap;
    list<pair<int,int>>lru;
    map<int,list<pair<int,int>>::iterator>address;
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(address.find(key) == address.end()) return -1;
        auto curr = address[key];
        int val = curr->second;
        address.erase(key);
        lru.erase(curr);
        lru.push_front({key, val});
        address[key] = lru.begin();
        return val;
    }
    
    void put(int key, int value) {
        if(address.find(key) != address.end())
        {
            auto curr = address[key];
            address.erase(key);
            lru.erase(curr);
        }
        if(address.size() == cap)
        {
            int todel = lru.back().first;
            lru.pop_back();
            address.erase(todel);
        }
        lru.push_front({key, value});
        address[key] = lru.begin();
    }
};
