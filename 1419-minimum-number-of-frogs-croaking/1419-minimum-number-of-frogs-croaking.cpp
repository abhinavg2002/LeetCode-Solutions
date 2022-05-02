class Solution {
public:
    bool is(string &a, string &b){
        int n=a.size();
        int j=0;
        for(int i=0;i<n;i++){
            if(a[i]==b[j])j++;
            if(j==b.size())return true;
        }
        return false;
    }
    int minNumberOfFrogs(string &s) {
        if(s[0]!='c')return -1;
        int n=s.size();
        if(n%5)return -1;
        int r=n/5;
        vector<int> f(26,0);
        for(auto x:s){
            f[x-'a']++;
        }
        string s1="croak";
        for(auto x:s1){
            if(f[x-'a']!=r)return -1;
        }
        if(!is(s, s1))return -1;
        int j=0;
        int mx=0;
        fill(f.begin(), f.end(), 0);
        while(j<n){
            int x=s[j]-'a';
            f[x]++;
            for(auto c:s1){
                if(s1.find(c)<s1.find(s[j]))if(f[c-'a']<f[x])return -1;
                else break;
            }
            mx=max(mx, f[x]);
            if(s[j]=='k'){
                for(auto c:s1){
                    f[c-'a']--;
                    if(f[c-'a']<0)return -1;
                }
            }
            j++;
        }
        if(count(f.begin(), f.end(), 0)!=26)return -1;
        return mx;
    }
};