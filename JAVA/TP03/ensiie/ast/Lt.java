package ensiie.ast;

public class Lt extends Operation{
    public Lt(Node left, Node right) {
        super(left, right);
    }

    @Override
    public int execute() {
        return op(0).execute() < op(1).execute() ? 1 : 0;
    }
}
