#include "Silnik.hpp"
using namespace sf;
Silnik::Silnik(sf::RenderWindow &win)
{
	//wczytanie tekstur
    swiat.wczytajkafelki();
	postac.wczytajObrazek();
    //wczytanie poziomów
	swiat.wczytajMapy();
	swiat.wczytajLokacja();
	
	uruchomSilnik(win);
}
Silnik::~Silnik(void)
{

}
void Silnik::uruchomSilnik(sf::RenderWindow &window)
{
	bool menu = false;
	while(!menu)
	{
		postac.pozycja();
		Event event;
		while(window.pollEvent(event))
		{
			if(event.type == Event::KeyReleased && event.key.code == Keyboard::Escape)
				menu = true;
			if(event.type == Event::KeyPressed && event.key.code == Keyboard::W)
			{
				if(swiat.las[postac.py-1][postac.px].isWall==false)
				postac.sprite.move( 0 , -16 );
			}
			if(event.type == Event::KeyPressed && event.key.code == Keyboard::S)
			{
				if(swiat.las[postac.py+1][postac.px].isWall==false)
				postac.sprite.move( 0 , 16 );
			}
			if(event.type == Event::KeyPressed && event.key.code == Keyboard::A)
			{
				if(swiat.las[postac.py][postac.px-1].isWall==false)
				postac.sprite.move( -16 , 0 );
			}
			if(event.type == Event::KeyPressed && event.key.code == Keyboard::D)
			{
				if(swiat.las[postac.py][postac.px+1].isWall==false)
				postac.sprite.move( 16 , 0 );
			}
			window.clear();
			if( swiat.aktywnaMapa==0)
		{
			swiat.rysujMapeGlowna(window);

		}
		else if (swiat.aktywnaMapa==1)
		{
			swiat.rysujlokacjaMiasto(window);
		}

			window.draw(postac);
			window.display();
		}
	}
}
