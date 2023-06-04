package overloading_overriding;

public class Overload {
    public void fun() {
        System.out.println("No argu");
    }
    public void fun(int x) {
        System.out.println("1 int argu: " + x);
    }
    public void fun(char c) {
        System.out.println("1 char argu: " + c);
    }
    public void fun(int x, int y) {
        System.out.println("2 int argu: " + x + " " + y);
    }
    public static void main(String... args) {
        Overload obj = new Overload();
        obj.fun();
        obj.fun(5);
        obj.fun('x');
        obj.fun(3, 7);
    }
}