package ensiie.ast;

public class While extends Operation{
    public While(Node condition, Node body) {
        super(condition, body);
    }

    @Override
    public int execute() {
        int result = 0;
        while (op(0).execute() != 0) {
            result += op(1).execute();
        }
        return result;
    }
}