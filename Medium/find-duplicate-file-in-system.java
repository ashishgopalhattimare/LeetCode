// https://leetcode.com/problems/find-duplicate-file-in-system/
// Medium, Java

class Solution {
    public List<List<String>> findDuplicate(String[] paths) {

        List<List<String>> result = new ArrayList<>();
        HashMap<String, List<String>>hashmap = new HashMap<>();

        for(String directory : paths) {
            String[] content = directory.split(" ");
            for(int i = 1; i < content.length; i++) {
                String file = content[i];
                int bracket = file.indexOf('(') + 1;
                String para = file.substring(bracket, file.length()-1);

                String dir = content[0]+ "/" + file.substring(0, bracket-1);

                if(!hashmap.containsKey(para)) {
                    hashmap.put(para, new ArrayList<>());
                }
                List<String>list = hashmap.get(para); // get List<String> reference from the HashMap<String,List>
                list.add(dir); // add dir to para key
            }
        }

        for(List<String> list : hashmap.values()) {
            if(list.size() > 1) // If length of > 1 : duplicate present
                result.add(list);
        }

        return result;
    }
}
