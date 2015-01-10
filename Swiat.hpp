#ifndef Swiat_hpp
#define Swiat_hpp

#include <SFML\Graphics.hpp>
class Swiat
{
	private:
        sf::Sprite sprite[7];
        sf::Texture texture;
		int pozycjax;
		int pozycjay;
		int kafelek;
public:
		//"podklasy"
		enum typKafla {
			NIC,
			TRAWA,
			ZIEMIA,
			WODA,
			DRZEWO,
			LICZEBNIK
					};
	
	struct KAFEL
	{
		typKafla typ;
		bool isWall;
	};
        Swiat();
        ~Swiat();
		int aktywnaMapa;
		KAFEL las[20][20];
		int lokacjaMiasto[5][5];
        bool wczytajkafelki();
		void wczytajMapy();
		void wczytajLokacja();
		void rysujMapeGlowna(sf::RenderWindow &Window);
		void rysujlokacjaMiasto(sf::RenderWindow &Window);
};

#endif
