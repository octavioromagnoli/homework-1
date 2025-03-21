#include "1.h"
#include <iostream>
using namespace std;

int main() {
  cout<<"### EJERCICIO 1 ### \n Consigna a) \n";

  int n;
  cout << "Ingrese la dimension de su matriz cuadrada:";
  cin >> n;
  int** matrix = create_matrix(n);

  // imprimo la matriz en forma cuadrada para que el usuario la pueda ver
  cout << "Se creo la matriz: \n";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << matrix[i][j] << " ";
    }
    cout << "\n";
  }

  cout<<"\nConsigna b) \n";

  print_matrix(matrix, n);

  // Elimino la matriz para evitar fugas de memoria
  for (int i = 0; i < n; i++) {
    delete[] matrix[i];
    matrix[i] = nullptr; // Seteo a nullptr
  }
  delete[] matrix;
  matrix = nullptr; // Seteo a nullptr
}

int** create_matrix(const int n){
  try{
    // Reservo memoria para un arreglo de punteros a enteros
    int** matrix = new int*[n];
    int count = 1;
    for (int i = 0; i < n; i++){
      // Reservo memoria para cada fila de la matriz
      matrix[i] = new int[n];
      for (int j =0; j < n; j++){
        matrix[i][j] = count++; //Relleno cada posición contando
      }
    }
    return matrix;
  } catch(const bad_alloc& e){ //Manejo de errores
    cerr << "Error al alocar memoria" << e.what() << endl;
    exit(EXIT_FAILURE); 
  }
}

void print_matrix(int** matrix, int n){
  /* Itero la matriz entera de abajo hacia arriba arrancando de la ultima 
  posición. Obtengo la fila como la parte entera de dividir por la dimension
  y la columna como el resto.*/
  for(int i = ((n*n) - 1); i>=0; i--){
    int row = static_cast<int>(i / n);
    int column = i%n;
    cout << "M[" << row << "][" << column << "]:" << matrix[row][column] << "\n";
  }
}
