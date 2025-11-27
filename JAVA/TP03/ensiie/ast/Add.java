package ensiie.ast;

public class Add extends Operation {
    public Add(Node left, Node right) {
        super(left, right);
    }

    @Override
    public int execute() {
        return op(0).execute() + op(1).execute();
    }
}
