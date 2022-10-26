class Solution {
public:
    bool checkSubarraySum(vector<int>& a, int k) {
        unordered_set<int> s;
        int n=a.size();
        int sum=0, p=0;
        for(int i=0;i<n;i++){
            sum+=a[i];
            int m=sum%k;
            if(s.count(m))return true;
            s.insert(p);
            p=m;
        }
        return false;
    }
};