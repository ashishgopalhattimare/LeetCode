#include <bits/stdc++.h>
#include <string>

// https://practice.geeksforgeeks.org/problems/extract-the-number-from-the-string/0

using namespace std;

int main(int argc, char* argv[])
{
	int t;
	bool digFound, validNum;
	long long int maxValue;
	char str[10001];
	string maxString, number;

	scanf("%d ", &t);
	while(t--) {
	    scanf("%[^\n]%*c", str);

		maxValue = -1;
		number = "";
		
		maxString = "-1";
        validNum = true;
		digFound = false;
		for(int i = 0; str[i] != '\0'; i++) {
			if(isdigit(str[i])) {
			    
			    if(str[i] == '9') {
			        validNum = false;
			        continue;
			    }
			    
			    if(validNum) {
			        number.push_back(str[i]);
    				digFound = true;   
			    }
			}
			else {
				if(digFound && validNum && number.length()) {
					if(maxValue < stoll(number)) {
        		        maxValue = stoll(number);
        		        maxString = number;
        		    }
				}
				number = "";
				validNum = true;
			}
		}

		if(digFound && validNum && number.length()) {
		    if(maxValue < stoll(number)) {
		        maxValue = stoll(number);
		        maxString = number;
		    }
		}

		cout << maxString << endl;
	}

	return 0;
}