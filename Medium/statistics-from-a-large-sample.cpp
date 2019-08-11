// https://leetcode.com/problems/statistics-from-a-large-sample/
// Medium, Weekly Contest 141

class Solution {
public:
    
    int valueAt(vector<int>& count, int index) {
        for(int i = 0; i < count.size(); i++) {
            if(count[i]) {
                if(count[i] >= index) return i;
                else 
                    index -= count[i];
            }
        }
        return 0;
    }
    
    vector<double> sampleStats(vector<int>& count) {
        int minim = INT_MAX, maxim = INT_MIN;
        long long int average = 0, total = 0;
        int mode = -1;
        int freq = INT_MIN;
        
        for(int i = 0; i < count.size(); i++) {
            
            if(count[i]) {
                minim = min(minim, i);
                maxim = max(maxim, i);

                average += (count[i]*i);
                total += count[i];

                if(freq < count[i]) {
                    freq = count[i];
                    mode = i;
                }
            }
        }
        
        double median = valueAt(count, total/2+1);
        if(total % 2 == 0) { // if even
            median += valueAt(count, total/2);
            median/=2;
        }
        
        return {minim, maxim, average/(total*1.0), median, mode};
    }
};
