#include "Gra.hpp"
#include <iostream>
RenderWindow window(VideoMode(800,600),"Nevermore");
Gra::Gra(void)
{
     status = KONIEC;
 
     if(!font.loadFromFile("data/rpg.ttf"))
     {
          MessageBox(NULL,"Nie znaleziono czcionki!","ERROR",NULL);
          return;
     }
 
     status = MENU;
}
Gra::~Gra(void)
{
}

void Gra::uruchomGre()
{
     while(status != KONIEC)
     {
          switch (status)
          {
          case statusGry::MENU:
               menu();
               break;
          case statusGry::GRA:
               jedenGracz();
               break;
          }
     }
}
void Gra::menu()
{
	    Text title("Nevermore",font,80);
     title.setStyle(Text::Bold);
 
     title.setPosition(800/2-title.getGlobalBounds().width/2,20);
 
     const int ile = 3;
 
     Text tekst[ile];
 
     string str[] = {"Graj","Autorzy","Wyjdz"};
     for(int i=0;i<ile;i++)
     {
          tekst[i].setFont(font);
          tekst[i].setCharacterSize(48);
 
          tekst[i].setString(str[i]);
          tekst[i].setPosition(800/2-tekst[i].getGlobalBounds().width/2,250+i*40);
     }
 
     while(status == MENU)
     {
          Vector2f mouse(Mouse::getPosition(window));
          Event event;
 
          while(window.pollEvent(event))
          {
          //Wciśnięcie ESC lub przycisk X
          if(event.type == Event::Closed || event.type == Event::KeyPressed &&
               event.key.code == Keyboard::Escape)
               status = KONIEC;
		  //kliknięcie Menu
          else if(tekst[0].getGlobalBounds().contains(mouse) &&
          event.type == Event::MouseButtonReleased && event.key.code == Mouse::Left)
               {
               status = GRA;
               }
 
          //kliknięcie EXIT
          else if(tekst[2].getGlobalBounds().contains(mouse) &&
          event.type == Event::MouseButtonReleased && event.key.code == Mouse::Left)
               {
               status = KONIEC;
               }
          }
          for(int i=0;i<ile;i++)
               if(tekst[i].getGlobalBounds().contains(mouse))
                    tekst[i].setColor(Color::Red);
               else tekst[i].setColor(Color::White);
 
          window.clear();
 
          window.draw(title);
          for(int i=0;i<ile;i++)
          window.draw(tekst[i]);
 
          window.display();
     }
}
void Gra::jedenGracz()
{
	Silnik silnik(window);
	status = MENU;
}
