// https://leetcode.com/problems/sequential-digits/
// Medium

class Solution {
private:
    int DIGITS = 10;
    
public:

    long long getValue(vector<int>& digits) {
        long long res = 0;
        for(int x : digits) res=res*10+x;
        return res;
    }

    void initialSetup(vector<int>& digits, int index)
    {
        for(int i = index, dig = 1; i < DIGITS; i++, dig++) {
            digits[i] = dig;
        }
        return;
    }
    void increment(vector<int>& digits, int index) {
        for(int i = index; i < DIGITS; i++) {
            digits[i]++;
        }
    }

    vector<int> sequentialDigits(int low, int high) {

        vector<int> result, digits(DIGITS, 0);

        int index = DIGITS - (log10(low) + (low<10));

        initialSetup(digits, index);

        long long value;
        while(true) {

            value = getValue(digits);

            if(value > high) break;
            else if(low <= value && value <= high) {
                result.push_back(value);
            }

            if(digits[digits.size()-1] == 9) {
                if(--index >= 1)
                    initialSetup(digits, index);
                else break;
            }
            else increment(digits, index);
        }

        return result;
    }
};