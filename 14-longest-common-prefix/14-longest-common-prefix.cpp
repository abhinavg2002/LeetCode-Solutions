class Solution {
public:
    string longestCommonPrefix(vector<string>& a) {
        if(a.size()==0)return "";
        string ans=a[0];
        for(int i=1;i<a.size();i++){
            string t;
            // cout<<ans<<endl;
            for(int j=0;j<min(ans.size(), a[i].size());j++){
                if(ans[j]==a[i][j]){
                    t.push_back(ans[j]);
                }else{
                    break;
                }
            }
            ans=t;
        }
        return ans;
    }
};