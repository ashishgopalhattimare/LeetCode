// https://leetcode.com/problems/string-compression/description/

class Solution {
public:
    int compress(vector<char>& chars) {
        
        char prev;
        bool startChar = true;
        int  digits, times, index = 0;
        for(int i = 0; i < chars.size(); i++) {
            
            // first char input
            if(startChar) {
		// set the default parameters
                prev = chars[i];
                times = 1;
                
                startChar = false;
            }
            else {
                if(prev == chars[i]) {
			// if the prev == current, increment the times
                    times++;
                }
                else {
			// if only one times the prev char has appeared
			// instead of ['a']['1'] make it ['a']
                    if(times == 1) {
                        chars[index++] = prev;
                    }
                    else {
			// put the prev char
                        chars[index++] = prev;
			
			// get the digits in the times variable
                        digits = log10(times) + 1;
			
			// ['a']['1']['2'] make it ['a']
			// put them in the reverse order
                        for(int j = index + digits - 1; j >= index; j--) {
                            chars[j] = '0' + times%10;
                            times/=10;
                        }
			// shift the index to index + digits
                        index += digits;
                    }
			// make current char prev char and reset the times
                    prev = chars[i];
                    times = 1;
                }
            }
            
        }
        
        if(times == 1) {
            chars[index++] = prev;
        }
        else {
            chars[index++] = prev;
            digits = log10(times) + 1;
            for(int j = index + digits - 1; j >= index; j--) {
                chars[j] = '0' + times%10;
                times/=10;
            }
            index += digits;
        }
        
        chars[index] = '\0';
        
        for(int i = 0; i < index; i++) {
            printf("[%c]", chars[i]);
        }
        
        return index;
    }
};
