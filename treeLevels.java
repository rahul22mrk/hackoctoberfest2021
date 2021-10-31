import java.util.*;

public class treeLevel {
    static Node root = null;

    class Node {
        int data;
        Node right;
        Node left;

        Node(int data) {
            this.data = data;
            right = left = null;
        }
    }

    public Node insert(Node node, int data) {
        if (node == null) {
            return new Node(data);
        }

        if (data < node.data) {
            if (node.left != null) {
                insert(node.left, data);
            } else
                node.left = new Node(data);
        } else if (data > node.data) {
            if (node.right != null) {
                insert(node.right, data);
            } else
                node.right = new Node(data);
        }
        return node;
    }

    public void add(int data) {
        root = insert(root, data);
    }

    int height(Node root) {
        if (root == null) {
            return 0;
        } else {
            int lh = height(root.left);
            int rh = height(root.right);
            if (lh > rh) {
                return (lh + 1);
            } else
                return (rh + 1);

        }

    }

    void printLevel() {
        int h = height(root);
        int i = 1;
        for (i = 1; i <= h; i++) {
            printGlevel(root, i);

        }

    }

    void printGlevel(Node root, int i) {
        if (root == null) {
            return;
        }
        if (i == 1) {
            System.out.println(root.data + " ");
        } else if (i > 1) {
            printGlevel(root.left, i - 1);
            printGlevel(root.right, i - 1);
        }
    }

    public static void main(String args[]) {
        treeLevel bt = new treeLevel();

        bt.add(1);
        bt.add(2);
        bt.add(3);
        bt.add(4);
        bt.add(5);
        System.out.println("Height of tree: " + bt.height(root));
        bt.printLevel();

    }
}
