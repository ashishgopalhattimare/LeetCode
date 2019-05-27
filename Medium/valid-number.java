// https://leetcode.com/problems/valid-number/submissions/

class Solution {
    
    public boolean allDigits(String str, int index, int len)
    {
        if(index == len) return false;
        for(int i = index; i < len; i++) {
            if(!Character.isDigit(str.charAt(i))) return false;
        }
        return true;
    }
    
    public boolean afterExpo(String str, int index, int len)
    {
        if(index == len) return false;
        for(int i = index; i < len ; i++) {
            switch(str.charAt(i)) {
                case '+':
                case '-': return allDigits(str, i+1, len);
            }
            if(!Character.isDigit(str.charAt(i))) return false;
        }
        return true;
    }
    
    public boolean afterDeci(String str, int index, int len)
    {
        if(index == len) return false;
        
        for(int i = index; i < len ; i++) {
            if(str.charAt(i) == 'e') return afterExpo(str, i+1, len);
            else if(!Character.isDigit(str.charAt(i))) return false;
        }
        return true;
    }
    
    public boolean baseValue(String str, int index, int len)
    {
        if(index == len) return false;
        
        for(int i = index; i < len; i++) {
            switch(str.charAt(i)) {
                case 'e': return afterExpo(str, i+1, len);
                case '.': return afterDeci(str, i+1, len);
            }
            if(!Character.isDigit(str.charAt(i)))
                return false;
        }
        return true;
    }
    
    public boolean isNumber(String s) {
        
        String str = s.trim();
        
        for(int i = 0; i < str.length(); i++) {
            if(Character.isDigit(str.charAt(i))) continue;
            
            switch(str.charAt(i)) {
                case 'e':
                case '-':
                case '+':
                case '.': break;
                default : return false; 
            }
        }
        try {
            Double x = Double.parseDouble(str);
            return true;
        }
        catch(Exception e){}
        
        return false;
        
//         if(str.length() == 1) {
//             return Character.isDigit(str.charAt(0));
//         }
        
//         if(str.length() == 0) return false;
//         switch(str.charAt(0)) {
//             case 'e': return false;
//             case '+':
//             case '-': str = str.substring(1, str.length());
//         }
        
//         return baseValue(str, 0, str.length());
    }
}
