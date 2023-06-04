package multiple_inheritance;

interface I1 {
    default void fun() {
        System.out.println("Interface I1");
    }
}

interface I2 {
    default void fun() {
        System.out.println("Interface I2");
    }
}

public class MultiInheri implements I1, I2 {
    @Override
    public void fun() {
        I1.super.fun();
        I2.super.fun();
    }
    public static void main(String... args) {
        MultiInheri obj = new MultiInheri();
        obj.fun();
    }
}