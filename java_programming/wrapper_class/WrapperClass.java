package wrapper_class;

public class WrapperClass {
    public static void main(String... args) {
        int n = 20;

        Integer iobj = n;   // autoboxing
        System.out.println(iobj);

        Integer num = 12;
        int x = num;        // unboxing
        System.out.println(x);
    }
}