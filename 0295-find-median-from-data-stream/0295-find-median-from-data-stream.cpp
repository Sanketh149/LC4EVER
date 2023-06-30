class MedianFinder {
public:
    MedianFinder() {
        
    }
    priority_queue<int>small_half;
    priority_queue<int, vector<int>, greater<int> >large_half;
    void addNum(int num) {
        small_half.push(num);
        large_half.push(small_half.top());
        small_half.pop();
        if(small_half.size() < large_half.size())
        {
            small_half.push(large_half.top());
            large_half.pop();
        }

    }
    double findMedian() {
        return small_half.size() == large_half.size() ? (double)(small_half.top() + large_half.top())/2 : small_half.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */