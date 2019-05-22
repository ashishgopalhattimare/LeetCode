// https://leetcode.com/contest/weekly-contest-131/problems/camelcase-matching/

class Solution {

    public List<Boolean> camelMatch(String[] queries, String pattern) {

        List<Boolean> result = new ArrayList<Boolean>();

        List<String> arr = new ArrayList<>(Arrays.asList(pattern.split("")));

        int slow, high;

        boolean valid;
        for(String str : queries) {
            valid = true;
            slow = 0;

            for(String temp : arr) {
                high = str.indexOf(temp, slow); // get the index of first string in array

                if(high == -1) { valid = false; }

                for(int i = slow; i < high && valid; i++) {
                    if(str.charAt(i) < 'a' || str.charAt(i) > 'z') { valid = false;
                        break;
                    }
                }

                slow = high + temp.length();
                if(!valid) break;
            }

            for(int i = slow; i < str.length() && valid; i++) {
                if(str.charAt(i) >= 'A' && str.charAt(i) <= 'Z') valid = false;
            }
            result.add(valid);
        }
        return result;
    }
}
