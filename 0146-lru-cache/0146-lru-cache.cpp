class LRUCache {
public:
    int cap;
    list<pair<int,int>>lru;
    map<int,list<pair<int,int>>::iterator>address;
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        auto curr = address.find(key);
        if(curr == address.end()) return -1;
        lru.splice(lru.begin(), lru, address[key]);
        return address[key]->second;
    }
    
    void put(int key, int value) {
        if(address.find(key) != address.end())
        {
            lru.splice(lru.begin(), lru, address[key]);
            address[key]->second = value;
            return;
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

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */