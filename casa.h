#ifndef CASA_H
#define CASA_H



#include "Locuinta.h"
#include <iostream>
#include <vector>
#include <typeinfo>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>

class Casa: public Locuinta
{
private:
	int nr_etaj;
	double area_yard;/// suprafata curte
    	std::vector<double> useful_area;
public:
	Casa(){}
	Casa(int nr_etaj, double area_yard, std::vector<double> useful_area1, int discount,const char *name):Locuinta(discount,name), nr_etaj(nr_etaj), area_yard(area_yard){ useful_area.assign(useful_area1.begin(), useful_area1.end());}
	Casa(Casa &ob):Locuinta(ob), nr_etaj(ob.nr_etaj), area_yard(ob.area_yard){ useful_area.assign(ob.useful_area.begin(), ob.useful_area.end());}
	~Casa(){if(!useful_area.empty())useful_area.clear();}

	Casa& operator = (Casa &Ob);
	friend std::istream& operator >>(std::istream &in, Casa &ob);
    	friend std::ostream& operator <<(std::istream &out, Casa &ob);

	void citire();
	void afisare();
	double calculate_rent();

};

#endif // CASA_H
