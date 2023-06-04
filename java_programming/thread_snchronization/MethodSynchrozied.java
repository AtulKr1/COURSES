package thread_snchronization;

class A {
    synchronized void fun(int x) {
        for(int i=1; i<=3; i++) {
            System.out.println(x * i);

            try {
                Thread.sleep(100);
            }
            catch(Exception e) {
                System.out.println(e);
            }
        }
    }
}

class B extends Thread {
    A obj;
    B(A obj) {
        this.obj = obj;
    }

    public void run() {
        obj.fun(1);
    }
}

class C extends Thread {
    A obj;
    C(A obj) {
        this.obj = obj;
    }

    public void run() {
        obj.fun(10);
    }
}

public class MethodSynchrozied {
    public static void main(String args[]) {
        A obj = new A();
        B th1 = new B(obj);
        C th2 = new C(obj);

        th1.start();
        th2.start();
    }
}