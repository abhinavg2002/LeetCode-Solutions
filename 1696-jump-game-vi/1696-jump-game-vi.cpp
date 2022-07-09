class Solution {
public:
    int maxResult(vector<int>& a, int k) {
        int n=a.size();
        deque<int> q{0};
        vector<int> dp(n);
        dp[0]=a[0];
        for(int i=1;i<n;i++){
            if(q.front()<i-k)q.pop_front();
            dp[i]=a[i]+dp[q.front()];
            while(q.size() and dp[i]>=dp[q.back()])q.pop_back();
            q.push_back(i);
        }
        return dp[n-1];
    }
};