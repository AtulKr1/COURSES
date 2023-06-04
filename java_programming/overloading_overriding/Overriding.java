package overloading_overriding;

class A {
    public void fun() {
        System.out.println("Class A");
    }
}

class B extends A {
    public void fun() {
        System.out.println("Class B");
    }
}

public class Overriding {
    public static void main(String... args) {
        B objB1 = new B();
        A objA1 = new A();

        objA1.fun();
        objB1.fun();

        A objA2 = new B();
        objA2.fun();        // Overriding
    }
}