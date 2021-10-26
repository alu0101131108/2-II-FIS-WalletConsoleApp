#include "monedero.hpp"
#include "banco.hpp"

monedero::monedero(void){
    saldo_ = 0;
    historial_.clear();
}

float monedero::get_saldo(void)const{
  return saldo_;
}

bool monedero::ingresar_saldo(float saldo){
    banco caixa;
    if (caixa.validar_intercambio()){
        saldo_ = saldo_ + saldo;
        std::string auxiliar = std::to_string(saldo);
        historial_.push_back(auxiliar);
        //std::cout << "El saldo se han ingresado correctamente " << saldo << "v€" << std::endl;
        return true;
    }
    else {
      std::cout << "El banco no ha validado sus credenciales, por favor revise el numero de cuenta bancaria" << std::endl;
      return false;
    }
}

bool monedero::retirar_saldo(float a_retirar) {
  if (get_saldo() < a_retirar){
    std::cout << "ERROR. No tiene saldo suficiente." << '\n';
    return false;
  }else {
    std::string auxiliar = std::to_string(-a_retirar);
    historial_.push_back(auxiliar);
    saldo_ = saldo_ - a_retirar;
    std::cout << "Se han retirado " << a_retirar << " v€" << "correctamente" << std::endl;
    return true;
  }
}

bool monedero::intercambiar_monedas(float euros){
    banco banco;
    if(banco.comprobar_saldo(euros)){
        std::cout << "Se han cambiado " << euros << "€ por " << euros*1.5 << "v€ " << std::endl;
        ingresar_saldo(euros*1.5);
        return true;
    }else{
        std::cout << "El banco no ha validado la transferencia" << std::endl;
        return false;
    }
}

void monedero::mostrar_historial(void)const {
  for (int i = historial_.size()-1; i >=0 ; i--)
    std::cout << "Transferecia numero " << i << ": " << historial_[i] << std::endl;
}

std::ostream& operator<<(std::ostream& os, const monedero &monedero){
    os << "Saldo actual = " << monedero.get_saldo() << " v€ " << std::endl;
    os << "Las transferencias realizadas son:" << std::endl;
    monedero.mostrar_historial();
    return os;
}
