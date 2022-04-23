class Solution {
public:

    // Encodes a URL to a shortened URL.
    map<string, string> m;
    string encode(string longUrl) {
        int s=0;
        for(auto x:longUrl){
            s+=(int)(x);
        }
        string ans=to_string(s);
        m[ans]=longUrl;
        return ans;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return m[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));