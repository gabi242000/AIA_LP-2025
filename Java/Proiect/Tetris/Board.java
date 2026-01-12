package tetris1;

import java.awt.Color;
import java.awt.Font;
import javax.sound.sampled.*;
import java.awt.Graphics;
import javax.swing.Timer;
import javax.swing.JPanel;
import java.awt.event.*;
import java.io.*;
import java.util.Random;

public class Board extends JPanel implements KeyListener {

	private static final long serialVersionUID = 1L;
	
	public static int starePlay=0;
	public static int starePauza=1;
	public static int stareSfarsit=2;
	private int stare=starePlay;
	
	//dimensiuni board
	public static final int inaltime=20;
	public static final int latime=10;
	
	public static final int dimensiune_cel=20; //dimensiuni celula
	private static int fps=60;
	private static int viteza=fps/1000;
	private Timer looper;
	
	private Color[][] board=new Color[inaltime][latime];
	
	private Forma[] forme=new Forma[14];	//vectorul de forme
	private Color[] culori= {Color.green, Color.red, Color.white, Color.magenta, Color.orange, Color.yellow, Color.cyan}; //vector culori
	private Forma formaCurenta,formaUrmatoare;

	private Random random;
	
	private int[] rotiri= {0,0,0,0,0,0,0};
	private int[] rotiriFormaUrm= {0,0,0,0,0,0,0};
	
	public int scor=0;	//scor
	public int nrLinii=0;	//nr linii complete
	public int nivelStart=0;	//nivel start
	public int nivelCurent=0;	//nivel curent
	//alegerea formelor
	private int nr=0;	//forma curenta
	private int nr2=0;	//forma urmatoare
	
	//parametri ecran pornire
	private int optiune=1;	//optiune ecran pornire
	private int optiuneAleasa=0;
	private int optiuneMuzica=1;
	public int start=0;	//trigger start joc
	
	private boolean restart=true;
	
	private Clip clipMuzica;
	
	public Board() {
		random=new Random();
		forme[0]=new Forma(new int[][] {
			{1,1,1,1} 	//forma I
		},this,culori[0]);
		
		forme[1]=new Forma(new int[][] {
			{1,1,1},
			{0,1,0}	//forma T
		},this,culori[1]);
		
		forme[2]=new Forma(new int[][] {
				{1,1,1},
				{1,0,0}	//forma L
		},this,culori[2]);
		
		forme[3]=new Forma(new int[][] {
			{1,1,1},
			{0,0,1}	//forma J
		},this,culori[3]);
		
		forme[4]=new Forma(new int[][] {
			{0,1,1},
			{1,1,0}	//forma S
		},this,culori[4]);
		
		forme[5]=new Forma(new int[][] {
			{1,1,0},
			{0,1,1}	//forma Z
		},this,culori[5]);
		
		forme[6]=new Forma(new int[][] {
			{1,1},
			{1,1}	//forma O
		},this,culori[6]);
		
		forme[7]=new Forma(new int[][] {
			{1,1,1,1} 	//forma I
		},this,culori[0]);
		
		forme[8]=new Forma(new int[][] {
			{1,1,1},
			{0,1,0}	//forma T
		},this,culori[1]);
		
		forme[9]=new Forma(new int[][] {
				{1,1,1},
				{1,0,0}	//forma L
		},this,culori[2]);
		
		forme[10]=new Forma(new int[][] {
			{1,1,1},
			{0,0,1}	//forma J
		},this,culori[3]);
		
		forme[11]=new Forma(new int[][] {
			{0,1,1},
			{1,1,0}	//forma S
		},this,culori[4]);
		
		forme[12]=new Forma(new int[][] {
			{1,1,0},
			{0,1,1}	//forma Z
		},this,culori[5]);
		
		forme[13]=new Forma(new int[][] {
			{1,1},
			{1,1}	//forma O
		},this,culori[6]);
		
		setareFormaCurenta();
		
		looper=new Timer(viteza,new ActionListener ()
				{
			@Override
			public void actionPerformed(ActionEvent e)
			{
				updateBoard();
				repaint();
			}
				});
		looper.start();
	}
	private void updateBoard()
	{
		if(stare==starePlay&&start==1)
		{
			formaCurenta.update();
		}
	}
	
