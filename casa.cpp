#include"casa.h"

/// Casa functii

void Casa::citire()
{
   double x;
   std::cout<<"Numarul de etaje ale casei: ";
   std::cin>>nr_etaj;
   std::cout<<"\nSuprafata curtii: ";
   std::cin>>area_yard;

   for(int i=0;i<nr_etaj;i++)
   {
       std::cout<<"\nSuprafata utila a etajului "<<i+1<<" : ";
       std::cin>>x;
       useful_area.push_back(x);
   }
   Sleep(1000);
   system("cls");
}

void Casa::afisare()
{
    std::cout<<"Numarul de etaje ale casei: "<<nr_etaj<<"\n";
    std::cout<<"Suprafata curte: "<<area_yard<<"\n";
    for(int i=0;i<nr_etaj;i++)
        std::cout<<"Suprafata utila pe etajul "<<i<<" : "<<useful_area[i]<<"\n\n";


}

double Casa::calculate_rent()
{
     int price_per_m=5, price_per_m_yard=6;

     double rent=0.0;
     for(int i=0;i<nr_etaj;i++)
        rent+=useful_area[i]*price_per_m;
     rent+=area_yard*price_per_m_yard;

     return rent;
}

Casa& Casa::operator=(Casa &ob)
{
    area_yard=ob.area_yard;
    nr_etaj=ob.nr_etaj;
    useful_area.assign(ob.useful_area.begin(),ob.useful_area.end());
    (*this).Locuinta::operator=(ob);
    return *this;
}
