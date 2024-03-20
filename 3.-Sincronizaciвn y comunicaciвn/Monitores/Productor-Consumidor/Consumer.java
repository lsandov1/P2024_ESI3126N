import java.util.concurrent.ThreadLocalRandom;

public class Consumer implements Runnable {
    private Buffer buffer;

    // standard constructors
    public Consumer(Buffer buffer) {
    	this.buffer=buffer;
    	System.out.println("Inicia receiver");
    }

    public void run() {
        int receivedNum=0;
        while(receivedNum!=-1) {
            receivedNum = buffer.receive();
            System.out.println("\t\t\tConsumidor consume "+receivedNum);

            // ...
            try {
                Thread.sleep(ThreadLocalRandom.current().nextInt(500, 2500));
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }
    }
}
