public class BinaryTree{
 
    public static void main(String[] args) {
        //create node
        Node node1 = new Node(1);
        Node node2 = new Node(2);
        Node node3 = new Node(3);
        Node node4 = new Node(4);
        Node node5 = new Node(5);
        
        //add node
        node1.setLeft(node2);
        node1.setRight(node3);
        node2.setLeft(node4);
        node2.setRight(node5);

        System.out.println(node1.getData());
    }
}


// src: http://swalloow.tistory.com/34 [MyCloud]