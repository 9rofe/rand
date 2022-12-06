#include "Engine.h"

bool Engine::ItemCollision(Rect<float> playerRect)
{
	for (auto iter = m_dotsMap.begin(); iter != m_dotsMap.end(); ++iter) {
		if ((*iter)->GetRect().intersects(playerRect)) {
			//cout << "DOT COLLISION!" << endl;
			iter = m_dotsMap.erase(iter);
			currentScore += (*iter)->getPoints();
		}
	}
	for (auto iter = m_fruitMap.begin(); iter != m_fruitMap.end(); ++iter) {
		if ((*iter)->GetRect().intersects(playerRect)) {
			//cout << "FRUIT COLLISION!" << endl;
			iter = m_fruitMap.erase(iter);
			currentScore += (*iter)->getPoints();
		}
	}
	if (m_dotsMap.size() == 0)
	{
		//m_level++;
		reset();
		return true;
	}
	return false;
}
