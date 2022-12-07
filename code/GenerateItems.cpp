#include "Engine.h"

//generate once each round
list<Item*> Engine::GenerateDots()
{
	list<Item*> dotMap;
	Vector2f dotSize = { resolution.x / 96, resolution.y / 54 };
	float wallWidth = (resolution.x - (5 * (resolution.x / 16))) / 4;
	Vector2f dotPos = { (resolution.x / 16) / 3, resolution.y / 10 };
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			Item* dot_ptr = new Dot(dotPos, dotSize);
			dotMap.emplace_back(dot_ptr);
			dotPos.y += (resolution.y / 10);
		}
		dotPos.x += ((resolution.x / 16) + wallWidth);
		dotPos.y = resolution.y / 10;
	}
	cout << "dots generated" << endl;
	return dotMap;
}

//generate once each round
list<Item*> Engine::GenerateFruit()
{
	list<Item*> fruitMap;
	Vector2f fruitSize = { resolution.x / 48, resolution.y / 27 };
	float wallWidth = (resolution.x - (5 * (resolution.x / 16))) / 4;
	Vector2f fruitPos = { ((resolution.x / 16) / 3) - (resolution.x / 192), (resolution.y / 2) - (resolution.y / 108) };
	for (int i = 0; i < 5; i++)
	{
		Item* fruit_ptr = new Fruit(fruitPos, fruitSize);
		fruitMap.emplace_back(fruit_ptr);
		fruitPos.x += ((resolution.x / 16) + wallWidth);
	}
	cout << "fruits generated" << endl;
	return fruitMap;
}