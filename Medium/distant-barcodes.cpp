// https://leetcode.com/problems/distant-barcodes/

// https://leetcode.com/problems/distant-barcodes/

struct Barcode {
    int value, freq;
    Barcode(int val, int fre) : value(val), freq(fre) {}
    
    bool operator<(const Barcode& temp) const {
        return freq < temp.freq;
    }
};

class Solution {
public:
    
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        
        vector<int>nums(10001, 0);
        for(int x: barcodes) {
            nums[x]++;
        }
        
        priority_queue<Barcode>pq;
        for(int i = 1; i != nums.size(); i++) {
            if(nums[i]) pq.push({i, nums[i]});
        }
        
        Barcode prev {-1,-1}, temp {-1,-1};
        int i = 0, val;
        
        while(!pq.empty())
        {
            temp = pq.top();
            pq.pop();
            
            barcodes[i++] = temp.value;
            
            if(prev.freq >= 1) pq.push(prev);
            if(temp.freq <= 0) continue;
            
            temp.freq--;
            prev = temp;
        }
        
        return barcodes;
    }
};
