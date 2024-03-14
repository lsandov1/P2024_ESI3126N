class Counter {
    private int count = 0;
    private Object lock = new Object();

    public void increment() {
        synchronized (lock) {
            count++;
        }
    }

    public void decrement() {
        synchronized (lock) {
            count--;
        }
    }

    public int getCount() {
        synchronized (lock) {
            return count;
        }
    }
}

public class Main {
    public static void main(String[] args) {
        Counter counter = new Counter();

        // Multiple threads incrementing and decrementing the counter
        for (int i = 0; i < 5; i++) {
            new Thread(() -> {
                counter.increment();
                System.out.println("Incremented: " + counter.getCount());
            }).start();

            new Thread(() -> {
                counter.decrement();
                System.out.println("Decremented: " + counter.getCount());
            }).start();
        }
    }
}
