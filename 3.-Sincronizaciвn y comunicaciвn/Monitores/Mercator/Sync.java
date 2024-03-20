public class Sync {
    private boolean startAll = false;
    private int endedThreads = 0;
    double[] sum = {0,0,0,0};

    public synchronized void waitStart() {
        while (!startAll) {
            try {
                wait();
            } catch (InterruptedException e)  {
                Thread.currentThread().interrupt();
                // Log.error("Thread interrupted", e);
            }
        }
    }

    public synchronized void finished() {
        endedThreads++;
        notify();
    }

    public synchronized void sendStart() {
        startAll = true;
        notifyAll();
    }

    public synchronized void waitAll() {
        while(endedThreads!=4) {
            try {
                wait();
            } catch (InterruptedException e)  {
                Thread.currentThread().interrupt();
                // Log.error("Thread interrupted", e);
            }
        }
    }
}
