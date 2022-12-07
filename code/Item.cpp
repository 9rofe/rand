#include "Item.h"

//item definitions
Item::Item(Vector2f location, Vector2f size)
{
    cout << "constructor called" <<  endl;
    item = new Rect<float>(location, size);
}

Vector2f Item::GetLocation() const
{
    return { item->left, item->top };
}

void Item::SetLocation(Vector2f location)
{
    item->left = location.x;
    item->top = location.y;
}

Vector2f Item::GetSize() const
{
    return { item->width, item->height };
}

void Item::SetSize(Vector2f location)
{
    item->width = location.x;
    item->height = location.y;
}

Rect<float>* Item::GetRect() const
{
    return item;
}

//deconstr
Item::~Item()
{
    cout << "deconstructor called" <<  endl;
    delete item;
}

//copy constr
Item::Item(const Item &origItem)
{
    cout << "copy constructor called." << endl;
    item = new Rect<float>;
   *item = *(origItem.item);
}

//assignment op
Item& Item::operator=(const Item& objToCopy)
{
   cout << "Assignment op called." << endl;
   if (this != &objToCopy) {          
        delete item;                  
        item = new Rect<float>;               
        *item = *(objToCopy.item); 
   }
   return *this;
}


//dot definitions
Dot::Dot(Vector2f location, Vector2f size) : Item(location, size)
{
    m_Points = 1;
}

int Dot::getPoints()
{
    return m_Points;
}

//fruit definitions
Fruit::Fruit(Vector2f location, Vector2f size) : Item(location, size)
{
    m_Points = 4;
}

int Fruit::getPoints()
{
    return m_Points;
}


