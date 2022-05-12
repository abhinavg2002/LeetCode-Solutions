class Solution {
public:
    string largestMerge(string a, string b) {
        int i=0, j=0;
        int n=a.size(), m=b.size();
        string ans;
        while(i<n and j<m){
            if(a[i]>b[j]){
                ans.push_back(a[i++]);
            }else if(a[i]<b[j]){
                ans.push_back(b[j++]);
            }else{
                string x=a.substr(i);
                string y=b.substr(j);
                if(x>y){
                    ans.push_back(a[i++]);
                }else{
                    ans.push_back(b[j++]);
                }
            }
        }
        while(i<n){
            ans.push_back(a[i++]);
        }
        while(j<m){
            ans.push_back(b[j++]);
        }
        return ans;
    }
};