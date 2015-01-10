#ifndef Silnik_hpp
#define Silnik_hpp
#include "Postac.hpp"
#include "Swiat.hpp"
 
class Silnik
{
public:
     Silnik(sf::RenderWindow &win);
     ~Silnik(void);
 
     void uruchomSilnik(sf::RenderWindow &window);
 
private:
     Postac postac;
	 Swiat swiat;
};
#endif
