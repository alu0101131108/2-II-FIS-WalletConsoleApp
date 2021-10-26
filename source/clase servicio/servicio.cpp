#include "servicio.hpp"

servicio::servicio() {
  id_ = -1;
  autor_ = "NULL";
  precio_ = -1;

  //////iteracion 3//////
  media_valoraciones_ = 0;
  total_valoraciones_ = 0;
}

servicio::servicio(std::string nombre, std::string autor, float precio, std::string descripcion) {
  id_ = rand() % 10000;
  nombre_ = nombre;
  autor_ = autor;
  precio_ = precio;
  descripcion_ = descripcion;

  //////iteracion 3//////
  media_valoraciones_ = 0;
  total_valoraciones_ = 0;
}

void servicio::set_Nombre(std::string nombre) {
  nombre_ = nombre;
}

void servicio::set_Id(int id) {
  id_ = id;
}

void servicio::set_Autor(std::string autor) {
  autor_ = autor;
}

void servicio::set_Precio(float precio) {
  precio_ = precio;
}

std::string servicio::get_Nombre() const{
  return nombre_;
}

int servicio::get_Id() const {
  return id_;
}

std::string servicio::get_Autor() const {
  return autor_;
}

float servicio::get_Precio() const{
  return precio_;
}

void servicio::mostrar() {
  std::cout << "Servicio " << id_ << '\n';
  std::cout << nombre_ << " por " << autor_ << '\n';
  std::cout << "Precio: " << precio_ << "v€\n";
  std::cout << "Total de valoraciones: " << total_valoraciones_ << '\n';
  std::cout << "Media de valoraciones: " << media_valoraciones_ << '\n';
  std::cout << "Descripción: " << descripcion_ << '\n';
}

void servicio::leer() {
  std::ifstream fileIn;
  fileIn.open("./datos/servicios.dat");
  if (fileIn.is_open()) {
    std::string serv, id, autor, precio;
    getline(fileIn, serv);
    std::stringstream ss(serv);
    ss >> id >> nombre_ >> autor >> precio;
    id = stoi(id);
    precio = stof(precio);
    autor_  = autor;
    fileIn.close();
  }else {
    std::cout << "No se ha podido abrir el fichero de entrada.\n";
  }
}

void servicio::guardar()
{
  std::ofstream fileOut;
  fileOut.open("./datos/servicios.dat", std::ios::app);
  if (fileOut.is_open())
  {
    fileOut << id_ << " " << nombre_ << " " << autor_ << " " << precio_ << " " << media_valoraciones_ << " " << total_valoraciones_ << '\n';
    fileOut << descripcion_ << '\n';
    fileOut.close();
  }
  else
  {
    std::cout << "No se ha podido abrir el fichero de salida.\n";
  }
}

//////iteracion 3//////
void servicio::valorar_servicio(unsigned valoracion) {
  //si metes un numero negativo te saldra un numero grandisimo
  if ( valoracion > 5 ){
    std::cout << "ERROR. No ha introducido una valoracion correcta. Debe poner de 0 a 5 siendo 0 la peor valoraciony 5 la mejor." << std::endl;
  }else{

    //sacamos el sumatorio de todas las valoraciones
    int sumatoria_valoraciones = media_valoraciones_*total_valoraciones_;

    //ahora, tenemos una valoracion mas
    total_valoraciones_++;

    //sumamos la nueva valoracion a la suma total de valoraciones
    sumatoria_valoraciones+=valoracion;

    //recalculamos la media
    media_valoraciones_ = ((float)sumatoria_valoraciones)/((float)total_valoraciones_);

  }
}
void servicio::set_mediaVal(float nueva_med)
{
  media_valoraciones_ = nueva_med;
}
void servicio::set_totalVal(unsigned nuevo_tot)
{
  total_valoraciones_ = nuevo_tot;
}
