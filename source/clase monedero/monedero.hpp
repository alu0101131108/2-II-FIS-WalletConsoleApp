#include<iostream>
#include<vector>
#include<string>

#pragma once

class monedero{

private:

    float saldo_;
    std::vector<std::string> historial_;

public:
    monedero();
    ~monedero(){}

    float get_saldo(void)const;
    
    bool ingresar_saldo(float);

    bool retirar_saldo(float);

    bool intercambiar_monedas(float);

    void mostrar_historial(void)const;
    
};