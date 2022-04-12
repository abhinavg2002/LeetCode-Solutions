class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wl) {
        unordered_set<string> us(begin(wl), end(wl)), vis;
        queue<string> q;
        q.push(beginWord);
        int l=0;
        if(beginWord==endWord)return 0;
        vis.insert(beginWord);
        while(q.size()){
            int s=q.size();
            l++;
            while(s--){
                auto word=q.front();
                q.pop();
                if(word==endWord)return l;
                string t=word;
                for(auto &x:t){
                    char m=x;
                    for(char c='a';c<='z';c++){
                        x=c;
                        if(us.count(t) and vis.count(t)==0){
                            q.push(t);
                            vis.insert(t);
                        }
                    }
                    x=m;
                }
            }
        }
        return 0;
    }
};