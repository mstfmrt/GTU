public class Main {
    public static void main(String[] args) {
        BinaryTree<Integer> binaryTree = new BinaryTree<Integer>(new BinaryTree.Node<>(0));
        binaryTree.root.left = new BinaryTree.Node<>(0);
        binaryTree.root.right = new BinaryTree.Node<>(0);
        binaryTree.root.left.left = new BinaryTree.Node<>(0);
        binaryTree.root.left.right = new BinaryTree.Node<>(0);
        binaryTree.root.right.right = new BinaryTree.Node<>(0);



        Object[] array = {4,3,1,7,5,2};
        // Printing the inorder traversal of the binary tree.
        System.out.println("Array passed to funtion is {4,3,1,7,5,2}\n");

        BinaryTree newbinary = hw7.bstCreator(binaryTree, array);
        System.out.println("printing the first Tree");

        StringBuilder sb = new StringBuilder();
        hw7.traversePreOrder(sb,"","",binaryTree.root);
        System.out.println(sb);


        BinaryTree<Integer> binaryTree2 = new BinaryTree<Integer>(new BinaryTree.Node<>(0));
        binaryTree2.root.left = new BinaryTree.Node<>(0);
        binaryTree2.root.right = new BinaryTree.Node<>(0);
        binaryTree2.root.left.left = new BinaryTree.Node<>(0);
        binaryTree2.root.left.right = new BinaryTree.Node<>(0);
        binaryTree2.root.right.right = new BinaryTree.Node<>(0);
        binaryTree2.root.left.left.right = new BinaryTree.Node<>(0);
        binaryTree2.root.left.right.left = new BinaryTree.Node<>(0);

        Object[] array2 = {23,12,6,45,84,25,68,35};
        // Printing the inorder traversal of the binary tree.
        System.out.println("Array passed to funtion is {23,12,6,45,84,25,68,35}\n");

        BinaryTree newbinary2 = hw7.bstCreator(binaryTree2, array2);
        System.out.println("printing the second Tree");

        StringBuilder sb2 = new StringBuilder();
        hw7.traversePreOrder(sb2,"","",binaryTree2.root);
        System.out.println(sb2);

    }




}
