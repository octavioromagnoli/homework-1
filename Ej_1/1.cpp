#include <iostream>
using namespace std;

int** create_matrix(const int n){
  int** matrix = new int*[n];

  int count = 1;
  for (int i = 0; i < n; i++){
    matrix[i] = new int[n];
    for (int j =0; j < n; j++){
      matrix[i][j] = count++;
    }
  }
  return matrix;
}

void print_matrix(int** matrix, int n){
  for(int i = ((n*n) - 1); i>=0; i--){
    int row = static_cast<int>(i / n);
    int column = i%n;
    cout << "M[" << row << "][" << column << "]:" << matrix[row][column] << "\n";
  }
}

int main() {
  cout<<"### EJERCICIO 1 ### \n Consigna a) \n";

  int n;
  cout << "Ingrese la dimension de su matriz cuadrada:";
  cin >> n;
  int** matrix = create_matrix(n);

  cout << "Se creo la matriz: \n";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << matrix[i][j] << " ";
    }
    cout << "\n";
  }

  cout<<"\nConsigna b) \n";


  print_matrix(matrix, n);

  for (int i = 0; i < n; i++) {
    delete[] matrix[i];
  }
  delete[] matrix;
}