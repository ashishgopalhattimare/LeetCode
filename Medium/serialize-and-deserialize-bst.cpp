// https://leetcode.com/problems/serialize-and-deserialize-bst/
// Medium

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Codec {

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        
        Queue<TreeNode> qq = new LinkedList<>();
        TreeNode temp;
        
        qq.add(root);
        
        StringBuilder result = new StringBuilder("[");
        boolean rootNode = true;
        
        while(qq.size() != 0) {
            temp = qq.remove();
            
            if(rootNode == false) result.append(',');
            
            // append this state, and ignore child
            if(temp == null) result.append("null");
            
            // insert both left and right child node
            else {
                result.append(temp.val);
                qq.add(temp.left); qq.add(temp.right);
            }
            
            rootNode = false;
        }
        return result.append("]").toString();
    }
    
    public int toInt(String x) { return Integer.parseInt(x); }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        
        String[] element = data.substring(1, data.length()-1).split("[,]");
        int n = element.length;
        
        Queue<TreeNode> qq = new LinkedList<>();
        
        if(element[0].equals("null")) return null;
        
        TreeNode result = new TreeNode(toInt(element[0]));
        qq.add(result);
        
        TreeNode head;
        for(int i = 1; i < n; i+=2) {
            head = qq.remove();
            
            if(i < n) { // left node place
                if(!element[i].equals("null")) {
                    head.left = new TreeNode(toInt(element[i]));
                    qq.add(head.left);
                }
            }
            if(i+1 < n) { // right node place
                if(!element[i+1].equals("null")) {
                    head.right = new TreeNode(toInt(element[i+1]));
                    qq.add(head.right);
                }
            }
        }
        
        return result;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.deserialize(codec.serialize(root));