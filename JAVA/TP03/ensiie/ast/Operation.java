package ensiie.ast;

public abstract class Operation implements Node {
    private final Node[] ops;

    public Operation(Node... ops) {
        for (Node op : ops) {
            if (op == null) {
                throw new IllegalArgumentException("Operation nodes cannot be null");
            }
        }
        this.ops = ops;
    }

    public abstract int execute();

    public Node op(int index) {
        if (index < 0 || index >= ops.length) {
            throw new IndexOutOfBoundsException("Index out of bounds for operation nodes");
        }
        return ops[index];
    }

    public int nbOps() {
        return ops.length;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("(").append(this.getClass().getSimpleName());
        for (Node op : ops) {
            sb.append(" ").append(op.toString());
        }
        sb.append(")");
        return sb.toString();
    }
}
