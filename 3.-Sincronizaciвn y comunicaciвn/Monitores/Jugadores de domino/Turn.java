public class Turn {
    private int currentTurn;	// Variable o atributo para
    // establecer la condición

    public synchronized void waitTurn(int player) {
        while (currentTurn!=player) {
            try {
                wait();	// Cola de bloqueados
            } catch (InterruptedException e)  {
                Thread.currentThread().interrupt();
                // Log.error("Thread interrupted", e);
            }
        }
    }

    public synchronized void sendTurn(int player) {
        currentTurn = player;
        notifyAll();
    }
}
