
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

#include "fantasma.h"

Fantasma::Fantasma()
:Personaje(1, 1, "=3")
{

}

Fantasma::Fantasma(int x, int y, const char* img, int** map, int num)
:Personaje(x , y, img)
{
	salida = num;
	setPosicionActual(map[x][y]);
	map[x][y] = 3;
}

bool Fantasma::rev_pared(int movX, int movY, int** map)
{
	if (map[x+movX][y+movY]==1)
		return false;
	return true;
}

void Fantasma::movimiento(int** map, Pacman pac)
{
		/* rand()%5!!!!!
		Izquierda: 0, -1
		Derecha: 0, 1
		Arriba: -1, 0
		Abajo: 1, 0
		*/
	int num = rand()%3;

	if (salida == contador) //new
	{
		map[x][y] = 9;
		//map[x-1][y] = 1;
		x-=2;
	}

	if (num == 0)
	{
		if ((rev_pared(-1, 0, map)) and (map[x-1][y] != 3))  //Arriba: -1, 0
		{
			if (x >= pac.getX())
			{
				map[x][y] = PosicionActual;
				x-=1;
				y+=0;
				PosicionActual = map[x][y];
				map[x][y] = 3;
				return;
			}
		}
		
		if ((rev_pared(0, -1, map)) and (map[x][y-1] != 3)) //Izquierda: 0, -1
		{
			if (y >= pac.getY())
			{
				map[x][y] = PosicionActual;
				x+=0;
				y-=1;
				PosicionActual = map[x][y];
				map[x][y] = 3;
				return;
			}
		}

		if ((rev_pared(0, 1, map)) and (map[x][y+1] != 3))  //Derecha: 0, 1
		{
			if (y <= pac.getY())
			{
				map[x][y] = PosicionActual;
				x+=0;
				y+=1;	
				PosicionActual = map[x][y];
				map[x][y] = 3;
				return;
			}
		}

		if ((rev_pared(1, 0, map)) and (map[x+1][y] != 3))   //Abajo: 1, 0
		{
			if (x <= pac.getX())
			{
				map[x][y] = PosicionActual;
				x+=1;
				y+=0;	
				PosicionActual = map[x][y];
				map[x][y] = 3;
				return;
			}
		}	
	}

	if (num == 1)
	{
		if ((rev_pared(1, 0, map)) and (map[x+1][y] != 3))   //Abajo: 1, 0
		{
			if (x <= pac.getX())
			{
				map[x][y] = PosicionActual;
				x+=1;
				y+=0;	
				PosicionActual = map[x][y];
				map[x][y] = 3;
				return;
			}
		}

		if ((rev_pared(0, 1, map)) and (map[x][y+1] != 3))  //Derecha: 0, 1
		{
			if (y <= pac.getY())
			{
				map[x][y] = PosicionActual;
				x+=0;
				y+=1;	
				PosicionActual = map[x][y];
				map[x][y] = 3;
				return;
			}
		}		

		if ((rev_pared(-1, 0, map)) and (map[x-1][y] != 3))  //Arriba: -1, 0
		{
			if (x >= pac.getX())
			{
				map[x][y] = PosicionActual;
				x-=1;
				y+=0;
				PosicionActual = map[x][y];
				map[x][y] = 3;
				return;
			}
		}
		
		if ((rev_pared(0, -1, map)) and (map[x][y-1] != 3)) //Izquierda: 0, -1
		{
			if (y >= pac.getY())
			{
				map[x][y] = PosicionActual;
				x+=0;
				y-=1;
				PosicionActual = map[x][y];
				map[x][y] = 3;
				return;
			}
		}	
	}	

	if (num == 2)
	{
		if ((rev_pared(0, -1, map)) and (map[x][y-1] != 3)) //Izquierda: 0, -1
		{
			if (y >= pac.getY())
			{
				map[x][y] = PosicionActual;
				x+=0;
				y-=1;
				PosicionActual = map[x][y];
				map[x][y] = 3;
				return;
			}
		}

		if ((rev_pared(0, 1, map)) and (map[x][y+1] != 3))  //Derecha: 0, 1
		{
			if (y <= pac.getY())
			{
				map[x][y] = PosicionActual;
				x+=0;
				y+=1;	
				PosicionActual = map[x][y];
				map[x][y] = 3;
				return;
			}
		}
		
		if ((rev_pared(1, 0, map)) and (map[x+1][y] != 3)) //Abajo: 1, 0
		{
			if (x <= pac.getX())
			{
				map[x][y] = PosicionActual;
				x+=1;
				y+=0;	
				PosicionActual = map[x][y];
				map[x][y] = 3;
				return;
			}
		}

		if ((rev_pared(-1, 0, map)) and (map[x-1][y] != 3)) //Arriba: -1, 0
		{
			if (x >= pac.getX())
			{
				map[x][y] = PosicionActual;
				x-=1;
				y+=0;
				PosicionActual = map[x][y];
				map[x][y] = 3;
				return;
			}
		}	
	}
}

void Fantasma::mAzul(int** map, Pacman pac)
{					 //f   c
	if ((rev_pared(0, -1, map)) and (map[x][y-1] != 3)) //Izquierda: 0, -1
	{
		if (y <= pac.getY())
		{
			map[x][y] = PosicionActual;
			x+=0;
			y-=1;
			PosicionActual = map[x][y];
			map[x][y] = 3;
			return;
		}
	}

	if ((rev_pared(0, 1, map)) and (map[x][y+1] != 3))  //Derecha: 0, 1
	{
		if (y >= pac.getY())
		{
			map[x][y] = PosicionActual;
			x+=0;
			y+=1;	
			PosicionActual = map[x][y];
			map[x][y] = 3;
			return;
		}
	}
		
	if ((rev_pared(1, 0, map)) and (map[x+1][y] != 3)) //Abajo: 1, 0
	{
		if (x >= pac.getX())
		{
			map[x][y] = PosicionActual;
			x+=1;
			y+=0;	
			PosicionActual = map[x][y];
			map[x][y] = 3;
			return;
		}
	}

	if ((rev_pared(-1, 0, map)) and (map[x-1][y] != 3)) //Arriba: -1, 0
	{
		if (x <= pac.getX())
		{
			map[x][y] = PosicionActual;
			x-=1;
			y+=0;
			PosicionActual = map[x][y];
			map[x][y] = 3;
			return;
		}
	}	
}

void Fantasma::regresarCaja(int** map, Pacman pac)
{
	if ((x == pac.getX()) and (y == pac.getY()))
	{
		if (map[10][8] == 0)
		{
			x = 10;
			y = 8;
		}

		else if (map[10][9] == 0)
		{
			x = 10;
			y = 9;
		}

		else if (map[10][10] == 0)
		{
			x = 10;
			y = 10;
		}

		else if (map[8][9] == 0)
		{
			x = 8;
			y = 9;
		}
		contador = 0;
		salida = 15;				
	}
}

//Prueba en poner esto para que los fantasmas no vuelvan a poner bolitas, pon esto en vez de : map[x][y] = 0;
/*
if(map[x][y] == 0)// bolitas
	map[x][y] = 0;

else if(map[x][y] == 2;) //bolas
	map[x][y] = 2;

else if(map[x][y] == 9;) //espacio en blanco
	map[x][y] = 9;

*/