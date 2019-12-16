// https://www.codechef.com/NOV19B/problems/WEIRDO/

// Do the division and power in logorithm form to solve in limited range

#include <bits/stdc++.h>
#include <decimal/decimal>

using namespace std;

static int matrix[100000][26];
static int id = 1;

bool isConso(char x)
{
	switch(x)
	{
		case 'a': case 'e': case 'i': case 'o': case 'u': return 0;
		default : return 1;
	}
}

bool whoseRecipe(string& str)
{
	int size = str.length();
	
	if(isConso(str[0]) && isConso(str[1])) return false;
	
	for(int i = 2; i < size; i++) {
	    if( (isConso(str[i-2]) || isConso(str[i-1])) && isConso(str[i]) ) {
	        return false;
	    }
	}
	return true;
}

long double compute(vector<string>& arr)
{
	vector<long double>freq(26, 0), appear(26, 0);
	int size = arr.size();

	for(int i = 0; i < size; i++) {
		for(char k : arr[i]) {
			freq[k-'a']++;
			matrix[i][k-'a'] = id;
		}
	}

	for(int i = 0; i < size; i++) {
		for(int j = 0; j < 26; j++) {
			if(matrix[i][j] == id) 
				appear[j]++;
		}
	}
    
    long double result = 0;
	
	for(int i = 0; i < 26; i++) {
		if(freq[i]) {
		    result += (log(appear[i]) - log(freq[i]) * size);
		}
	}
	
	id++;
	return result;
}

int main()
{
	int t, n;
	string recipe;

	cin >> t;
	
	cout << fixed;
	while(t--)
	{
		cin >> n;

		vector<string>alice, bob;

		for(int i = 0; i != n; i++) {
			cin >> recipe;

			if(whoseRecipe(recipe)) {
				alice.push_back(recipe);
			}
			else {
				bob.push_back(recipe);
			}
		}
		
		long double a1 = compute(alice);
		long double b1 = compute(bob);
		
		long double result = exp(a1 - b1);
		
		if(result > 10000000) printf("Infinity\n");
		else 
		cout << setprecision(7) << result << endl;
		
	}
	return 0;
}