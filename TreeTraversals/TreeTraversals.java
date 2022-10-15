package TreeTraversals;

public final class TreeTraversals {

    /*
     * PreOrder traversal
     * 1. Visit the root
     * 2. Traverse the left subtree i.e Call preorderTraversal(left -> subtree)
     * 3. Traverse the right subtree i.e Call preorderTraversal(right -> subtree)
     */

    public static void preorderTraversal(TreeNode n) {
        if(n == null)
            return;
        System.out.println(n.value+" ");
        preorderTraversal(n.left);
        preorderTraversal(n.right);
    }

    /*
     * PostOrder traversal
     * 1. Traverse the left subtree i.e Call postorderTraversal(left -> subtree)
     * 2. Traverse the right subtree i.e Call postorderTraversal(right -> subtree)
     * 3. Visit the root
     */

    public static void postorderTraversal(TreeNode n) {
        if(n == null)
            return;
        postorderTraversal(n.left);
        postorderTraversal(n.right);
        System.out.println(n.value+" ");
    }

    /*
     * InOrder traversal
     * 1. Traverse the left subtree i.e Call inorderTraversal(left -> subtree)
     * 2. Visit the root
     * 3. Traverse the right subtree i.e Call inorderTraversal(right -> subtree)
     */

    public static void inorderTraversal(TreeNode n) {
        if(n == null)
            return;
        inorderTraversal(n.left);
        System.out.println(n.value+" ");
        inorderTraversal(n.right);
    }

    public static TreeNode createData() {

        /*
        *              a
        *             / \
        *            b   g
        *           / \
        *          c   d
        *         /
        *        e
        *        \
        *         f
        */
        
        TreeNode a = new TreeNode("a");
        TreeNode b = new TreeNode("b");
        TreeNode c = new TreeNode("c");
        TreeNode d = new TreeNode("d");
        TreeNode e = new TreeNode("e");
        TreeNode f = new TreeNode("f");
        TreeNode g = new TreeNode("g");

        a.left = b;
        a.right = g;
        b.left = c;
        b.right = d;
        c.left = e;
        e.right = f;

        return a;
    }

    public static void main(String[] args) {
        TreeNode root = createData();
        preorderTraversal(root);
        postorderTraversal(root);
        inorderTraversal(root);
    } 

}




