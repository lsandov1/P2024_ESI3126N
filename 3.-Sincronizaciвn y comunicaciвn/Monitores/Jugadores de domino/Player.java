import java.util.concurrent.ThreadLocalRandom;

public class Player implements Runnable {
    private Turn turn;
    int playerNumber;
    int nextPlayer;

    // standard constructors
    public Player(int playerNumber,Turn turn) {
    	this.playerNumber=playerNumber;
        this.turn = turn;
        nextPlayer = (playerNumber + 1) % 4;
    	System.out.println("Inicia jugador "+playerNumber);
    }

    public void run() {
        for(int i=0;i<10;i++) {
            turn.waitTurn(playerNumber);
            System.out.print("Jugador "+playerNumber+" inicia jugada");
            try {
                Thread.sleep(1000);
            } catch (InterruptedException ex) {}
            System.out.println(" - Jugador "+playerNumber+" termina jugada");
            turn.sendTurn(nextPlayer);
        }
    }
}
