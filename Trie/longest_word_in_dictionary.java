// https://leetcode.com/problems/longest-word-in-dictionary/

class Trie
{
    private Node[] ar;

    public Trie() {
        ar = new Node[26];
        for(int i = 0; i < 26; i++) {
            ar[i] = null;
        }
    }

    public void testcase(String word) {

        int index = (int)word.charAt(0) - 97;
        if(ar[index] == null) {
            ar[index] = new Node();
        }
        ar[index].traversePath(1, word);
    }

    public void recursive(Wrapper wrapper) {
        for(int i = 0; i < 26; i++) {
            if(ar[i] != null && ar[i].end == true) {
                ar[i].recursive(wrapper, (char)(i+97));
            }
        }
    }
}

class Node
{
    private Node[] ar;
    public boolean end;

    public Node() {
        ar = new Node[26];
        for(int i = 0; i < 26; i++) {
            ar[i] = null;
        }
        end = false;
    }

    public void traversePath(int index, String word)
    {
        if(index == word.length()) {
            end = true;
        }
        else {
            int ind = (int)word.charAt(index) - 97;

            if(ar[ind] == null) {
                ar[ind] = new Node();
            }
            ar[ind].traversePath(index+1, word);
        }
    }

    public void recursive(Wrapper wrapper, char c) {
        wrapper.append(c);
        if(wrapper.getString().length() < wrapper.length()) {
            wrapper.setString(wrapper.toString());
        }

        for(int i = 0; i < 26; i++) {
            if(ar[i] != null && ar[i].end == true) {
                ar[i].recursive(wrapper, (char)(i+97));
            }
        }
        wrapper.removeEnd();
    }
}

class Wrapper
{
    private StringBuilder builder;
    private String str;

    public Wrapper() {
        builder = new StringBuilder("");
        str = "";
    }

    public void setString(String str) {
        this.str = str;
    }
    public String getString() {
        return str;
    }

    public void append(char c) {
        builder.append(c);
    }
    public int length() {
        return builder.length();
    }
    public String toString() {
        return builder.toString();
    }

    public void removeEnd() {
        if(builder.length() > 0)
        builder.deleteCharAt(builder.length()-1);
    }
}

class Solution {
    public String longestWord(String[] words) {

        Wrapper wrapper = new Wrapper();

        Trie tree = new Trie();

        for(int i = 0; i < words.length; i++) {
            tree.testcase(words[i]);
        }

        tree.recursive(wrapper);

        return wrapper.getString();
    }
}