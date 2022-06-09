class Solution {
public:
    vector<int> twoSum(vector<int>& a, int x) {
        vector<pair<int, int>> v;
        int n=a.size();
        for(int i=0;i<n;i++){
            v.push_back({a[i], i+1});
        }
        sort(v.begin(), v.end());
        int i=0, j=n-1;
        while(i<j){
            if(v[i].first+v[j].first==x){
                return {v[i].second, v[j].second};
            }else if(v[i].first+v[j].first<x){
                i++;
            }else{
                j--;
            }
        }
        return {};
    }
};