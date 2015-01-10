#ifndef Postac_hpp
#define Postac_hpp

#include <SFML\Graphics.hpp>
class Postac: public sf::Drawable
{
	private:
        sf::Texture texture;
        int postac_X, postac_Y;
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
	    sf::Sprite sprite;
		int px, py;
        Postac();
        ~Postac();
        bool wczytajObrazek();
		void pozycja();
};

#endif
