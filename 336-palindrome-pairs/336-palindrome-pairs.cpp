class Solution {
public:
    map<string,bool> p;
    bool fun(string &s){
        if(p.count(s))return p[s];
        if(s.size()==0)return p[""]=true;
        string t=s;
        reverse(t.begin(), t.end());
        return p[s]=(s==t);
    }
    vector<vector<int>> palindromePairs(vector<string>& w) {
        vector<vector<int>> ans;
        unordered_map<string,int> m;
        int n=w.size();
        for(int i=0;i<n;i++){
            string s=w[i];
            reverse(s.begin(), s.end());
            m[s]=i;
        }
        if(m.count("")){
            int id=m[""];
            for(int i=0;i<n;i++){
                if(id==i)continue;
                if(fun(w[i])){
                    ans.push_back({i, id});
                }
            }
        }
        for(int i=0;i<n;i++){
            // w[i]="abaa"
            string l="", r=w[i];
            for(int j=0;j<w[i].size();j++){
                // at any point 
                // l=ab, r=aa
                // now if we found ab in m that means we have ba in array and r is palindrome
                // so we can add w[i]+rev(l);
                // similarly other condition for aaab
                l+=w[i][j];
                r.erase(r.begin());
                if(m.count(l) and fun(r) and m[l]!=i){
                    ans.push_back({i, m[l]});
                }
                if(m.count(r) and fun(l) and m[r]!=i){
                    ans.push_back({m[r], i});
                }
            }
        }
        return ans;
    }
};