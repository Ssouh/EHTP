#ifndef UNPOINT_H
#define UNPOINT_H


class UnPoint
{
    public:
        UnPoint(int a=0,int b=0);
        int recupererX();
        int recupererY();

    private:
        int sonX,sonY;

};

#endif // UNPOINT_H
