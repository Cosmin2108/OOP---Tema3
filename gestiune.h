#ifndef GESTIUNE_H_INCLUDED
#define GESTIUNE_H_INCLUDED


#include <iostream>
#include<vector>
#include <typeinfo>
#include<string.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>

template<class T>
class Gestiune
{
private:
  T **house;
  int size=0, index=0;

public:
    Gestiune(){}
    Gestiune(const T **ob, int size=1){
        house=new T*[size];
        for(int i=0; i<size;i++)
         {
             house[index]=ob[i];
             ob[i]=NULL;
             index++;
         }
    }
    ~Gestiune(){
        if(index)
        {
            for(int i=0;i<index;i++)
                delete house[i];
            delete []house;
        }

    }
    Gestiune (const Gestiune &ob);
    Gestiune<T>& operator = (const Gestiune<T> &ob);
    Gestiune<T>& operator +=(T *ob);

    template<class J>
    friend std::ostream& operator <<(std::ostream &out, const Gestiune<J> &ob);

    void redimens();
    int getSize (){return index;}
    T* getOb(int poz) {return house[poz];}

};

template <>
class Gestiune <char*>
{
    std::vector <char*> client;
    int size;
    bool owns=true;
public:
    Gestiune(){}
    Gestiune(std::vector <char*> cl){ client.assign(cl.begin(),cl.end());}
    ~Gestiune(){client.clear();}
    Gestiune(Gestiune<char*> &ob){client.assign(ob.client.begin(),ob.client.end()); }

    Gestiune<char*>& operator = (const Gestiune<char*> &ob);
    Gestiune<char*>& operator += (const char *ob);
    char* getClient(int poz){ if(poz<(int)client.size())return client[poz];else throw "Pozitie invalida!\n";}
    friend std::ostream& operator <<(std::ostream &out, const Gestiune<char*> &ob);

};



template<class T>
Gestiune<T>::Gestiune(const Gestiune<T> &ob)
{
    size=ob.size;
    index=ob.index;
    house= new T*[size];
    for(int i=0;i<index;i++)
    {
         if(typeid(*(ob.house[i]))==typeid(Apartament))
                house[i]=new Apartament;
             else
                house[i]=new Casa;
        *(house[i])=*(ob.house[i]);
    }
}

template<class T>
Gestiune<T>& Gestiune<T>::operator=(const Gestiune<T> &ob)       ///De modificat
{


    for(int i=0;i<index;i++)
        delete []house[i];
    if(size)
        delete []house;

    size=ob.size;
    index=ob.index;
    house= new T*[size];

    for(int i=0;i<index;i++)
    {
        if(typeid(*(ob.house[i]))==typeid(Apartament))
            house[i]=static_cast<T*>(new Apartament);     /// static_cast se face automat oricum
        else
            house[i]=static_cast<T*>(new Casa);
        *(house[i])=*(ob.house[i]);
    }

    return *this;
}

template<class T>
void Gestiune<T>::redimens()
{
    if(size==0)
        size=2;
    else
        size=2*size;

    Gestiune <T> aux=*this;
    *this=aux;
}

template<class T>
std::ostream& operator <<(std::ostream &out, const Gestiune<T> &ob)
{
    for(int i=0;i<ob.index;i++)
    {
        out<<*(ob.house[i])<<"\n";
    }
    return out;
}

template<class T>
Gestiune<T>& Gestiune<T>::operator +=(T *ob)
{
    if(index>=size)
        (*this).redimens();

    house[index]=ob;
    ob=NULL;

    index++;
    return *this;

}

/// Functii specializare gestiune

std::ostream& operator <<(std::ostream &out, const Gestiune<char*> &ob)
{
    out<<"   | Lista de clienti:\n";
    out<<"-----------------------------------\n";
    for(int i=0;i<(int)ob.client.size();i++)
         out<<i+1<<". | "<<ob.client[i]<<"\n";
    return out;
}


Gestiune<char*>& Gestiune<char*>::operator = (const Gestiune<char*> &ob)
{
    client.clear();
    client.assign(ob.client.begin(),ob.client.end());
    return *this;
}

Gestiune<char*>& Gestiune<char*>::operator +=(const char *ob)
{
    char *name=new char[strlen(ob)];
    strcpy(name,ob);
    client.push_back(name);
    return *this;
}



#endif // GESTIUNE_H_INCLUDED
