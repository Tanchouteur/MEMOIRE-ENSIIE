package ensiie.ast;

public class Begin extends Operation {
    public Begin(Node... operations) {
        super(operations);
    }

    @Override
    public int execute() {
        int result = 0;
        for (int i = 0; i < nbOps(); i++) {
            result += op(i).execute();
        }
        return result;
    }
}
