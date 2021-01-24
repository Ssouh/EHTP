#include "Point.h"
#ifndef RECTANGLE_H
#define RECTANGLE_H


class Rectangle // Rectangle simple constitué de points simples
{
    public:
        Rectangle(int x1=0, int y1=0, int x2=1, int y2=1);
        ~Rectangle();
        int SaLongueur();
        int SaLargeur();
        void afficheToi();

    private:
        Point point1;
        Point point2;
};

#endif // RECTANGLE_H
