#include <iostream>
#include "../source/clase usuario/usuario.cpp"

int main(void){
    usuario lola("lola","1234");
    std::cout << lola.get_user() << std::endl;
    std::cout << lola.get_passwd() << std::endl;
    lola.ingresarSaldo(99);
    lola.retirarSaldo(50);
    lola.intercambiar(15);
    lola.mostrarmonedero();

    servicio niniera("niniera","lola",8,"descripcion");
    niniera.valorar_servicio(5);
    std::cout << "deberia salir 5" << std::endl;
    std::cout << "valoracion nueva:" << niniera.get_valoraciones() << std::endl;
    niniera.valorar_servicio(3);
    std::cout << "deberia salir 4 ((5+3)/2)" << std::endl;
    std::cout << "valoracion nueva:" << niniera.get_valoraciones() << std::endl;
    niniera.valorar_servicio(3);
    niniera.valorar_servicio(4);
    niniera.valorar_servicio(1);
    niniera.valorar_servicio(5);
    niniera.valorar_servicio(2);
    std::cout << "deberia salir 3.285714286 (23/7)" << std::endl;
    std::cout << "Valoracion nueva:" << niniera.get_valoraciones() << std::endl;

    return 0;
}
