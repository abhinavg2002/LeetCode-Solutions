class Solution {
public:
    int maxResult(vector<int>& a, int k) {
        int n=a.size();
        deque<int> q;
        for(int i=n-1;i>=0;i--){
            int c=a[i]+(q.size()?a[q.front()]:0);
            while(q.size() and c>a[q.back()]){
                q.pop_back();
            }
            q.push_back(i);
            if(q.front()>=i+k)q.pop_front();
            a[i]=c;
        }
        return a[0];
    }
};