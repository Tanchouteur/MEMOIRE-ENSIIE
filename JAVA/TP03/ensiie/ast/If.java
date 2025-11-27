package ensiie.ast;

public class If extends Operation{
    public If(Node condition, Node thenBranch, Node elseBranch) {
        super(condition, thenBranch, elseBranch);
    }

    public int execute() {
        if (op(0).execute() != 0) {
            return op(1).execute();
        } else {
            return op(2).execute();
        }
    }
}
