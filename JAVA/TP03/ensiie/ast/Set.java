package ensiie.ast;

public class Set extends Operation{
    public Set(Node variable, Node value) {
        super(variable, value);
    }

    @Override
    public int execute() {
        if (op(0) instanceof Variable var) {
            int value = op(1).execute();
            var.setValue(value);
            return 0;
        } else {
            throw new RuntimeException("Left operand of Set must be a Variable");
        }
    }

}
