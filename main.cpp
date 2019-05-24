#include<iostream>

#include<typeinfo>
#include "locuinta.h"
#include "casa.h"
#include "apartament.h"
#include "gestiune.h"




void meniu()
{
     system("cls");
     std::cout<<"||||||||||||||||||||||||||||||||||||||||\n";
     std::cout<<"|| Optiuni:                           ||\n";
	 std::cout<<"|| 1-Afiseaza locuintele inchiriate   ||\n";
	 std::cout<<"|| 2-Incheie                          ||\n";
	 std::cout<<"|| 3-Afiseaza toti clientii           ||\n";
	 std::cout<<"|| 4-Cine este al x-lea client?       ||\n";
     std::cout<<"||||||||||||||||||||||||||||||||||||||||\n";

}

void inchiriere ()
{

    Gestiune<Locuinta> Locuinte;
    Gestiune<char*> Nume;

    while(1)
    {
        char locuinta;
        int ok;
        std::cout<<"Inchiriezi sau te opresti?\n1/0: ";
        std::cin>>ok;
        if(ok)
        {
        std::cout<<"Ce doresti sa inchiriezi?\nApartament(1)/Casa(2): ";
        std::cin>>locuinta;
        system("cls");
        Locuinta *loc;

        if(locuinta=='1')
            {
                loc=new Apartament;
                std::cin>>*loc;
                Locuinte+=(loc);
                Nume+=(*loc).getName();

            }
        else
        if(locuinta=='2')
            {
                loc=new Casa;
                std::cin>>*loc;
                Locuinte+=(loc);
                Nume+=(*loc).getName();

            }
        else
            std::cout<<"Locuinta invalida\n";

        }
        else
            break;

    }

    meniu();

    while(1)
    {
        switch(_getch())
        {
            case '1': {  std::cout<<Locuinte<<"\n"; Sleep(2500); system("cls"); meniu(); break;}
            case '2': {  return;}
            case '3': { std::cout<<Nume<<"\n"; Sleep(1500); system("cls"); meniu(); break;}
            case '4': { int poz; std::cout<<"Al catalea client?: "; std::cin>>poz; try {char *client=Nume.getClient(poz-1); std::cout<<"\nNumele clientului: "<<client<<"\n"; }catch(const char *msg) {std::cout<<msg<<"\n";}  Sleep(1000); system("cls"); meniu();  break;}
            default: std::cout<<"Optiune inexistenta\n"; Sleep(500); system("cls");
        }

    }

}



int main()
{

    inchiriere();
	return 0;
}
