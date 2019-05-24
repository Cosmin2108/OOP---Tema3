#ifndef APARTAMENT_H
#define APARTAMENT_H


#include"Locuinta.h"
#include <iostream>
#include<vector>
#include <typeinfo>
#include<string.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>

class Apartament: public Locuinta
{
private:
	int etaj;
	double useful_area;
public:
	Apartament(){}
	Apartament(int etaj,int discount,const char *name, double useful_area):Locuinta(discount,name),etaj(etaj), useful_area(useful_area){}
	Apartament( Apartament &ob ):Locuinta(ob),etaj(ob.etaj), useful_area(ob.useful_area){}
	~Apartament(){}

	Apartament& operator = (Apartament &Ob);
	friend std::istream& operator >>(std::istream &in, Apartament &ob);
    friend std::ostream& operator <<(std::ostream &out, Apartament &ob);

    void citire();
    void afisare();
    double calculate_rent();


};

#endif // APARTAMENT_H
