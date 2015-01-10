#ifndef Gra_hpp
#define Gra_hpp
#include <SFML\Graphics.hpp>
#include <Windows.h>
#include <string>
#include "Silnik.hpp"
using namespace std;
using namespace sf;

class Gra
{
public:
     Gra(void);
     ~Gra(void);
 
     void uruchomGre();
 
protected:
     enum statusGry {MENU,GRA,GRA_SKONCZONA,KONIEC};
     statusGry status;
 
private:
     Font font;
 
     void menu();
	 void jedenGracz();
};
#endif
