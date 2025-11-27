package ensiie.ast;

public class Scalar implements Node {
    private int value;

    public Scalar(int value) {
        this.value = value;
    }

    @Override
    public int execute() {
        return value;
    }

    public void setValue(int value) {
        this.value = value;
    }

    @Override
    public String toString() {
        return Integer.toString(value);
    }
}
