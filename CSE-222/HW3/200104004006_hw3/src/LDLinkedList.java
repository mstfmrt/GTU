/**
 * A doubly linked list that uses a node class to store data and a reference to the next node
 */

import java.util.AbstractList;
import java.util.List;


/**
 * A linked list that use "lazy deletion strategy"
 * A linked list that use a data structure that consists of a sequence of nodes. Each node contains a data item and a reference
 *
 * to the next node
 */
public class LDLinkedList<E> extends AbstractList<E> implements List<E>, Iterable<E> {

    private Node<E> head;
    private int size =0;
    private static LDLinkedList usable = new LDLinkedList();

    @Override
    public E get(int index) {
        Node<E> currentNode = head;
        if (index >= size || index < 0){
            throw new IndexOutOfBoundsException();
        }

        if (index <= size && index >= 0) {
            for (int i = 0; i < index; i++) {
                currentNode = currentNode.next;
            }
        }

        return currentNode.data;
    }

    @Override
    public int size() {
        int size = 0;
        Node currentNode = head;
        while(currentNode != null){
            size++;
            currentNode = currentNode.next;
        }
        return size;
    }


    /**
     * Add a new node to the beginning of the list
     * @param data The data to be added to the list.
     */
    public void addFirst(E data) {
        head = new Node<>(data, head);
        size++;
    }


    /**
     * Add a new node after the given node
     * @param node The node after which the new node is to be inserted.
     * @param data The data to be added to the list.
     */
    private void addAfter(Node<E> node, E data) {
        node.next = new Node<>(data, node.next);
        size++;
    }

    /**
     * If the data is in the list, remove it and return true. Otherwise, return false
     *
     * @param data The data to be added to the list.
     * @return Nothing
     */
    public boolean add(E data){
        Node<E> currentNode = head;
        Node<E> temp = usable.head;
        if(this.size()==0){
            if (temp == null)
                addFirst(data);
            else {
                if (temp.data.equals(data)){
                    head = temp;
                    usable.head = temp.next;
                    head.next = null;
                    return true;
                }
                for (int i=0; i< usable.size;i++){
                    if (temp.next.data.equals(data)){
                         head = temp.next;
                         temp.next = temp.next.next;
                         head.next = null;
                         return true;
                    }
                }
                addFirst(data);
            }

        }
        else{
            while(currentNode.next != null)
                currentNode = currentNode.next;
            if (temp == null)
                addAfter(currentNode,data);
            else{
                if (temp.data.equals(data)){
                    currentNode = temp;
                    usable.head = temp.next;
                    currentNode.next = null;
                    return true;
                }
                for (int i=0; i< usable.size;i++){
                    if (temp.next.data.equals(data)){
                        currentNode = temp.next;
                        temp.next = temp.next.next;
                        currentNode.next = null;
                        return true;
                    }
                }
                addAfter(currentNode,data);
            }

        }

        return true;
    }



    /**
     * Given a list and a node, link the node to the end of the list
     * @param list the list to be linked
     * @param n The node to be linked to the list.
     * @return Nothing is being returned.
     */
    public boolean link(LDLinkedList list, Node n){
        Node<E> currentNode = list.head;
        while(currentNode != null)
            currentNode = currentNode.next;
        currentNode = n;
        list.size++;
        return true;
    }

    /**
     * Remove the element at the specified index
     *
     * @param index The index of the element to remove.
     * @return The data of the removed node.
     */
    public E remove(int index ){
        Node<E> currentNode = head;
        Node<E> previousNode = currentNode;
        if (index >= size || index < 0){
            throw new IndexOutOfBoundsException("error");
        }


        if (index == 0)
            removeFirst();
        else{
            for (int i = 0; i < index; i++) {
                previousNode = currentNode;
                currentNode = currentNode.next;
            }
            previousNode.next = currentNode.next;
            size--;
        }

        link(usable,currentNode);

        return currentNode.data;
    }


    /** Remove the first node from the list
     @return The removed node's data or null if the list is empty
     */
    private E removeFirst() {
        Node<E> temp = head;
        if (head != null)
            head = head.next;


        if (temp != null) {
            size--;
            return temp.data;
        } else
            return null;

    }


    /**
     * A node is a data item and a reference to the next node
     */
    private static class Node<E> {
        E data;
        Node<E> next;

        private Node(E d) {
            data = d; }


        private Node(E dataItem, Node<E> nodeRef) {
            data = dataItem;
            next = nodeRef;
        }

    }
}
