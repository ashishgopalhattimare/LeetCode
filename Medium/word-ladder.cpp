// https://leetcode.com/problems/word-ladder/
// Medium, Amazon SDE II
// TLE, optimization required (Generic String for all single change string approach)

struct Node {
    string word;
    bool visited;
    vector<int>neighbours;

    Node(string word) : word(word), visited(false) {}
};

class Solution {
public:

    int minLength, len;

    bool difference(string x, string y) {
        int diff = 0;
        for(int i = 0; i < x.length() && diff < 2; i++) {
            if(x[i] != y[i]) diff++;
        }

        return (diff == 1);
    }

    void calculateBFS(int source, vector<Node*>nodes, int l, string endWord) {

    	if(nodes[source]->visited || l > minLength) return;

    	if(nodes[source]->word == endWord) {
            minLength = min(minLength, l);
            return;
    	}

    	nodes[source]->visited = 1;
    	for(int i = 0; i < nodes[source]->neighbours.size(); i++) {
    		calculateBFS(nodes[source]->neighbours[i], nodes, l+1, endWord);
    	}
    	nodes[source]->visited = 0;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_map<string,int>indexmap;

        vector<Node*>nodes(wordList.size());
        for(int i = 0; i < nodes.size(); i++) {
            nodes[i] = new Node(wordList[i]);
            indexmap[wordList[i]] = i;
        }

        for(int i = 0; i < wordList.size(); i++) {
            string curr = wordList[i];
            for(int j = i+1; j < wordList.size(); j++) {
                string next = wordList[j];

                if(difference(curr, next)) {
                    nodes[i]->neighbours.push_back(j);
                    nodes[j]->neighbours.push_back(i);
                }
            }
        }

        if(indexmap.find(endWord) == indexmap.end()) return {};

        minLength = INT_MAX;
        if(indexmap.find(beginWord) != indexmap.end()) { // start is already in the wordList
            calculateBFS(indexmap[beginWord], nodes, 1, endWord);
        }
        else { // not in the wordList
            for(int i = 0; i < wordList.size(); i++) {
            	if(difference(wordList[i], beginWord)) {
                    calculateBFS(indexmap[wordList[i]], nodes, 2, endWord);
            	}
            }
        }
        
        return (minLength == INT_MAX) ? 0 : minLength;
    }
};
