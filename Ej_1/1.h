#ifndef ONE_H
#define ONE_H

/*
  Crea una matriz cuadrada de dimensión n (parámetro dado).
  En caso de error al alocar memoria termina el programa.
  Parámetro:
    <int> n : dimension de la matriz cuadrada.
  */
int** create_matrix(const int n);

/*
  Imprime  en consola cada posición de una matriz cuadrada desde el valor 
  en la última fila y columna hasta el primer valor.
  Parámetros:
    <int**> matrix : la matriz a imprimir en consola
    <int> n : la dimension de la matriz
  */
void print_matrix(int** matrix, int n);

#endif