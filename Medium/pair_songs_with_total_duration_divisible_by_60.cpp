class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int result = 0;

        unordered_map<int, int> freq;

        for(int x : time) freq[x]++;

        for(auto itr1 = freq.begin(); itr1 != freq.end(); itr1++) {
            
            if((itr1->first + itr1->first) % 60 == 0)
            result += ((itr1->second*(itr1->second-1))/2);
            
            auto temp = itr1;
            temp++;
            for(auto itr2 = temp; itr2 != freq.end(); itr2++) {
                if((itr1->first + itr2->first) % 60 == 0)
                result += (itr1->second * itr2->second);
            }
        }
        
        return result;
    }
};