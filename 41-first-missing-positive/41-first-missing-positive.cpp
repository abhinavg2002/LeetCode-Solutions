class Solution {
public:
    int firstMissingPositive(vector<int>& a) {
        int n=a.size();
        sort(a.begin(), a.end());
        int id=lower_bound(a.begin(), a.end(), 0)-a.begin();
        if(id==n){
            return 1;
        }
        if(a[id]==0){
            id++;
        }
        int e=1;
        for(int i=id;i<n;i++){
            if(i>0 and a[i]==a[i-1])continue;
            if(a[i]!=e){
                return e;
            }
            e++;
        }
        return e;
    }
};