/**
 * "This class creates a binary search tree from a sorted array."
 *
 * The class is recursive because it calls itself
 */
import java.util.Arrays;

public class hw7 {
    private BinaryTree.Node root;

    static class Int{
        int i;

        public Int() {
            this.i = 0;
        }
    }
    /**
     * We create a binary search tree from a sorted array by recursively inserting the middle element of the array into the
     * tree
     *
     * @param binaryTree The binary tree that we want to convert to a BST.
     * @param array The array of elements that need to be inserted into the tree.
     * @return A BinaryTree object.
     */
    static BinaryTree bstCreator(BinaryTree binaryTree, Object[] array){
        Int index = new Int();
        Arrays.sort(array);
        inorderTraversal(binaryTree.root,array,index);

        return new BinaryTree(binaryTree.root);
    }

    /**
     * "If the node is not null, recursively call the function on the left node, then set the node's data to the next
     * element in the array, then recursively call the function on the right node."
     *
     * The function is recursive because it calls itself
     *
     * @param node The node to start the traversal from.
     * @param array The array that contains the elements in sorted order.
     * @param index This is a class that contains an integer. This is used to keep track of the index of the array.
     */
    static void inorderTraversal(BinaryTree.Node node, Object[] array, Int index)
    {
        if (node == null)
            return;


        inorderTraversal(node.left, array, index);

        node.data = array[index.i];
        index.i++;

        inorderTraversal(node.right, array, index);
    }



    /**
     * If the node is not null, print the node, then recursively call the function on the left and right nodes
     *
     * @param sb StringBuilder object to which the tree will be appended
     * @param padding This is the padding that is added to the left of the node.
     * @param pointer the pointer to the current node
     * @param node the node to be printed
     */
    static public void traversePreOrder(StringBuilder sb, String padding, String pointer, BinaryTree.Node node) {
        if (node != null) {
            sb.append(padding);
            sb.append(pointer);
            sb.append(node.data);
            sb.append("\n");

            StringBuilder paddingBuilder = new StringBuilder(padding);
            paddingBuilder.append("│  ");

            String paddingForBoth = paddingBuilder.toString();
            String pointerForRight = "└──";
            String pointerForLeft = (node.right != null) ? "├──" : "└──";

            traversePreOrder(sb, paddingForBoth, pointerForLeft, node.left);
            traversePreOrder(sb, paddingForBoth, pointerForRight, node.right);
        }
    }
}
