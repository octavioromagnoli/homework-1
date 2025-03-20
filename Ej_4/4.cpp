#include <iostream>
using namespace std;
#include <chrono>

constexpr bool are_equal(const char* s1,const char* s2){
  if(!*s1 && !*s2){
    return true;
  }
  if(*s1 != *s2){
    return false;
  } 
  return are_equal(s1 + 1, s2 +1);
}

int main() {
  std::cout << "Hello, World!" << std::endl;
  constexpr const char* str1 = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890a";
  constexpr const char* str2 = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890a";
  constexpr const char* str3 = "abcdefghijklmnopqrstuv-DIFERENTE-HIJKLMNOPQRSTUVWXYZ1234567890a";

  auto startTime = std::chrono::high_resolution_clock::now();
  constexpr bool prueba1 = are_equal(str1, str2);
  auto endTime = std::chrono::high_resolution_clock::now();
  auto elapsedTime = std::chrono::duration_cast<std::chrono::nanoseconds>(
  endTime - startTime);
  cout << "A are_equal en runtime (iguales) le tomó: " << elapsedTime.count() << " nanosegundos" << endl;

  auto startTime2 = std::chrono::high_resolution_clock::now();
  constexpr bool prueba2 = are_equal(str2, str3);
  auto endTime2 = std::chrono::high_resolution_clock::now();
  auto elapsedTime2 = std::chrono::duration_cast<std::chrono::nanoseconds>(
  endTime2 - startTime2);
  cout << "A are_equal en runtime (distintos) le tomó: " << elapsedTime2.count() << " nanosegundos" << endl;


  cout << "Are str1 and str2 equal? " << (prueba1 ? "Yes" : "No") << endl;
  cout << "Are str2 and str3 equal? " << (prueba2 ? "Yes" : "No") << endl;

  return 0;
}

/*En runtime, a are_equal le tomo 400 nanosegundos comparar los strings iguales y 200
nanosegundos comparar los strings distintos. En cambio, a la versión en tiempo de compilación
le costó tan solo 100 nanosegundos para los iguales y marca 0 nanosegundos para los distintos
(Al ser menor a 100 se ve despreciable).*/