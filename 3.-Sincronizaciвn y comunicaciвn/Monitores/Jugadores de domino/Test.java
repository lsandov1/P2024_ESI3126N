
public class Test {
	public static void main(String[] args) {
	    Turn turn = new Turn();
		Thread[] player = new Thread[4];
		for(int i=0;i<4;i++)
			player[i]=new Thread(new Player(i,turn));

		for(int i=0;i<4;i++)
			player[i].start();
	}
}
