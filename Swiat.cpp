#include "Swiat.hpp"
#include <iostream>
#include <fstream>
using namespace std;
Swiat::Swiat(void)
{
	aktywnaMapa=0;

}

Swiat::~Swiat(void)
{

}
void Swiat::wczytajMapy()
{
fstream file;
	file.open("data/levels/las.txt", std::ios::in);

	if(!file.is_open()) 
		std::cout<<"Nie znaleziono poziomu: ";
	else
	{
		for(int y=0;y<20;y++)
			for(int x=0;x<20;x++)
			{
				int tmp;
				file>>tmp;
				las[y][x].typ = typKafla(tmp);
			
				if(tmp==1 || tmp==2 )
					las[y][x].isWall = false;
				else
					las[y][x].isWall = true;
			}
	}
	
	file.close();
}
void Swiat::wczytajLokacja()
{
	ifstream mapa;
	mapa.open("data/levels/lokacjaMiasto.txt");
			for(int i=0;i<5;i++)
			{
    			for(int j=0;j<5;j++)
    			{
     			   mapa >> lokacjaMiasto[i][j];
     			}
     		}
}

bool Swiat::wczytajkafelki()
{
		if(!texture.loadFromFile("data/images/Mapa.png"))
        return false;
		for( int x = 0; x <= 6; x++ )
		{
			sprite[x].setTexture(texture);
			sprite[x].setTextureRect(sf::IntRect(x*16,0,16,16));
		}
        return true;
}
void Swiat::rysujMapeGlowna(sf::RenderWindow &Window)
{
	for( int x = 0; x < 20; x++ )
		{
		for( int y = 0; y < 20; y++ )
		{
			if (las[y][x].typ == Swiat::NIC)
			{
				pozycjay= y*16;
				pozycjax= x*16;
				sprite[0].setPosition(pozycjax, pozycjay);
				Window.draw(sprite[0]);
			}
			else if (las[y][x].typ == Swiat::TRAWA)
			{
				pozycjay= y*16;
				pozycjax= x*16;
				sprite[1].setPosition(pozycjax, pozycjay);
				Window.draw(sprite[1]);
			}
			else if (las[y][x].typ == Swiat::ZIEMIA)
			{
				pozycjay= y*16;
				pozycjax= x*16;
				sprite[2].setPosition(pozycjax, pozycjay);
				Window.draw(sprite[2]);
			}
			else if (las[y][x].typ == Swiat::WODA)
			{
				pozycjay= y*16;
				pozycjax= x*16;
				sprite[3].setPosition(pozycjax, pozycjay);
				Window.draw(sprite[3]);
			}
			else if (las[y][x].typ == Swiat::DRZEWO)
			{
				pozycjay= y*16;
				pozycjax= x*16;
				sprite[4].setPosition(pozycjax, pozycjay);
				Window.draw(sprite[4]);
			}
		}
	}	
	
}
void Swiat::rysujlokacjaMiasto(sf::RenderWindow &Window)
{
	for( int x = 0; x < 5; x++ )
		{
		for( int y = 0; y < 5; y++ )
		{
			if (lokacjaMiasto[y][x]== 0)
			{
				pozycjay= y*16;
				pozycjax= x*16;
				sprite[0].setPosition(pozycjax, pozycjay);
				Window.draw(sprite[0]);
			}
			else if (lokacjaMiasto[y][x]== 1)
			{
				pozycjay= y*16;
				pozycjax= x*16;
				sprite[1].setPosition(pozycjax, pozycjay);
				Window.draw(sprite[1]);
			}
			else if (lokacjaMiasto[y][x]== 2)
			{
				pozycjay= y*16;
				pozycjax= x*16;
				sprite[2].setPosition(pozycjax, pozycjay);
				Window.draw(sprite[2]);
			}
			else if (lokacjaMiasto[y][x]== 3)
			{
				pozycjay= y*16;
				pozycjax= x*16;
				sprite[3].setPosition(pozycjax, pozycjay);
				Window.draw(sprite[3]);
			}
			else if (lokacjaMiasto[y][x]== 4)
			{
				pozycjay= y*16;
				pozycjax= x*16;
				sprite[4].setPosition(pozycjax, pozycjay);
				Window.draw(sprite[4]);
			}
			else if (lokacjaMiasto[y][x]== 5)
			{
				pozycjay= y*16;
				pozycjax= x*16;
				sprite[5].setPosition(pozycjax, pozycjay);
				Window.draw(sprite[5]);
			}
		}
	}	
	
}
