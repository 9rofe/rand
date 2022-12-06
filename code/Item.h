#ifndef ITEM_H
#define ITEM_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
#include <vector>
#include <complex>
#include <cmath>
#include <sstream>
#include <thread>

using namespace sf;
using namespace std;

class Item
{
public:
    Item();
    Item(Vector2f location);
    Vector2f GetLocation() const;
    void SetLocation(Vector2f location);
    virtual Vector2f GetSize() const = 0;
    virtual void SetSize(Vector2f location) = 0;
    virtual int getPoints() = 0;
    virtual Rect<float> GetRect() const = 0;
protected:
    Vector2f itemLocation;
};

class Dot : public Item
{
public:
    Dot(Vector2f location, Vector2f size);
    Vector2f GetSize() const override;
    void SetSize(Vector2f location) override;
    int getPoints() override;
    Rect<float> GetRect() const override;
private:
    int m_Points;
    Rect<float> dot;
};

class Fruit : public Item
{
public:
    Fruit(Vector2f location, Vector2f size);
    Vector2f GetSize() const override;
    void SetSize(Vector2f location) override;
    int getPoints() override;
    Rect<float> GetRect() const override;
private:
    int m_Points;
    Rect<float> fruit;
};

#endif