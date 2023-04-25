class SmallestInfiniteSet {
    private:
        int n;
        vector<int>res;
        int smallest = 1;
public:
    SmallestInfiniteSet() {
        n = 1001;
        res.resize(n);
        fill(res.begin(), res.end(), 1);
    }
    
    int popSmallest() {
        while(res[smallest] == 0)
        {
            smallest++;
        }
        res[smallest] = 0;
        return smallest;
    }
    
    void addBack(int num) {
        if(res[num] == 1) return;
        if(num < smallest)
        {
            smallest = num;
        }
        res[num] = 1;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */