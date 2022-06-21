class Solution {
public:
    string fun(string s){
        int ct=0, i=0;
        vector<string> v;
        for(int j=0;j<s.size();j++){
            if(s[j]=='1')ct++;
            else ct--;
            if(ct==0){
                string t="1"+fun(s.substr(i+1, j-i-1))+"0";
                v.push_back(t);
                i=j+1;
            }
        }
        sort(v.begin(), v.end(), greater<string>());
        string res;
        for(auto x:v){
            res+=x;
        }
        return res;
    }
    string makeLargestSpecial(string s) {
        return fun(s);
    }
};