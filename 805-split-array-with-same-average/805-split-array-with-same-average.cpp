class Solution {
public: 
    bool splitArraySameAverage(vector<int>& v) {
        int n=v.size();
        int m=n/2;
        int s=accumulate(v.begin(), v.end(), 0);
        vector<unordered_set<int>> sums(m+1);
        sums[0].insert(0);
        for (int num: v) {
            for (int i = m; i >= 1; --i) 
                for (const int t: sums[i-1]) 
                    sums[i].insert(t + num);
        }
        // s1=(s*n1)/n;
        for(int i=1;i<=m;i++){
            // vary n1 from [1 to n-1]
            // if we get a integer sum then check do we have a subsequence with req sum
            int p=s*i;
            if(p%n)continue;// decimal sum not allowed
            p/=n;// integer sum
            // check if we can get a subsequence with sum p;
            if(sums[i].count(p))return 1;
        }
        return false;
    }
};