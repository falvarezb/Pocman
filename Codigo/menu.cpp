#include "menu.h"

#include <ncurses.h>
Menu::Menu(std::vector< const char* > opciones)
{
	this->opciones = opciones;
	numOpciones = opciones.size();
	seleccionado = 0;
}

void Menu::printOpciones(WINDOW *w)
{
	int x, y, i;	

	x = 2;
	y = 2;
	for(i = 0; i < numOpciones; ++i)
	{	
		if(i == seleccionado) 
		{	wattron(w,A_REVERSE); //Resalta la opcion
			mvwprintw(w, y, x, "%s", opciones[i]);
			wattroff(w,A_REVERSE);
		}
		else
			mvwprintw(w, y, x, "%s", opciones[i]);
		++y;
	}
	wrefresh(w);
}

void Menu::usarMenu(WINDOW *w)
{
	int tecla;
	while (true)
	{
		printOpciones(w);
		opcion = -1;
		tecla = getch();
		if(tecla == KEY_UP)
		{ 	
			if (seleccionado == 0)
				seleccionado = numOpciones -1;
			else 
				--seleccionado;
		}
			
		if(tecla == KEY_DOWN) 
		{	
			if (seleccionado == numOpciones -1)
				seleccionado = 0;
			else
				++seleccionado;
		}
		if(tecla == 10)
		{
			opcion =seleccionado;
			break;
		}
		//? qué tenemos que hacer para que funcione con la funcion juego
		
	}
}


