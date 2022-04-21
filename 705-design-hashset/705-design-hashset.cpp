class MyHashSet {
public:
    vector<int> v;
    MyHashSet() {
        v.assign(1000005, 0);
    }
    
    void add(int key) {
        v[key]++;
    }
    
    void remove(int key) {
        v[key]=0;
    }
    
    bool contains(int key) {
        return v[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */