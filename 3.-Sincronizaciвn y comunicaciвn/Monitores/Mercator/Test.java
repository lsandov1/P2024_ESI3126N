public class Test {
    public static final double X = 1.0;
    public static void main(String[] args) {
        Sync sync = new Sync();	// sync es el objeto monitor
        Thread[] slave = new Thread[4];

        for(int i=0;i<4;i++)
            slave[i]=new Thread(new Slave(i,sync));
        Thread master = new Thread(new Master(sync));


        for(int i=0;i<4;i++)
            slave[i].start();
        master.start();
    }
}
