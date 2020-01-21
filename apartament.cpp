#include"apartament.h"


/// Apartament functii

void Apartament::citire()
{
    std::cout<<"Etajul: ";
    std::cin>>etaj;
    std::cout<<"\nSuprafata utila: ";
    std::cin>>useful_area;
    std::cout<<"\nSucces!";

    Sleep(1000);
    system("cls");
}


void Apartament::afisare()
{
    std::cout<<"Etaj apartament: "<<etaj<<"\n"<<"Suprafata utila: "<<useful_area<<"\n\n";
}

double Apartament::calculate_rent()
{
    int price_per_m=5;
    double rent=0.0;
    rent+=useful_area*price_per_m;
    return rent;
}

Apartament& Apartament::operator=(Apartament &ob)
{

    useful_area=ob.useful_area;
    etaj=ob.etaj;
    (*this).Locuinta::operator=(ob); /// apeleaza operatorul '=' pentru partea de obiect de tip locuinta
    return *this;
}
