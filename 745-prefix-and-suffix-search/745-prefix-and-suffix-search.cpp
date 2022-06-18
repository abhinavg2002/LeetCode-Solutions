class Node{
public:
    // because we have to insert { also
    Node* links[27];
    int id=0;
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
            node->id=idx;
        }
    }
    
    int search(string word) {
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                return -1;
            }
            node=node->get(word[i]);
        }
        return node->id;
    }
};

class WordFilter {
public:
    Trie t;
    WordFilter(vector<string>& words) {
        string s="";
        int id=0;
        for(auto &x:words){
            s="{"+x;
            t.insert(s, id);
            for(int i=x.size()-1;i>=0;i--){
                s=x[i]+s;
                t.insert(s, id);
            }
            id++;
        }
    }
    
    int f(string prefix, string suffix) {
        return t.search(suffix+"{"+prefix);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */