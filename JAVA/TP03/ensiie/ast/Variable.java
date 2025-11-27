package ensiie.ast;

public class Variable extends Scalar {
    private final String name;

    public Variable(String name) {
        super(0);
        this.name = name;
    }

    public String getName() {
        return name;
    }

    @Override
    public String toString() {
        return name;
    }
}
