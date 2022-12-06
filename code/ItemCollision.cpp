#include "Engine.h"

bool Engine::ItemCollision(Rect<float> playerRect)
{
	list<Item*>::iterator iter;
	for (iter = m_dotsMap.begin(); iter != m_dotsMap.end(); ++iter) {
		if ((*iter)->GetRect().intersects(playerRect)) {
			//cout << "DOT COLLISION!" << endl;
			iter = m_dotsMap.erase(iter);
			currentScore += (*iter)->getPoints();
		}
	}
	for (iter = m_fruitMap.begin(); iter != m_fruitMap.end(); ++iter) {
		if ((*iter)->GetRect().intersects(playerRect)) {
			//cout << "FRUIT COLLISION!" << endl;
			iter = m_fruitMap.erase(iter);
			currentScore += (*iter)->getPoints();
		}
		else {
			++iter;
		}
	}
	if (m_dotsMap.size() ==0)
	{
		//m_level++;
		reset();
		return true;
	}
	return false;
}
