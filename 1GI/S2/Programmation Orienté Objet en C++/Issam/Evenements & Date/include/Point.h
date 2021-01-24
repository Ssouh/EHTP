#ifndef POINT_H
#define POINT_H


class Point
{
    public:
        Point(int a,int b);
        void showPoint();
        void inputPoint();
        bool comparePoint(Point *p);
        int normePoint();
        void plusGrandPoint(Point *p);

    protected:

    private:
        int x,y;
};

#endif // POINT_H
