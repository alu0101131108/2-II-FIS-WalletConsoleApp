#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>


#pragma once

//#include "../clase usuario/usuario.cpp"


class servicio {

  private:
    int id_;
    std::string nombre_;
    std::string autor_;
    float precio_;
    float media_valoraciones_;
    unsigned total_valoraciones_;
    std::string descripcion_;

  public:
    servicio();
    servicio(std::string nombre, std::string autor, float precio, std::string descripcion);
    ~servicio(){}

    void set_Nombre(std::string nombre);
    void set_Id(int id);
    void set_Autor(std::string autor);
    void set_Precio(float precio);
    std::string get_Nombre() const;
    int get_Id() const;
    std::string get_Autor() const;
    float get_Precio() const;
    void mostrar();
    void leer();
    void guardar();

    void valorar_servicio(unsigned);
    void set_mediaVal(float);
    void set_totalVal(unsigned);
    inline float get_valoraciones(void)const{return media_valoraciones_;}
};
