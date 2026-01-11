package Checkers;

public class Move {

    public int startI, startJ;
    public int endI, endJ;

    public int jumpedI = -1;
    public int jumpedJ = -1;

    public Move(int startI, int startJ, int endI, int endJ) {
        this.startI = startI;
        this.startJ = startJ;
        this.endI = endI;
        this.endJ = endJ;
    }

    public boolean isJump() {
        return jumpedI != -1 && jumpedJ != -1;
    }
}
