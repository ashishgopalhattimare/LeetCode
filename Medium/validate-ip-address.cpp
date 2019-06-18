// https://leetcode.com/problems/validate-ip-address/
// Medium

class Solution {
    public String validIPAddress(String IP) {
        
        boolean formatted = true;
        if(IP.contains(".")) { // IPv4
            String[] sets = IP.split("[.]");
            if(sets.length == 4 && IP.charAt(IP.length()-1) != '.') {
                for(String x : sets) {
                    if(x.length() == 0) formatted = false; // if empty x
                    else {
                        try {
                            int i = Integer.parseInt(x); // not a digit
                            if(i >= 256 || !Character.isDigit(x.charAt(0))) // 1.1.-1.+1 or greater than 255
                                formatted = false;
                            else if(x.length() > 1 && x.charAt(0) == '0') // 00.0.0.0
                                formatted = false;
                        }
                        catch(Exception e) { System.out.println("asd"); formatted = false; }
                    }
                    if(!formatted) break;
                }
                if(formatted) return "IPv4";
            }
        }
        else { // IPv6
            String[] sets = IP.split(":");
            if(sets.length == 8 && IP.charAt(IP.length()-1) != ':') {
                for(String x : sets) {
                    if(x.length() == 0 || x.length() > 4) formatted = false;
                    else {
                        for(int i = 0; i < x.length(); i++) {
                            char c = Character.toLowerCase(x.charAt(i));
                            if(!Character.isDigit(c) && (c < 'a' || c > 'f')) { // fGea:xxxx:
                                formatted = false;
                                break;
                            }
                        }
                    }
                    if(!formatted) break;
                }
                if(formatted) return "IPv6";
            }
        }
        
        return "Neither";
    }
}
