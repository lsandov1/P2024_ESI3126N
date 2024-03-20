import java.util.concurrent.ThreadLocalRandom;

public class Producer implements Runnable {
    private Buffer buffer;

    // standard constructors
    public Producer(Buffer buffer) {
    	this.buffer=buffer;
    	System.out.println("Inicia sender");
    }

    public void run() {
        for (int i=0;i<30;i++) {
            System.out.println("Productor produce "+i);
            buffer.send(i);

            // Thread.sleep() to mimic heavy server-side processing
            try {
                Thread.sleep(ThreadLocalRandom.current().nextInt(500, 2500));
            } catch (InterruptedException e)  {
                Thread.currentThread().interrupt();
            }
        }
        buffer.send(-1);
    }
}
