package tetris1;

import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import static tetris1.Board.inaltime;
import static tetris1.Board.latime;
import static tetris1.Board.dimensiune_cel;

public class Forma {
	private int x=4;
	private int y=0;
	private int nivelCurent=0;
	public int nivele[]= {800,717,633,550,467,383,300,217,133,100,		//viteza cadere piese in fct de nivel	
			83,83,83,67,67,67,50,50,50,33,
			33,33,33,33,33,33,33,33,33,16};
	private long timpStart;
	public int delayMiscare=nivele[nivelCurent];	//viteza nivel curent
	private int delayMiscareActual=0;
	
	private int deltaX=0;
	private boolean contact=false;
	private int coordonate[][];
	
	private Board board;
	private Color culoare;
	public int deltaLinii=0;
	public int startSoft=0;
	
	private boolean plasare=false;
	
	public Forma(int[][] coordonate, Board board, Color culoare)
	{
		this.coordonate=coordonate;
		this.board=board;
		this.culoare=culoare;
	}
	
	public void setareX(int x)
	{
		this.x=x;
	}
	public void setareY(int y)
	{
		this.y=y;
	}
	
	public void reset()
	{
		this.x=4;
		this.y=0;
		contact=false;
		plasare=false;
		startSoft=0;
		delayMiscareActual=nivele[nivelCurent];
		verificaLinie();
	}
	
