class Solution {
public:
    #define ll long long
    int sum(string &s){
        int ct=0;
        for(auto x:s){
            ct+=(x-'0');
        }
        return ct;
    }
    long long makeIntegerBeautiful(long long nm, int t) {
        string s=to_string(nm);
        int n=s.size();
        int i=n-1;
        while(i>=0 and sum(s)>t){
            // cout<<s<<endl;
            if(s[i]=='0'){
                i--;
                continue;
            }
            s[i]='0';
            int j=i-1;
            while(j>=0 and s[j]=='9'){
                s[j]='0';
                j--;
            }
            if(j>=0){
                s[j]++;
            }else{
                s.insert(s.begin(), '1');
                break;
            }
            i--;
        }
        ll nn=stoll(s);
        return nn-nm;
    }
};