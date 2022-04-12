class Solution {
public:
    int openLock(vector<string>& de, string t) {
        vector<int> vis(1e5+10, 0);
        set<string> d(de.begin(), de.end());
        queue<string> q;
        q.push("0000");
        vis[0]=1;
        int l=0;
        while(q.size()){
            int s=q.size();
            while(s--){
                auto f=q.front();
                q.pop();
                if(f==t){
                    return l;
                }
                if(d.count(f))continue;
                for(int i=0;i<4;i++){
                    string r=f;
                    if(r[i]=='0'){
                        r[i]='9';
                    }else{
                        r[i]=(char)(((r[i]-'0')-1)+'0');
                    }
                    if(!vis[stoi(r)]){
                        q.push(r);
                        vis[stoi(r)]=1;
                    }
                    r=f;
                    if(r[i]=='9'){
                        r[i]='0';
                    }else{
                        r[i]=(char)(((r[i]-'0')+1)+'0');
                    }
                    if(!vis[stoi(r)]){
                        q.push(r);
                        vis[stoi(r)]=1;
                    }
                }
            }
            l++;
        }
        return -1;
    }
};