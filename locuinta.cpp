#include"locuinta.h"

/// Locuinta functii

std::istream& operator >>(std::istream &in, Locuinta &ob)
{
    std::cout<<"Numele clientului: ";
    ob.name=new char[40];
    in>>ob.name;
    std::cout<<"\nDiscount aplicat: ";
    ob.discount=-1;
    while(ob.discount==-1||ob.discount>10)
     {
         std::cout<<"Introdu un discount <= 10%: ";
         in>>ob.discount;
         if(ob.discount==-1||ob.discount>10)
         {
             system("cls");
             std::cout<<"Discount invalid. ";
         }
     }

    ob.citire();
    return in;
}


std::ostream& operator <<(std::ostream &out, Locuinta &ob)
{
    std::cout<<"Proprietar: "<<ob.name<<"\n";
    std::cout<<"Discount: " <<ob.discount<<"\n";
    ob.afisare();
    return out;
}

Locuinta& Locuinta::operator =(Locuinta &ob)
{
        if(this!=&ob)
        {
            discount=ob.discount;
            strcpy(name, ob.name);
        }

 return *this;
}
