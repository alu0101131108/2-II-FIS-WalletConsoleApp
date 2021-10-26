#include "usuario.hpp"

usuario::usuario(std::string user, std::string passwd){
    user_ = user;
    passwd_ = passwd;
    monedero_ = new monedero();
  }

usuario::~usuario(){
  delete monedero_;
}

void usuario::set_user(std::string new_user) {
  user_ = new_user;
}

void usuario::set_passwd(std::string new_passwd) {
  passwd_ = new_passwd;
}

std::string usuario::get_user() const {
  return user_;
}

std::string usuario::get_passwd() const {
  return passwd_;
}

void usuario::guardar()
{
  std::ofstream fileOut;
  fileOut.open("./datos/usuarios.dat", std::ios::app);
  if (fileOut.is_open())
  {
    fileOut << user_ << " " << passwd_ << " " << monedero_ -> get_saldo() << '\n';
    fileOut.close();
  }
  else
    std::cout << "No se ha podido abrir el fichero de salida.\n";
}

void usuario::ingresarSaldo(float saldo) {
  monedero_->ingresar_saldo(saldo);
}

bool usuario::retirarSaldo(float saldo) {
  return monedero_ -> retirar_saldo(saldo);
}

void usuario::intercambiar(float euros) {
  monedero_->intercambiar_monedas(euros);
}


void usuario::mostrarmonedero(void)const{
  std::cout << "Saldo actual: " << monedero_->get_saldo() << std::endl;
  std::cout << "Historial de transacciones: " << std::endl;
  monedero_->mostrar_historial();
  std::cout << std::endl;
}
