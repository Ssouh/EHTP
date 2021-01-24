#ifndef POINT_H
#define POINT_H


class point
{
    public:
        point();
        point(point&);
        point(int,int);
        int X_afficheToi();
        int Y_afficheToi();

    private:
        int sonX;int sonY;
};

#endif // POINT_H
