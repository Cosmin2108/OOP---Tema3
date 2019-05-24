#ifndef LOCUINTA_H
#define LOCUINTA_H


#include <iostream>
#include<vector>
#include <typeinfo>
#include<string.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>

class Locuinta
{
private:
	int discount;
    char *name;
public:
	Locuinta(){name=new char[40]; strcpy(name, "Default"); discount=0;}
	Locuinta(int discount, const char *name2):discount(discount){name=new char[40]; strcpy(name, name2);std::cout<<"Constr param Locuinta\n"; }
	Locuinta(Locuinta &ob): discount(ob.discount){ name=new char[40]; strcpy(name,ob.name);}
    virtual ~Locuinta(){delete []name;}

	Locuinta& operator=(Locuinta &Ob);
	friend std::istream& operator >>(std::istream &in, Locuinta &ob);
    friend std::ostream& operator <<(std::ostream &out, Locuinta &ob);

    virtual void citire()=0;
    virtual void afisare ()=0;
    virtual double calculate_rent()=0;
    char* getName(){return name;}


};

#endif // LOCUINTA_H
