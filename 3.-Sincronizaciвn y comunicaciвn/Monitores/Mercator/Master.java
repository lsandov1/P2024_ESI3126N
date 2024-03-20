import java.util.concurrent.ThreadLocalRandom;

public class Master implements Runnable {
    private Sync sync;

    public Master(Sync sync) {
    	this.sync=sync;
    }

    public void run() {
        double res = 0.0;
        try {
            Thread.sleep(1000);
        } catch (InterruptedException ex) {}

        sync.sendStart();

        sync.waitAll();

        for(int i=0;i<4;i++)
            res += sync.sum[i];

        System.out.printf("El resultado es %10.8f\n", res);
        System.out.printf("Llamando a la función ln(1 + %f) = %10.8f\n",Test.X, Math.log(1+Test.X));
    }
}
