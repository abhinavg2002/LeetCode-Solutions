class SnapshotArray {
public:
    unordered_map<int, unordered_map<int,int>> m;
    int snap_id;
    unordered_map<int, int> v;
    SnapshotArray(int l) {
        snap_id=0;
    }
    
    void set(int i, int val) {
        v[i]=val;
    }
    
    int snap() {
        m[snap_id]=v;
        int x=snap_id;
        snap_id++;
        return x;
    }
    
    int get(int index, int snap_id) {
        return m[snap_id][index];
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */