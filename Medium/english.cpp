#include <bits/stdc++.h>

using namespace std;

int CPS(string& a, string& b, int s1, int s2, int e1, int e2, int fi)
{
	int count = 0;
	for(int i = s1, j = s2; i != e1 && j != e2; i+=fi, j+=fi) {
		if(a[i] == b[j]) count++;
		else break;
	}
	return count;
}

int main()
{
	int t, n;

	cin >> t;
	while(t--)
	{
		cin >> n;
		vector<string>str(n);
        unordered_map<string,int>freq;
        
		for(int i = 0; i < n; i++) {
			cin >> str[i];
			freq[str[i]]++;
		}

		vector<vector<string>>strPair;
		for(int i = 0; i < n; i++) {
			for(int j = i+1; j < n; j++) {
				strPair.push_back({str[i], str[j]});
			}
		}

		sort(strPair.begin(), strPair.end(), [](vector<string>& a, vector<string>& b) {
			int p1 = CPS(a[0], a[1], 0, 0, a[0].size(), a[1].size(), 1);
			int s1 = CPS(a[0], a[1], a[0].size()-1, a[1].size()-1, -1, -1, -1);

			int p2 = CPS(b[0], b[1], 0, 0, b[0].size(), b[1].size(), 1);
			int s2 = CPS(b[0], b[1], b[0].size()-1, b[1].size()-1, -1, -1, -1);

			return (min(p1,s1) > min(p2,s2));
		});
		
		long long int totalSum = 0;
		for(vector<string>& a : strPair) {
		    
		    if(a[0] == a[1] && freq[a[0]] < 2) continue;
		    
		    if(freq[a[0]] && freq[a[1]]) {
		        
		        int prefix = CPS(a[0], a[1], 0, 0, a[0].size(), a[1].size(), 1);
			    int suffix = CPS(a[0], a[1], a[0].size()-1, a[1].size()-1, -1, -1, -1);
		    
		        long long int minim = min(prefix, suffix);
		        minim *= minim;
		        
		        totalSum += minim;
		        
		        freq[a[0]]--; freq[a[1]]--;
		    }
		}
		cout << totalSum << endl;
	}
	return 0;
}