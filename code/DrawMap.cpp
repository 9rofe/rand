#include "Engine.h"
#include <ctime>

//draw in loop
void Engine::DrawWalls(vector<Rect<float>> map)
{

	for (unsigned int i = 0; i < map.size(); i++)
	{
		Vector2f mapSize = { map.at(i).width, map.at(i).height };
		Vector2f mapPos = { map.at(i).left, map.at(i).top };
		RectangleShape wall(mapSize);
		wall.setPosition(mapPos);
		wall.setFillColor(Color::Red);
		wall.setOutlineThickness(4.0);
		wall.setOutlineColor(Color::White);
		m_Window.draw(wall);
	}
	//cout << "walls drawn" << endl;
}

//draw in loop
void Engine::DrawItems(list<Item*> dots, list<Item*> fruit)
{
	Texture text;
	text.loadFromFile("code/Textures/BitcoinLogo.png");
	for (list<Item*>::iterator iter = dots.begin(); iter != dots.end(); ++iter) {
		//Vector2f dotSize = (iter->GetSize());
		Vector2f dotPos = (*iter)->GetLocation();
		Sprite dot_Sprite;
		dot_Sprite.setTexture(text);
		dot_Sprite.setPosition(dotPos);
		/*dot.setFillColor(Color::White);
		dot.setOutlineColor(Color::Blue);*/
		m_Window.draw(dot_Sprite);
	}
	text.loadFromFile("code/Textures/TeslaLogo2.png");
	for (list<Item*>::iterator iter = fruit.begin(); iter != fruit.end(); ++iter) {
		//Vector2f fruitSize = { iter->width, iter->height };
		Vector2f fruitPos = (*iter)->GetLocation();
		Sprite fruit_Sprite;
		fruit_Sprite.setTexture(text);
		fruit_Sprite.setPosition(fruitPos);
		//fruit.setFillColor(Color::White);
		//fruit.setOutlineColor(Color::Blue);
		m_Window.draw(fruit_Sprite);
	}
}