	public void update()
	{
		if(contact==true)	//verificare contact cu baza/alte piese asezate
		{
			for(int linie=0;linie<coordonate.length;linie++)
			{
				for(int col=0;col<coordonate[0].length;col++)
				{
					if(coordonate[linie][col]!=0)
					{
						board.getBoard()[y+linie][x+col]=culoare;
					}
				}
			}
			if(plasare==true)
				board.setareFormaCurenta();
			plasare=true;
			board.updateSoftDrop();
			return;
		}
		boolean miscareX=true;
		if(x+deltaX+coordonate[0].length<=latime&&x+deltaX>=0) //veirificare limite
		{
			for(int linie=0;linie<coordonate.length;linie++)
			{
				for(int col=0;col<coordonate[0].length;col++)
				{
					if(coordonate[linie][col]!=0)
					{
						if(board.getBoard()[y+linie][x+deltaX+col]!=null)
							miscareX=false;
					}	
				}
			}
			if(miscareX==true)
				x+=deltaX;	//miscare orizontala
		}
		deltaX=0;
		if(System.currentTimeMillis()-timpStart>delayMiscare)
		{
			//miscare verticala
			if(!(y+1+coordonate.length>inaltime))
			{
				for(int linie=0;linie<coordonate.length;linie++)
				{
					for(int col=0;col<coordonate[0].length;col++)
					{
						if(coordonate[linie][col]!=0)
						{
							if(board.getBoard()[y+1+linie][x+deltaX+col]!=null)
							{
								contact=true;
							}
						}
					}
				}
				if(contact==false)
					{y++;}
			}
			else
			{
				contact=true;
			}
			timpStart=System.currentTimeMillis();
		}
	}
	private void verificaLinie()	//verifica si elimina liniile complete
	{
		int baza=board.getBoard().length-1;
		deltaLinii=0;
		for(int varf=board.getBoard().length-1;varf>0;varf--)
		{
			int numar=0;
			for(int col=0;col<board.getBoard()[0].length;col++)
			{
				if(board.getBoard()[varf][col]!=null)
					numar++;
				board.getBoard()[baza][col]=board.getBoard()[varf][col];
			}
			if(numar<board.getBoard()[0].length)
			{
				baza--;
			}
		}
		deltaLinii=board.nrLinii;
		board.nrLinii+=baza;
		deltaLinii=board.nrLinii-deltaLinii;
		board.updateScor();
	}
	public void rotireStanga()
	{
		int[][] formaRotita=transpunereMatrice(coordonate);
		inversareLinii(formaRotita);
		if(x+formaRotita[0].length>board.latime || y+formaRotita.length>20)	//verificare margini dreapta+jos
		{
			return;
		}
		//verificare colisiune cu alte forme
		for(int linie=0;linie<formaRotita.length;linie++)
		{
			for(int col=0;col<formaRotita[linie].length;col++)
			{
				if(formaRotita[linie][col]!=0)
				{
					if(board.getBoard()[y+linie][x+col]!=null)
					{
						return;
					}
				}
			}
		}
		coordonate=formaRotita;
	}
	public void rotireDreapta()
	{
		int[][] formaRotita=transpunereMatrice(coordonate);
		inversareColoane(formaRotita);
		if(x+formaRotita[0].length>board.latime || y+formaRotita.length>20)	//verificare margini dreapta+jos
		{
			return;
		}
		//verificare colisiune cu alte forme
		for(int linie=0;linie<formaRotita.length;linie++)
		{
			for(int col=0;col<formaRotita[linie].length;col++)
			{
				if(formaRotita[linie][col]!=0)
				{
					if(board.getBoard()[y+linie][x+col]!=null)
					{
						return;
					}
				}
			}
		}
		coordonate=formaRotita;
	}
	private int[][] transpunereMatrice(int[][] matrice)
	{
		int[][] temp=new int[matrice[0].length][matrice.length];
		for(int linie=0;linie<matrice.length;linie++)
		{
			for(int col=0;col<matrice[0].length;col++)
			{
				temp[col][linie]=matrice[linie][col];
			}
		}
		return temp;
	}
	private void inversareLinii(int[][] matrice)
	{
		int mijloc=matrice.length/2;
		for(int linie=0;linie<mijloc;linie++)
		{
			int[] temp=matrice[linie];
			matrice[linie]=matrice[matrice.length-linie-1];
			matrice[matrice.length-linie-1]=temp;
		}
	}
	private void inversareColoane(int[][] matrice)
	{
		for(int linie=0;linie<matrice.length;linie++)
		{
			for(int st=0,dr=matrice[0].length-1;st<dr;st++,dr--)
			{
				int temp;
				temp=matrice[linie][st];
				matrice[linie][st]=matrice[linie][dr];
				matrice[linie][dr]=temp;
			}
		}
	}
	public void desenForma(Graphics g)
	{
		for(int linie=0;linie<coordonate.length;linie++)
			for(int col=0;col<coordonate[0].length;col++)	//desenare forma
			{
				
				if(coordonate[linie][col]!=0)
				{
					g.setColor(culoare);
					g.fillRect(col*dimensiune_cel+x*dimensiune_cel, 
							linie*dimensiune_cel+50+y*dimensiune_cel, dimensiune_cel, dimensiune_cel);
				}
			}}
	//desenarea formei urmatoare
	public void desenFormaUrmatoare(Graphics g)
	{
		g.setColor(Color.white);
		g.setFont(new Font("Arial",Font.BOLD,24));
		g.drawString("URMEAZA", 250, 100);
		g.drawRect(250,110,90,70);
		for(int linie=0;linie<coordonate.length;linie++)
		{
			for(int col=0;col<coordonate[0].length;col++)
			{
				if(coordonate[linie][col]!=0)
				{
					g.setColor(culoare);
					g.fillRect(255+col*dimensiune_cel,115+linie*dimensiune_cel, dimensiune_cel, dimensiune_cel);
				}
			}}}
	public void softDrop()	//mecanica soft drop
	{
		if(startSoft==0)
			startSoft=y+coordonate.length;
		if(delayMiscare>nivele[nivelCurent]/8)
			delayMiscare=delayMiscare/2;
	}
	public void vitezaNormala()	//anuleaza soft drop
	{
		if(y+coordonate.length!=board.inaltime)
			startSoft=0;
		delayMiscare=delayMiscareActual;
	}
	public void miscareStanga()
	{
		if(x+deltaX<0)
		{
			deltaX=0;
		}
		else
		{
			deltaX=-1;
		}
	}
	public void miscareDreapta()
	{
		if(x+deltaX<=latime)
			{deltaX=1;}
	}
	public int getX()
	{
		return x;
	}
	public int getY()
	{
		return y;
	}
	public int[][] getCoordonate()
	{
		return coordonate;
	}
	public int getStartSoft()
	{
		return startSoft;
	}
}
