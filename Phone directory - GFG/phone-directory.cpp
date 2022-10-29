//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Node{
public:
    Node* links[26];
    bool flag=false;
    set<string> a;
    int ct=0;
    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    void connect(char ch, Node* node){
        links[ch-'a']=node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void setEnd(){
        flag = true;
    }
    bool isEnd(){
        return flag;
    }
};

class Trie {
public:
    Node* root;
    Trie() {
        root=new Node();
    }
    // tc->O(len)
    void insert(string word) {
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                node->connect(word[i], new Node());
            }
            // moves to the reference trie
            node=node->get(word[i]);
            node->a.insert(word);
        }
    }
    
    vector<vector<string>> search(string word) {
        Node* node=root;
        vector<vector<string>> ans;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                while(i<word.size()){
                    ans.push_back({"0"});
                    i++;
                }
                return ans;
            }else{
                node=node->get(word[i]);
                // cout<<node->a.size()<<endl;
                ans.push_back(vector<string>(node->a.begin(), node->a.end()));
            }
        }
        return ans;
    }
};

class Solution{
public:
    vector<vector<string>> displayContacts(int n, string c[], string s)
    {
        Trie *t=new Trie();
        for(int i=0;i<n;i++){
            // cout<<c[i]<<endl;
            t->insert(c[i]);
        }
        auto ans=t->search(s);
        for(auto &x:ans){
            sort(x.begin(), x.end());
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends