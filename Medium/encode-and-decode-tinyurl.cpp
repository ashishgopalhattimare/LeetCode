// https://leetcode.com/problems/encode-and-decode-tinyurl/
// Medium

#define MAX_LEN 62

class Solution {
public:
    
    unordered_map<string, string>map;
    string ASCII = "dVa7F8TxDUs4RQ9Gpc5Bgn13hi2WwKyMlmoNALzqrHtJuvCEbIkPOSjXYZ0e6f";
        
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        
        srand (time(NULL));
        
        string hash = "";
        for(int i = 0; i < MAX_LEN; i++) {
            hash.push_back(ASCII[rand()%MAX_LEN]);
        }
        map[hash] = longUrl;
        return hash;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return map[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
