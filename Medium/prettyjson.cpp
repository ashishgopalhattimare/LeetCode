// https://www.interviewbit.com/problems/pretty-json/

string addTab(int x) {
    string spaces = "";
    for(int i = 0; i < x; i++) {
        spaces.push_back('\t');
    }
    return spaces;
}

vector<string> Solution::prettyJSON(string A) {
    
    vector<string> result;
    
    int tabs = 0;
    bool statementAdded = false;
    string row = "";
    
    bool reduced;
    
    for(int i = 0; i < A.length(); i++) {
        
        if(A[i] == ' ' && !statementAdded) continue;
        
        if(A[i] == '[' || A[i] == '{') {
            if(row.length() && statementAdded) {
                result.push_back(row);
                row = addTab(tabs);
            }
            row.push_back(A[i]);
            
            result.push_back(row);
            
            row = addTab(++tabs);
            
            statementAdded = false;
        }
        else if(A[i] == ',') {
            
            if(!statementAdded) {
                result[result.size()-1].push_back(',');
            }
            else {
                row.push_back(',');
                result.push_back(row);
            }
            
            row = addTab(tabs);
            
            statementAdded = false;
        }
        else if(A[i] == ']' || A[i] == '}') {
            
            if(row.length() && statementAdded) {
                result.push_back(row);
            }
            row = addTab(--tabs);
            
            row.push_back(A[i]);
            
            result.push_back(row);
            row = addTab(tabs);
            
            statementAdded = false;
        }
        else {
            statementAdded = true;
            row.push_back(A[i]);
        }
    }
    
    return result;
}