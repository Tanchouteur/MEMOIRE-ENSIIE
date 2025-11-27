package ensiie.ast;

public class Echo extends Operation{
    public Echo(Node operand) {
        super(operand);
    }

    @Override
    public int execute() {
        int value = op(0).execute();
        System.out.println(value);
        return value;
    }

}
