#include "Rectangle.h"
#ifndef RECTANGLECOLORE_H
#define RECTANGLECOLORE_H


class RectangleColore :public Rectangle // Rectagle simple se  ayant une couleur
{
    public:
        RectangleColore(int x1=0, int y1=0, int x2=1, int y2=1,int clr=0);

        void afficheToi();

        ~RectangleColore();

    private:
        int couleur;

};

#endif // RECTANGLECOLORE_H
