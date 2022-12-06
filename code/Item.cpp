#include "Item.h"

//item definitions
Item::Item()
{
    itemLocation = { 0.0,0.0 };
}

Item::Item(Vector2f location)
{
    itemLocation.x = location.x;
    itemLocation.y = location.y;
}

Vector2f Item::GetLocation() const
{
    return {itemLocation.x, itemLocation.y};
}

void Item::SetLocation(Vector2f location)
{
    itemLocation.x = location.x;
    itemLocation.y = location.y;
}

//dot definitions
Dot::Dot(Vector2f location, Vector2f size) : Item(location)
{
    m_Points = 1;
    dot = {itemLocation, size};
}

Vector2f Dot::GetSize() const
{
    return { dot.width, dot.height };
}

void Dot::SetSize(Vector2f location)
{
    dot.width = location.x;
    dot.height = location.y;
}

int Dot::getPoints()
{
    return m_Points;
}

Rect<float> Dot::GetRect() const
{
    return dot;
}

//fruit definitions
Fruit::Fruit(Vector2f location, Vector2f size) : Item(location)
{
    m_Points = 4;
    fruit.width = size.x;
    fruit.height = size.y;
    fruit.left = itemLocation.x;
    fruit.top = itemLocation.y;
}

Vector2f Fruit::GetSize() const
{
    return { fruit.width, fruit.height };
}

void Fruit::SetSize(Vector2f location)
{
    fruit.width = location.x;
    fruit.height = location.y;
}

int Fruit::getPoints()
{
    return m_Points;
}

Rect<float> Fruit::GetRect() const
{
    return fruit;
}

