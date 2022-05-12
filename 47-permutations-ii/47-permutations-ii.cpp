set<vector<int>> ans;

void solve(int i, int n, vector<int>&a){
    if(i==n-1){
        ans.insert(a);
        return;
    }
    
    for(int j=i;j<n;j++){
        if(i!=j and a[i]==a[j])continue;
        swap(a[i], a[j]);
        solve(i+1, n, a);
        swap(a[i], a[j]);
    }
}

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& a) {
        ans.clear();
        sort(a.begin(), a.end());
        int n=a.size();
        solve(0, n, a);
        vector<vector<int>> x(ans.begin(), ans.end());
        return x;
    }
};