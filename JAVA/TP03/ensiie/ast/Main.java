package ensiie.ast;

public class Main {
    public static void main(String[] args) {

        Variable x = new Variable("x");
        Node program = new Begin(
            new Set(x, new Scalar(0)),
            new While(
                new Lt(x, new Scalar(10)),
                new Begin(
                    new Echo(x),
                    new Set(x, new Add(x, new Scalar(1)))
                )
            )
        );

        System.out.println("Programme AST : " + program);
        System.out.println("Exécution du programme :");
        program.execute();
    }
}
