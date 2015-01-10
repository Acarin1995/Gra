#include "Postac.hpp"

Postac::Postac(void)
{
	px=0;
	py=0;
	postac_X=0;
	postac_Y=0;
    sprite.setPosition(0,0);
}

Postac::~Postac(void)
{

}

bool Postac::wczytajObrazek()
{
	if(!texture.loadFromFile("data/images/postac.png"))
        return false;
        sprite.setTexture(texture);
        return true;
}

void Postac::pozycja()
{
		px = sprite.getPosition().x / 16; // Os x
		py = sprite.getPosition().y / 16; // Os y
}

void Postac::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
        states.texture = &texture;
        target.draw(sprite,states);
        
}
