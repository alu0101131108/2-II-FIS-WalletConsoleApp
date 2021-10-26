//VARIABLES GLOBALES//
std::vector<usuario*> lista_usuarios;
std::vector<servicio*> lista_servicios;
usuario* sesion_actual = NULL;

void GuardarBDs()
{
  std::ofstream ofs;

  // Sobreescribir BD de servicios
  ofs.open("./datos/servicios.dat", std::ofstream::out | std::ofstream::trunc);
  ofs.close();
  for (int i = 0; i < lista_servicios.size(); i++)
    lista_servicios[i] -> guardar();

  ofs.open("./datos/usuarios.dat", std::ofstream::out | std::ofstream::trunc);
  ofs.close();
  for (int i = 0; i < lista_usuarios.size(); i++)
    lista_usuarios[i] -> guardar();

}

void MostrarServicios()
{
  system("clear");

  for (int i = 0; i < lista_servicios.size(); i++)
  {
    lista_servicios[i] -> mostrar();
    std::cout << '\n';
  }

  int servID;
  std::cout << "\nIngrese el ID del servicio que desea contratar o 0 si no quiere contratar ningun servicio." << '\n';
  std::cin >> servID;
  system("clear");

  if(servID != 0)
  {
    bool id_valida = false;
    int confirmacion;
    float precio;
    for (int i = 0; i < lista_servicios.size(); i++)
      if (lista_servicios[i] -> get_Id() == servID)
      {
        id_valida = true;
        precio = lista_servicios[i] -> get_Precio();
        std::cout << "Usted va a contratar el siguiente servicio:" << '\n';
        lista_servicios[i] -> mostrar();
        std::cout << "[0] Confirmar" << '\n';
        std::cout << "[1] Cancelar" << '\n';
        std::cin >> confirmacion;
        system("clear");
        if(confirmacion == 0)
        {
          if (sesion_actual -> retirarSaldo(precio))  // Realiza el cobro.
          {
            for (int j = 0; j < lista_usuarios.size(); j++) // Busca al dueño del servicio para hacerle el ingreso.
              if (lista_usuarios[j] -> get_user() == lista_servicios[i] -> get_Autor())
                lista_usuarios[j] -> ingresarSaldo(precio);

            std::cout << "Porfavor, introduzca una valoración (0 - 5) para el servicio: ";
            unsigned temp_val;
            std::cin >> temp_val;
            lista_servicios[i] -> valorar_servicio(temp_val);
          }
        }
        else
          std::cout << "Contratación cancelada." << '\n' << '\n';
      }
    if(!id_valida)
      std::cout << "No se encontró un servicio asociado a la ID proporcionada" << '\n' << '\n';
  }
}

void PublicarServicio()
{
  std::string nombre, descripcion;
  float precio;
  std::cout << "Nombre para su servicio: " << '\n';
  std::cin >> nombre;
  std::cout << "Precio: " << '\n';
  std::cin >> precio;
  std::cout << "Breve descripción: " << '\n';
  std::cin >> descripcion;

  lista_servicios.push_back(new servicio(nombre, sesion_actual -> get_user(), precio, descripcion));
  lista_servicios[lista_servicios.size() - 1] -> guardar();
}

void UserLogged()
{
  std::cout << "Usuario autenticado" << '\n';
  bool exit = false;
  int option;
  while(!exit)
  {
    std::cout << "[1] Consultar y contratar servicios" << '\n';
    std::cout << "[2] Publicar servicio" << '\n';
    std::cout << "[3] Consultar mi monedero" << '\n';
    std::cout << "[4] Comprar v€" << '\n';
    std::cout << "[5] Log out" << '\n';
    std::cin >> option;
    switch (option) {
      case 1:
        MostrarServicios();
        break;

      case 2:
        system("clear");
        PublicarServicio();
        break;

      case 3:
        system("clear");
        sesion_actual -> mostrarmonedero();
        break;

      case 4:
        system("clear");
        float cantidad;
        std::cout << "Ingresar la cantidad de euros que desea cambiar por v€. Tasa de cambio EUR-v€: 1.5" << '\n';
        std::cin >> cantidad;
        sesion_actual -> intercambiar(cantidad);
        break;

      case 5:
        sesion_actual = NULL;
        exit = true;
        system("clear");
        break;

      default:
        system("clear");
        std::cout << "Opción no válida" << '\n';
    }
  }
}

int Login()
{
  system("clear");
  std::string login(""), passwd("");

  std::cout << "LOGIN:\n" << std::endl;
  std::cout << "Usuario:" << std::endl;
  std::cin >> login;
  std::cout << "Password:" << std::endl;
  std::cin >> passwd;

  for (int i = 0; i < lista_usuarios.size(); i++)
    if (lista_usuarios[i] -> get_user() == login)
      if (lista_usuarios[i] -> get_passwd() == passwd)
      {
        sesion_actual = lista_usuarios[i];
        system("clear");
        return 0;
      }
      else
        return -1;
}

int Registro()
{
  system("clear");
  std::ofstream readUsr;
  std::string login(""), passwd("");
  std::cout << "Introduce un nombre de usuario:" << std::endl;
  std::cin >> login;
  std::cout << "Introduce una contraseña:" << std::endl;
  std::cin >> passwd;

  lista_usuarios.push_back(new usuario(login, passwd));
  lista_usuarios[lista_usuarios.size() - 1] -> guardar();

  return 0;
}

void MostrarListas()
{
  for (int i = 0; i < lista_usuarios.size(); i++)
  {
    std::cout << lista_usuarios[i] -> get_user() << "::" << lista_usuarios[i] -> get_passwd() << '\n';
    lista_usuarios[i] -> mostrarmonedero();
    std::cout << '\n';
  }

  for (int i = 0; i < lista_servicios.size(); i++)
  {
    lista_servicios[i] -> mostrar();
    std::cout << '\n';
  }
}

void MainMenu()
{
  bool exit = false;
  int option;
  system("clear");
  while(!exit)
  {
    std::cout << "[1] Login" << '\n';
    std::cout << "[2] Registrarse" << '\n';
    std::cout << "[3] Salir" << '\n';
    std::cin >> option;

    switch (option) {
      case 1:
        if (Login() == 0)
          UserLogged();
        else
          std::cout << "Error de autenticación" << '\n';
        break;

      case 2:
        Registro();
        std::cout << "Registrado correctamente" << '\n';
        break;

      case 3:
        exit = true;
        system("clear");
        break;

      // case 4:
      //   MostrarListas();
      //   break;

      default:
        std::cout << "Opción no válida" << '\n';
        system("clear");
    }
  }
}
