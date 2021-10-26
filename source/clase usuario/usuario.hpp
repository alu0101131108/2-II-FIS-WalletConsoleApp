#include <iostream>
#include <string>

#pragma once

#include "../clase monedero/monedero.cpp"
#include "../clase servicio/servicio.cpp"

class usuario {
 private:
  std::string user_;
  std::string passwd_;
  monedero* monedero_;

 public:
  usuario(std::string, std::string);
  ~usuario();
  std::string get_user() const;
  std::string get_passwd() const;
  void set_user(std::string new_user);
  void set_passwd(std::string new_passwd);
  void guardar();
  void mostrarmonedero(void)const;
  void ingresarSaldo(float);
  bool retirarSaldo(float);
  void intercambiar(float);
};
