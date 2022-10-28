 public class TreeNode {
     int val;
     TreeNode left;
     TreeNode right;
      TreeNode() {}
     TreeNode(int val) { this.val = val; }
     TreeNode(int val, TreeNode left, TreeNode right) {
         this.val = val;
         this.left = left;
         this.right = right;
     }
 }
 
class Solution {

    public List<Integer> preHelper(TreeNode root, List<Integer> list){

        if(root == null){
            return list;
        }

        preHelper(root.left, list);
        list.add(root.val);
        preHelper(root.right, list);

        return list;
    }



    public List<Integer> inorderTraversal(TreeNode root) {

        List<Integer> list = new ArrayList<>();

        return preHelper(root, list);
        
        
    }
}
