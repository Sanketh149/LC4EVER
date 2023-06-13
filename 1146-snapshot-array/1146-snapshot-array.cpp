class SnapshotArray {
public:
    vector<map<int,int>>v;
    int snaps = 0;
    SnapshotArray(int length) {
        // mp.resize(5*1e4);
        for(int i = 0;i<length;i++)
        {
            map<int,int>tmp = {{0, 0}};
            v.push_back(tmp);
        }
    }
    
    void set(int index, int val) {
        v[index][snaps] = val;
    }
    
    int snap() {
        return snaps++; 
    }
    
    int get(int index, int snap_id) {
        auto it = v[index].upper_bound(snap_id); //to find the last value - 1 entry
        return (--it)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */