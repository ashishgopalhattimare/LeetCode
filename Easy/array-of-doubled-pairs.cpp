// https://leetcode.com/problems/array-of-doubled-pairs/
// Medium, Array, HashTable

class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        
        if(A.size() == 0) return 1;
        
        map<int, int>mymap; // Hash
        unordered_set<int>set; // Hash
        
        for(int i = 0; i < A.size(); i++) {
            mymap[A[i]]++;
            set.insert(A[i]);
        }
        
        sort(A.begin(), A.end(), [](int a, int b) { // Array
            if(abs(a) == abs(b)) {
                return a < b;
            }
            return abs(a) < abs(b);
        });
        
        int a, b;
        
        // 0 0 0 0 0 0
        // 1 2 4 4 8 16
        // 0 0 -1 -2 1 2
        for(int i = 0, j = 0; j < A.size()/2; i++) {
            b = 2*(a = A[i]);
            
            if(set.find(a) == set.end()) continue;
            if(set.find(b) == set.end()) return 0;
            
            if(!(--mymap[a])) set.erase(a);
            if(!(--mymap[b])) set.erase(b);
            
            if(a == 0) i++; // if a == 0, double increment, because next is also 0
            j++;
        }
        return 1;
    }
};
