#include "Engine.h"

bool Engine::ItemCollision(Rect<float> &playerRect)
{
	for (auto iter = m_dotsMap.begin(); iter != m_dotsMap.end(); ++iter) {
		if ((*iter)->GetRect()->intersects(playerRect)) {
			currentScore += (*iter)->getPoints();
			delete *iter;
			iter = m_dotsMap.erase(iter);
			cout << "size" << m_dotsMap.size() << endl;
		}
	}
	for (auto iter = m_fruitMap.begin(); iter != m_fruitMap.end(); ++iter) {
		if ((*iter)->GetRect()->intersects(playerRect)) {
			currentScore += (*iter)->getPoints();
			delete *iter;
			iter = m_fruitMap.erase(iter);
			cout << "check" << endl;
		}
	}
	if (m_dotsMap.size() < 5)
	{
		//m_level++;
		reset();
		return true;
	}
	return false;
}
