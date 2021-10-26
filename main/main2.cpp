#include <iostream>
#include "../source/clase usuario/usuario.cpp"
#include "../Funciones/funciones.cpp"


int main()
{
  srand(time(NULL));
  std::ifstream ifs;

  // Recorre usuarios.dat e inicializa el vector de usuarios.
  ifs.open("./datos/usuarios.dat");
  if (ifs.is_open())
  {
    std::string username, passwd, saldo;
    while(!ifs.eof())
    {
      ifs >> username >> passwd >> saldo;
      lista_usuarios.push_back(new usuario(username, passwd));
      lista_usuarios[lista_usuarios.size() - 1] -> ingresarSaldo(stof(saldo));
    }
    lista_usuarios.pop_back(); // Corrige error de fstream de duplicar el ultimo elemento.
    ifs.close();
  }
  else
    std::cout << "main():: Error al abrir usuarios.dat" << '\n';

  //Recorre servicios.dat e inicializa el vector de servicios.
  ifs.open("./datos/servicios.dat");
  if (ifs.is_open())
  {
    std::string serv, id = "0", nombre, autor, precio = "0", medval = "0", totval = "0", desc;
    while(!ifs.eof())
    {
      getline(ifs, serv);
      std::stringstream ss(serv);
      ss >> id >> nombre >> autor >> precio >> medval >> totval;
      getline(ifs, desc);
      lista_servicios.push_back(new servicio(nombre, autor, stof(precio), desc));
      lista_servicios[lista_servicios.size() - 1] -> set_Id(stoi(id));
      lista_servicios[lista_servicios.size() - 1] -> set_mediaVal(stof(medval));
      lista_servicios[lista_servicios.size() - 1] -> set_totalVal(stoul(totval));
    }
    lista_servicios.pop_back(); // Corrige error de fstream de duplicar el ultimo elemento.
    ifs.close();
  }
  else
    std::cout << "main():: Error al abrir servicios.dat" << '\n';

  MainMenu();
  GuardarBDs();
  return 0;
}
