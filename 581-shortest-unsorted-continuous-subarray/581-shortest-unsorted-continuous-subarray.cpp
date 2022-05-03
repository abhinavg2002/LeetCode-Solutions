class Solution {
public:
    int findUnsortedSubarray(vector<int>& a) {
        vector<int> v=a;
        sort(a.begin(), a.end());
        int l=0;
        int n=a.size();
        int i=0, j=n-1;
        while(i<n and a[i]==v[i])i++;
        if(i==n)return 0;
        while(j>=0 and j>=i and a[j]==v[j])j--;
        return j-i+1;
    }
};