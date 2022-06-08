class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& a, int k) {
        deque<int> q;
        vector<int> ans;
        int n=a.size();
        for(int i=0;i<n;i++){
            if(q.front()==i-k){
                q.pop_front();
            }
            while(q.size() and a[q.back()]<a[i]){
                q.pop_back();
            }
            q.push_back(i);
            if(i-k+1>=0){
                ans.push_back(a[q.front()]);
            }
        }
        return ans;
    }
};