class Node{
public:
    Node* links[26];
    vector<int> id;
    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    void connect(char ch, Node* node){
        links[ch-'a']=node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
};

class Trie {
public:
    Node* root;
    Trie() {
        root=new Node();
    }
    // tc->O(len)
    void insert(string word, int idx) {
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                node->connect(word[i], new Node());
            }
            // moves to the reference trie
            node=node->get(word[i]);
            // har trie me saare index store karlo
            node->id.push_back(idx);
        }
    }
    
    vector<int> search(string word) {
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                return {};
            }
            node=node->get(word[i]);
        }
        return node->id;
    }
};
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& p, string sw) {
        Trie t;
        for(int i=0;i<p.size();i++){
            t.insert(p[i], i);
        }
        vector<vector<string>> ans;
        vector<set<int>> v;
        string s;
        for(int i=0;i<sw.size();i++){
            s.push_back(sw[i]);
            vector<int> a=t.search(s);
            // itna prefix tk ke idx recover karo set me unki string daalo
            // and top 3 lexi string ans me daal do
            set<string> ta;
            for(auto x:a){
                ta.insert(p[x]);
            }
            vector<string> y;
            for(auto x:ta){
                y.push_back(x);
                if(y.size()==3)break;
            }
            ans.push_back(y);
        }
        return ans;
    }
};