class MyCalendarThree {
public:
    multiset<pair<int,int>> s;
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        s.insert({start, 1});
        s.insert({end, -1});
        int a=0, ans=0;
        for(auto x:s){
            a+=x.second;
            ans=max(ans, a);
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */