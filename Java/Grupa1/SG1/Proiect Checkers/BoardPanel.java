package Checkers;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.List;

public class BoardPanel extends JPanel {

    private Board board = new Board();
    private static final int tileSize = 80;

    private Piece.Color currentPlayer = Piece.Color.Red;

    private int selI = -1, selJ = -1;
    private List<Move> validMoves;

    public BoardPanel() {
        setPreferredSize(new Dimension(8 * tileSize, 8 * tileSize));

        addMouseListener(new MouseAdapter() {
            public void mousePressed(MouseEvent e) {
                int j = e.getX() / tileSize; 
                int i = e.getY() / tileSize; 
                handleClick(i, j);
            }
        });
    }

    private void handleClick(int i, int j) {
        if (selI == -1) {
            if (board.getPiece(i, j) != null &&
                board.getPiece(i, j).getColor() == currentPlayer) {

                selI = i;
                selJ = j;
                validMoves = board.getValidMoves(i, j, currentPlayer);
            }
            repaint();
            return;
        }
        for (Move m : validMoves) {
            if (m.endI == i && m.endJ == j) {

                board.makeMove(m);
                if (m.isJump() && board.hasMoves(currentPlayer)) {
                    selI = i;
                    selJ = j;
                    validMoves = board.getValidMoves(i, j, currentPlayer);
                    repaint();
                    return;
                }
                currentPlayer = (currentPlayer == Piece.Color.Red)
                        ? Piece.Color.Black
                        : Piece.Color.Red;
                if (!board.hasMoves(currentPlayer)) {
                    JOptionPane.showMessageDialog(
                            this,
                            (currentPlayer == Piece.Color.Red ? "Black" : "Red") + " a castigat!"
                    );
                    board = new Board();
                    currentPlayer = Piece.Color.Red;
                }
                break;
            }
        }
        selI = -1;
        selJ = -1;
        validMoves = null;

        repaint();
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);

        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++) {

                g.setColor((i + j) % 2 == 0 ? Color.LIGHT_GRAY : Color.DARK_GRAY);
                g.fillRect(j * tileSize, i * tileSize, tileSize, tileSize);

                Piece p = board.getPiece(i, j);
                if (p != null) {
                    g.setColor(p.getColor() == Piece.Color.Red ? Color.RED : Color.BLACK);
                    g.fillOval(
                            j * tileSize + 10,
                            i * tileSize + 10,
                            tileSize - 20,
                            tileSize - 20
                    );

                    if (p.isKing()) {
                        g.setColor(Color.YELLOW);
                        g.drawString("K", j * tileSize + 35, i * tileSize + 45);
                    }
                }
            }
        if (selI != -1) {
            g.setColor(Color.YELLOW);
            g.drawRect(selJ * tileSize, selI * tileSize, tileSize, tileSize);
            if (validMoves != null) {
                g.setColor(new Color(255, 255, 0, 120));
                for (Move m : validMoves) {
                    g.fillRect(
                            m.endJ * tileSize,
                            m.endI * tileSize,
                            tileSize,
                            tileSize
                    );
                }
            }
        }
    }
}
