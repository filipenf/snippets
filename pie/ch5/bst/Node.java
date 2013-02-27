

public class Node {

    public Node right;
    public Node left;
    public int value;

    public Node findNode(int v) {
        if ( value == v ) {
            return this;
        } else if ( value < v ) {
            return left.findNode(v);
        } else if ( value > v ) {
            return right.findNode(v);
        }
        return null;
    }

}
