struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
class SnapshotArray {
public:
    unordered_map<int, unordered_map<int,int,custom_hash>, custom_hash> m;
    int snap_id;
    unordered_map<int, int, custom_hash> v;
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