class Solution {
public:
    string digitSum(string s, int k) {
        string t=s;
        while(t.size()>k){
            int i=0;
            int n=t.size();
            string r;
            while(i<n){
                int j=0;
                int sm=0;
                while(i<n and j<k){
                    sm+=(t[i]-'0');
                    i++;j++;
                }
                r+=to_string(sm);
                // cout<<sm<<" ";
            }
            // cout<<endl;
            t=r;
            // cout<<t<<endl;
        }
        return t;
    }
};