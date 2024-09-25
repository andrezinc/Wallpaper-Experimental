#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>
#include <iostream>
int main(){
	sf::RenderWindow window(sf::VideoMode(sf::VideoMode::getDesktopMode().width,sf::VideoMode::getDesktopMode().height),"Wallpaper");
	window.setKeyRepeatEnabled(false);
	sf::Texture image;
	float j=2;
	std::string vetor[10];
	sf::Vector2f incr(0.9f,0.9f);
	float change=0.4f;
	for(int i=0;i<10;i++)
		vetor[i]="fotos/imagem"+std::to_string(i)+".png";
	image.loadFromFile(vetor[7]);
	sf::Sprite cat(image);
	sf::Vector2u size= image.getSize();
	cat.scale(change,change);
	cat.setOrigin(size.x/2,size.y/2);
	int acres=0;
	while(window.isOpen()){
		sf::Event event;
		while(window.pollEvent(event)){
			if(event.type==sf::Event::Closed){
				window.close();
			}
		}		
		if(event.type == sf::Event::KeyPressed){
			if(event.key.code==sf::Keyboard::W){
			cat.scale(1.1f,1.1f);
			change*=1.1f;
			}
		}
		if(event.type == sf::Event::KeyPressed){
			if(event.key.code==sf::Keyboard::S){
			cat.scale(0.9f,0.9f);
			change*=0.9f;
			}
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
				acres+=1;
			}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
				acres-=1;
		}

		if((cat.getPosition().x+(size.x*change/2)>window.getSize().x && incr.x>0)||(cat.getPosition().x - (size.x*change/2)< 0 && incr.x<0)){
			incr.x = -incr.x;
			j++;
			image.loadFromFile(vetor[int(j)%10]);
			size=image.getSize();
			acres+=20;
			if(acres>360)acres=0;
		}
		if((cat.getPosition().y+(size.y*change/2)>window.getSize().y && incr.y>0)||(cat.getPosition().y - (size.y*change/2)<0 && incr.y<0)){
			incr.y=-incr.y;
			j++;
			image.loadFromFile(vetor[int(j)%10]);
			size=image.getSize();
			acres+=20;
		}
	cat.setRotation(acres);
	window.clear(sf::Color::Black);
	cat.setPosition(cat.getPosition()+incr);
	window.draw(cat);
	window.display();
	}
}
