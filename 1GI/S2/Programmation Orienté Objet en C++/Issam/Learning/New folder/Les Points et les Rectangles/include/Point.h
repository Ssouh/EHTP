#ifndef POINT_H
#define POINT_H


class Point // Point Simple
{
    public:
        Point(int a=0,int b=0);
        ~Point();

        void deplacer(int dx, int dy);
        void afficheToi();
        int saNorme();
        int sonX();
        int sonY();


    private:
        int x;
        int y;


};

#endif // POINT_H
