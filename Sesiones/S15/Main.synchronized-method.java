class Counter {
    private int count = 0;

    // Synchronized method
    public synchronized void increment() {
        count++;
    }

    // Synchronized method
    public synchronized void decrement() {
        count--;
    }

    public synchronized int getCount() {
        return count;
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