	public void setareFormaCurenta()
	{
		if(nr2==0)
		{
			nr=random.nextInt(forme.length);
			if(nr>=7)
				nr-=7;
		}
		if(nr2>=7)
			nr=nr2-7;
		nr2=random.nextInt(forme.length);
		if(nr2<7)
			nr2+=7;
		formaUrmatoare=forme[nr2];
		formaCurenta=forme[nr];
		formaCurenta.reset();
		verificaSfarsitJoc();
		resetarePozitieFormaCurenta();
	}
	public void resetarePozitieFormaCurenta()	//resetare pozitie forma curenta la aparitia pe board
	{
		if(rotiri[nr]>0)
		{
			while(rotiri[nr]>0)
			{
				formaCurenta.rotireStanga();
				rotiri[nr]--;
			}
		}
		else if(rotiri[nr]<0)
		{
			while(rotiri[nr]<0)
			{
				formaCurenta.rotireDreapta();
				rotiri[nr]++;
			}
		}
	}
	public void resetarePozitieFormaUrmatoare()	//resetare pozitie forma curenta la aparitia pe board
	{
		if(rotiriFormaUrm[nr]>0)
		{
			while(rotiriFormaUrm[nr]>0)
			{
				formaUrmatoare.rotireStanga();
				rotiriFormaUrm[nr]--;
			}
		}
		else if(rotiriFormaUrm[nr]<0)
		{
			while(rotiriFormaUrm[nr]<0)
			{
				formaUrmatoare.rotireDreapta();
				rotiriFormaUrm[nr]++;
			}
		}
	}
	private void verificaSfarsitJoc()
	{
		int[][] coordonate=formaCurenta.getCoordonate();
		for(int linie=0;linie<coordonate.length;linie++)
			for(int col=0;col<coordonate[0].length;col++)
			{
				if(coordonate[linie][col]!=0)
				{
					if(board[linie+formaCurenta.getY()][col+formaCurenta.getX()]!=null)
					{
						stare=stareSfarsit;
					}
				}
			}
	}
	
	public void updateScor()
	{
		if(formaCurenta.deltaLinii==1)
			scor+=40*(nivelCurent+1);
		else if(formaCurenta.deltaLinii==2)
			scor+=100*(nivelCurent+1);
		else if(formaCurenta.deltaLinii==3)
			scor+=300*(nivelCurent+1);
		else if(formaCurenta.deltaLinii==4)
			scor+=1200*(nivelCurent+1);
		if(nivelCurent<=29) 
			nivelCurent=nivelStart+nrLinii/10;
		formaCurenta.delayMiscare=formaCurenta.nivele[nivelCurent];
	}
	public void updateSoftDrop()
	{
		if(formaCurenta.startSoft!=0)
			scor+=formaCurenta.getY()+formaCurenta.getCoordonate().length-formaCurenta.startSoft;
	}
	
	private void pornireMuzica(int optiune)
	{
		if(optiune==2)
		{
	        try {
	            AudioInputStream audio =AudioSystem.getAudioInputStream(new File("Original Tetris theme (Tetris Soundtrack).wav"));

	            clipMuzica = AudioSystem.getClip();
	            clipMuzica.open(audio);

	        } catch (Exception e) {
	            e.printStackTrace();
	        }
	    }
		else if(optiune==3)
		{
			try {
	            AudioInputStream audio =AudioSystem.getAudioInputStream(new File("DJ BLYATMAN - TETRIS.wav"));

	            clipMuzica=AudioSystem.getClip();
	            clipMuzica.open(audio);

	        } catch (Exception e) {
	            e.printStackTrace();
	        }
		}
		else if(optiune==4)
		{
			try {
	            AudioInputStream audio =AudioSystem.getAudioInputStream(new File("S.T.A.L.K.E.R._ Clear Sky - Bandit Radio.wav"));

	            clipMuzica=AudioSystem.getClip();
	            clipMuzica.open(audio);

	        } catch (Exception e) {
	            e.printStackTrace();
	        }
		}
		if(optiune!=1)
		{
			clipMuzica.start();
			clipMuzica.loop(Clip.LOOP_CONTINUOUSLY);
		}
	}
	private void pauzaMuzica()
	{
		if(clipMuzica!=null&&clipMuzica.isRunning())
			{
				clipMuzica.stop();
			}
		else if(clipMuzica!=null&&!(clipMuzica.isRunning()))
		{
			clipMuzica.start();
			clipMuzica.loop(Clip.LOOP_CONTINUOUSLY);
		}
	}
	
