package super_keyword;

class A {
    int x;
    A(int x) {
        this.x = x;
    }
    public void fun1() {
        System.out.println("x = " + x);
    }
}

public class SuperExample extends A {
    SuperExample() {
        super(10);  // calling base constructor
    }
    void fun2() {
        super.fun1();
        super.x = 20;
        super.fun1();
    }

    public static void main(String... args) {
        SuperExample obj = new SuperExample();
        obj.fun2();
    }
}