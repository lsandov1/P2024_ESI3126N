public class Buffer {
    private final int BUFSIZE = 10;
    private int[] buffer = new int[BUFSIZE];
    private int ent=0;
    private int sal=0;
    private int elements=0;

    public synchronized void send(int element) {
        while (elements==BUFSIZE) {
            try {
                wait();
            } catch (InterruptedException e)  {
                Thread.currentThread().interrupt();
            }
        }

        buffer[ent] = element;
        ent = (ent + 1) % BUFSIZE;

        elements++;

        notifyAll();
    }

    public synchronized int receive() {
        int retVal;
        while(elements==0) {
            try {
                wait();
            } catch (InterruptedException e)  {
                Thread.currentThread().interrupt();
            }
        }

        retVal = buffer[sal];
        sal = (sal + 1) % BUFSIZE;
        elements--;

        notifyAll();

        return retVal;
    }
}
