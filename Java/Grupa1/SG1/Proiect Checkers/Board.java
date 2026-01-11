package Checkers;

import java.util.ArrayList;
import java.util.List;

public class Board {

    public static final int size = 8;
    private Piece[][] board;

    public Board() {
        board = new Piece[size][size];
        initialize();
    }

    public Piece getPiece(int i, int j) {
        return isInside(i, j) ? board[i][j] : null;
    }
    public void initialize() {
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                board[i][j] = null;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < size; j++)
                if ((i + j) % 2 == 1)
                    board[i][j] = new Piece(Piece.Color.Black);
        for (int i = 5; i < size; i++)
            for (int j = 0; j < size; j++)
                if ((i + j) % 2 == 1)
                    board[i][j] = new Piece(Piece.Color.Red);
    }

    private boolean isInside(int i, int j) {
        return i >= 0 && i < size && j >= 0 && j < size;
    }
    public List<Move> getNormalMoves(int i, int j) {
        List<Move> moves = new ArrayList<>();
        Piece p = board[i][j];
        if (p == null) return moves;

        int[] di = p.isKing()
                ? new int[]{-1, 1}
                : (p.getColor() == Piece.Color.Red ? new int[]{-1} : new int[]{1});

        for (int d : di) {
            for (int dj : new int[]{-1, 1}) {
                int I = i + d;
                int J = j + dj;

                if (isInside(I, J) && board[I][J] == null) {
                    moves.add(new Move(i, j, I, J));
                }
            }
        }
        return moves;
    }
    public List<Move> getJumpMoves(int i, int j) {
        List<Move> jumps = new ArrayList<>();
        Piece p = board[i][j];
        if (p == null) return jumps;

        int[] di = p.isKing()
                ? new int[]{-1, 1}
                : (p.getColor() == Piece.Color.Red ? new int[]{-1} : new int[]{1});

        for (int d : di) {
            for (int dj : new int[]{-1, 1}) {
                int midI = i + d;
                int midJ = j + dj;
                int endI = i + 2 * d;
                int endJ = j + 2 * dj;

                if (isInside(endI, endJ)
                        && board[endI][endJ] == null
                        && board[midI][midJ] != null
                        && board[midI][midJ].getColor() != p.getColor()) {

                    Move m = new Move(i, j, endI, endJ);
                    m.jumpedI = midI;
                    m.jumpedJ = midJ;
                    jumps.add(m);
                }
            }
        }
        return jumps;
    }
    public boolean playerHasJump(Piece.Color color) {
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                if (board[i][j] != null && board[i][j].getColor() == color)
                    if (!getJumpMoves(i, j).isEmpty())
                        return true;

        return false;
    }
    public List<Move> getValidMoves(int i, int j, Piece.Color player) {
        if (board[i][j] == null || board[i][j].getColor() != player)
            return List.of();

        if (playerHasJump(player))
            return getJumpMoves(i, j);

        return getNormalMoves(i, j);
    }
    public List<Move> getAllValidMoves(Piece.Color color) {
        List<Move> all = new ArrayList<>();
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                if (board[i][j] != null && board[i][j].getColor() == color)
                    all.addAll(getJumpMoves(i, j));

        if (!all.isEmpty())
            return all;
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                if (board[i][j] != null && board[i][j].getColor() == color)
                    all.addAll(getNormalMoves(i, j));

        return all;
    }
    public void makeMove(Move m) {
        Piece p = board[m.startI][m.startJ];
        board[m.startI][m.startJ] = null;
        board[m.endI][m.endJ] = p;

        if (m.isJump()) {
            board[m.jumpedI][m.jumpedJ] = null;
        }

        if (p.getColor() == Piece.Color.Red && m.endI == 0)
            p.makeKing();

        if (p.getColor() == Piece.Color.Black && m.endI == size - 1)
            p.makeKing();
    }

    public boolean hasMoves(Piece.Color color) {
        return !getAllValidMoves(color).isEmpty();
    }
}
