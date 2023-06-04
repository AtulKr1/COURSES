package dynamic_dispatch;

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

public class RuntimePoly {
    public static void main(String... args) {
        A objA = new A();
        B objB = new B();
        A reference;

        reference = objA;
        reference.fun();

        reference = objB;
        reference.fun();
    }
}