	@Override
	protected void paintComponent(Graphics g)
	{
		super.paintComponent(g);
		g.setColor(Color.black);
		g.fillRect(0,0,getWidth(),getHeight());
		
		if(start==1)
		{
			if(stare==starePlay)
			{
				formaUrmatoare.desenFormaUrmatoare(g);
				formaCurenta.desenForma(g);
				
				for(int linie=0;linie<board.length;linie++)
				{
					for(int col=0;col<board[linie].length;col++)
					{
						if(board[linie][col]!=null)
						{
							g.setColor(board[linie][col]);
							g.fillRect(col*dimensiune_cel, linie*dimensiune_cel+50, dimensiune_cel, dimensiune_cel);
						}
					}
				}
				
				g.setColor(Color.white);
				g.drawRect(0, 50, 200, 400);
				//afisare statistici
				g.setColor(Color.white);
				g.setFont(new Font("Tahoma",Font.BOLD,24));
				g.drawString("SCOR",250,250);
				g.drawString(""+scor, 250,290);
				g.drawString("LINII - "+nrLinii, 50, 30);
				g.drawString("NIVEL", 250, 350);
				g.drawString(""+nivelCurent,250, 390);
			}
			
			if(stare==stareSfarsit)
			{
				g.setColor(Color.white);
				g.setFont(new Font("Tahoma",Font.BOLD,24));
				g.drawString("JOC TERMINAT",105, 125);
				g.drawString("JOC NOU?",120, 200);
				g.drawString("DA", 80, 250);
				g.drawString("NU", 250, 250);
				desenRestart(g);
				pauzaMuzica();
				clipMuzica=null;
			}
			if(stare==starePauza)
			{
				g.setColor(Color.white);
				g.setFont(new Font("Tahoma",Font.BOLD,24));
				g.drawString("PAUZA", 150, 125);
				g.setFont(new Font("Tahoma",Font.BOLD,16));
				g.drawString("APASA ENTER PENTRU A CONTINUA", 50, 200);
			}
		}
		else if(start==0)
		{
			g.setColor(Color.white);
			if(optiuneAleasa==0)
			{
				//Ecran pornire
				g.setFont(new Font("Tahoma",Font.BOLD,30));
				g.drawString("TETRIS", 125, 100);
				g.setFont(new Font("Tahoma",Font.BOLD,18));
				g.drawString("JOC NOU",135,200);
				g.drawString("CONTROALE", 135, 240);
				if(optiune==1)
				{
					desenOptiune1(g);
				}
				else if(optiune==2)
				{
					desenOptiune2(g);
				}
			}
			else if(optiuneAleasa==1)
			{
				optiuniJoc(g);
				if(optiuneMuzica==1)
					desenOptiuneMuzica1(g);
				else if(optiuneMuzica==2)
					desenOptiuneMuzica2(g);
				else if(optiuneMuzica==3)
					desenOptiuneMuzica3(g);
				else if(optiuneMuzica==4)
					desenOptiuneMuzica4(g);
			}
			else if(optiuneAleasa==2)
			{
				desenControale(g);
			}
		}
	}
	public void desenOptiune1(Graphics g)
	{
		int[] puncteX= {290,290,270};
		int[] puncteY= {185,205,195};
		g.drawPolygon(puncteX,puncteY,3);
		g.fillPolygon(puncteX,puncteY,3);
	}
	public void desenOptiune2(Graphics g)
	{
		int[] puncteX= {290,290,270};
		int[] puncteY= {225,245,235};
		g.drawPolygon(puncteX,puncteY,3);
		g.fillPolygon(puncteX,puncteY,3);
	}
	public void optiuniJoc(Graphics g)
	{
		g.setFont(new Font("Tahoma",Font.BOLD,24));
		g.drawString("SELECTARE MUZICA", 75, 100);
		g.setFont(new Font("Tahoma",Font.BOLD,18));
		g.drawString("MUZICA OPRITA", 110, 150);
		g.drawString("MUZICA 1", 110, 180);
		g.drawString("MUZICA 2", 110, 210);
		g.drawString("MUZICA 3", 110, 240);
	}
	public void desenOptiuneMuzica1(Graphics g)
	{
		int[] puncteX= {305,305,285};
		int[] puncteY= {133,153,143};
		g.drawPolygon(puncteX,puncteY,3);
		g.fillPolygon(puncteX,puncteY,3);
	}
	public void desenOptiuneMuzica2(Graphics g)
	{
		int[] puncteX= {305,305,285};
		int[] puncteY= {163,183,173};
		g.drawPolygon(puncteX,puncteY,3);
		g.fillPolygon(puncteX,puncteY,3);
	}
	public void desenOptiuneMuzica3(Graphics g)
	{
		int[] puncteX= {305,305,285};
		int[] puncteY= {193,213,203};
		g.drawPolygon(puncteX,puncteY,3);
		g.fillPolygon(puncteX,puncteY,3);
	}
	public void desenOptiuneMuzica4(Graphics g)
	{
		int[] puncteX= {305,305,285};
		int[] puncteY= {223,243,233};
		g.drawPolygon(puncteX,puncteY,3);
		g.fillPolygon(puncteX,puncteY,3);
	}
	public void desenControale(Graphics g)
	{
		g.setFont(new Font("Tahoma",Font.BOLD,24));
		g.drawString("CONTROALE", 100, 100);
		g.setFont(new Font("Tahoma",Font.BOLD,18));
		g.drawString("DREAPTA-MISCARE SPRE DREAPTA", 40, 150);
		g.drawString("STANGA-MISCARE SPRE STANGA", 40, 180);
		g.drawString("JOS-ACCELERARE PIESA", 40, 210);
		g.drawString("X-ROTIRE PIESA SPRE DREAPTA", 40, 240);
		g.drawString("Z-ROTIRE PIESA SPRE STANGA", 40, 270);
		g.drawString("ENTER-SELECTARE/PAUZA/START", 40, 300);
		g.drawString("APASA ENTER PENTRU A INCHIDE", 40, 350);
	}
	public void desenRestart(Graphics g)
	{
		if(restart==true)
		{
			int[] puncteX= {145,145,125};
			int[] puncteY= {230,250,240};
			g.drawPolygon(puncteX,puncteY,3);
			g.fillPolygon(puncteX,puncteY,3);
		}
		else
		{
			int[] puncteX= {315,315,295};
			int[] puncteY= {230,250,240};
			g.drawPolygon(puncteX,puncteY,3);
			g.fillPolygon(puncteX,puncteY,3);
		}
	}
	public Color[][] getBoard()
	{
		return board;
	}
	
