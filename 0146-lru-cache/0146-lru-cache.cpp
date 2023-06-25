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
        else{
            lru.splice(lru.begin(), lru, address[key]);
            return address[key]->second;
        }
    }
    
    void put(int key, int value) {
        if(address.find(key) != address.end())
        {
            lru.splice(lru.begin(), lru, address[key]);
            address[key]->second = value;
            return;
        }
        if(cap == address.size()){
            auto lru_key = lru.back().first;
            lru.pop_back();
            address.erase(lru_key);
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