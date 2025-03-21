#include <iostream>
#include <chrono>
using namespace std;

// Función recursiva que compara dos cadenas de texto
constexpr bool are_equal(const char* s1,const char* s2){
  //Si se llega al final de ambas cadenas sin retornar false, son iguales
  // (las cadenas terminan con valor falsy '\0')
  if(!*s1 && !*s2){
    return true;
  }
  if(*s1 != *s2){
    return false;
  } 
  return are_equal(s1 + 1, s2 +1); //aritmética de punteros para pasar el próximo caracter
}

/*Decidi usar char* ya que teóricamente trabajar con el es más rápido al evitar 
procesos de gestión de memoria subyacentes al objeto string*/

int main() {
  cout<<"### EJERCICIO 4 ### \n ";

  constexpr const char* str1 = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890a";
  constexpr const char* str2 = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890a";
  constexpr const char* str3 = "abcdefghijklmnopqrstuv-DIFERENTE-HIJKLMNOPQRSTUVWXYZ1234567890a";


  //Testeos dados por consigna.
  auto startTime = std::chrono::high_resolution_clock::now();
  constexpr bool prueba1 = are_equal(str1, str2);
  auto endTime = std::chrono::high_resolution_clock::now();
  auto elapsedTime = std::chrono::duration_cast<std::chrono::nanoseconds>(
  endTime - startTime);  
  cout << "A are_equal (iguales) le tomó: " << elapsedTime.count() << " nanosegundos" << endl;
  
  auto startTime2 = std::chrono::high_resolution_clock::now();
  constexpr bool prueba2 = are_equal(str2, str3);
  auto endTime2 = std::chrono::high_resolution_clock::now();
  auto elapsedTime2 = std::chrono::duration_cast<std::chrono::nanoseconds>(
    endTime2 - startTime2);
  cout << "A are_equal (distintos) le tomó: " << elapsedTime2.count() << " nanosegundos" << endl;  
  

  cout << "Son iguales str1 y str2? " << (prueba1 ? "Si" : "No") << endl;
  cout << "Son iguale str2 y str3? " << (prueba2 ? "Si" : "No") << endl;
  
  return 0;
}  
/*En runtime, a are_equal le tomo 400 nanosegundos comparar los strings iguales y 200
nanosegundos comparar los strings distintos. En cambio, a la versión en tiempo de compilación
le costó tan solo 100 nanosegundos para los iguales y marca 0 nanosegundos para los distintos
(Al ser menor a 100 se ve despreciable).*/