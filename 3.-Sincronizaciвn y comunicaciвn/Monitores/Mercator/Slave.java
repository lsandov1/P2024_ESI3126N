import java.util.concurrent.ThreadLocalRandom;

public class Slave implements Runnable {
    private Sync sync;
    private int slaveNumber;

    // standard constructors
    public Slave(int slaveNumber,Sync sync) {
    	this.slaveNumber=slaveNumber;
        this.sync = sync;
    }

    private double getMember(int n, double x)
    {
        double numerator = 1;

        for(int i=0; i<n; i++ )
            numerator = numerator*x;

        if (n % 2 == 0)
            return ( - numerator / n );
        else
            return numerator/n;
    }

    public void run() {
        sync.waitStart();

        for(int i=slaveNumber;i<200000;i+=4) {
            sync.sum[slaveNumber] += getMember(i+1,Test.X);
        }

        sync.finished();
    }
}
