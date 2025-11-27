package ensiie.ast;

public class Neg extends Operation{
    Neg(Node operand) {
        super(operand);
    }

    @Override
    public int execute() {
        return -op(0).execute();
    }
}
