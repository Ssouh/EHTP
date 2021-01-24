#ifndef DATE_H
#define DATE_H


class Date
{
    public:
        Date(int j=0, int m=0, int a=0);
        void afficheToi();
        void verification();

    protected:

    private:
        int sonJour;
        int sonMois;
        int sonAnnee;
};

#endif // DATE_H