	@Override
	public void keyTyped(KeyEvent e) {
		
	}
	@Override
	public void keyPressed(KeyEvent e) {
		if(start==1)
		{
			if(e.getKeyCode()==KeyEvent.VK_DOWN)
			{
				formaCurenta.softDrop();
			}
			if(e.getKeyCode()==KeyEvent.VK_LEFT)
			{
				if(stare==starePlay)
					formaCurenta.miscareStanga();
				else if(stare==stareSfarsit)
					restart=true;
			}
			if(e.getKeyCode()==KeyEvent.VK_RIGHT)
			{
				if(stare==starePlay)
					formaCurenta.miscareDreapta();
				else if(stare==stareSfarsit)
					restart=false;
			}
			if(e.getKeyCode()==KeyEvent.VK_Z)
			{
				rotiri[nr]--;
				rotiriFormaUrm[nr]--;
				formaCurenta.rotireStanga();
			}
			if(e.getKeyCode()==KeyEvent.VK_X)
			{
				rotiri[nr]++;
				rotiriFormaUrm[nr]++;
				formaCurenta.rotireDreapta();
			}
			
			if(e.getKeyCode()==KeyEvent.VK_ENTER)
			{
				//resetare board
				if(stare==stareSfarsit)
				{
					for(int linie=0;linie<board.length;linie++)
						for(int col=0;col<board[0].length;col++)
						{
							board[linie][col]=null;
						}
					scor=0;
					nrLinii=0;
					nivelCurent=0;
					if(restart==true)
					{
						stare=starePlay;
						pornireMuzica(optiuneMuzica);
						setareFormaCurenta();
					}
					else
					{
						start=0;
						optiune=1;
						optiuneAleasa=0;
						optiuneMuzica=1;
						restart=true;
					}
				}
				else
				{
					//pauza joc
					pauzaMuzica();
					if(stare==starePlay)
					{
						stare=starePauza;
					}
					else if(stare==starePauza)
					{
						stare=starePlay;
					}
				}
			}
		}
		else if(start==0)
		{
			if(e.getKeyCode()==KeyEvent.VK_DOWN)
			{
				if(optiuneAleasa==0)
					optiune=2;
				else if(optiuneAleasa==1)
					if(optiuneMuzica<4)
						optiuneMuzica++;
			}
			if(e.getKeyCode()==KeyEvent.VK_UP)
			{
				if(optiuneAleasa==0)
					optiune=1;
				else if(optiuneAleasa==1)
					if(optiuneMuzica>1)
						optiuneMuzica--;
			}
			if(e.getKeyCode()==KeyEvent.VK_ENTER)
			{
				if(optiuneAleasa==0)
					optiuneAleasa=optiune;
				else if(optiuneAleasa==1)
				{
					start=1;
					pornireMuzica(optiuneMuzica);
					stare=starePlay;
				}
				else if(optiuneAleasa==2)
					optiuneAleasa=0;
			}
		}
	}
	@Override
	public void keyReleased(KeyEvent e) {
		if(start==1)
			if(e.getKeyCode()==KeyEvent.VK_DOWN)
			{
				formaCurenta.vitezaNormala();
			}	
	}
}
