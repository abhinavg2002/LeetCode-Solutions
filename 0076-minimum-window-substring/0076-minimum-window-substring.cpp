class Solution {
public:
    map<char, int> f, p;
    bool check(){
        for(auto x:p){
            if(f[x.first]<x.second)return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        int n=s.size();
        int m=t.size();
        if(m>n)return "";
        for(auto x:t){
            p[x]++;
        }
        int i=0;
        int x=-1, y=-1;
        int l=1e9;
        for(int j=0;j<n;j++){
            f[s[j]]++;
            while(check()){
                if(l>j-i+1){
                    l=j-i+1;
                    x=j, y=i;
                }
                f[s[i]]--;
                i++;
            }
        }
        
        if(x==-1 and y==-1)return "";
        return s.substr(y, x-y+1);
    }
};