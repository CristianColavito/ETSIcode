#include <cmath>
#include <iostream>
#include "Fecha.h"

Fecha::Fecha(const int &dia, const int &mes, const int &anio){
    setFecha(dia, mes, anio);
}

bool Fecha::bisiesto() const {
    return anio%400 == 0 || (anio%4 == 0 && anio%100 != 0);
}

void Fecha::setFecha(const int &dia, const int &mes, const int &anio){
    this->dia = dia;
    this->mes = mes;
    this->anio = std::abs(anio);

    if(mes < 1)
        this->mes = 1;
    else if(mes > 12)
        this->mes = 12;

    int maxDias[] = {0,31,bisiesto()?29:28,31,30,31,30,31,31,30,31,30,31};

    //Redondeo al d�a mas cercano
    if(dia < 1)
        this->dia = 1;
    else if(dia > maxDias[this->mes])
        this->dia = maxDias[this->mes];
}

void Fecha::ver() const {
    std::cout << (dia<10?"0":"") << dia << "/" << (mes<10?"0":"") << mes << "/" << anio;
}


Fecha Fecha::operator++(){ //Este es el PRE
    Fecha r = Fecha(*this)+1;

    this->dia = r.dia;
    this->mes = r.mes;
    this->anio = r.anio;

    return *this;
}
Fecha Fecha::operator++(int flag){//Este es el POST
    Fecha copia(this->dia, this->mes, this->anio);

    ++(*this);

    return copia;
}

Fecha Fecha::operator+(int a) const{
    Fecha r(*this);

    r.dia += a;

    int maxDias[] = {0,31,bisiesto()?29:28,31,30,31,30,31,31,30,31,30,31};

    //El incremento de dias afecta al mes y al a�o
    while(r.dia > maxDias[r.mes]){
        r.dia -= maxDias[r.mes];
        r.mes++;
        if(r.mes > 12){
            r.mes = 1;
            r.anio++;
        }
    }

    return r;
}

std::ostream& operator<<(std::ostream& s, const Fecha &o) {
    s << (o.dia<10?"0":"") << o.dia << "/" << (o.mes<10?"0":"") << o.mes << "/" << o.anio;
    return s;
}


Fecha operator+(const int &a, const Fecha &f){
    return f+a;
}