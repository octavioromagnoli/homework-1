#ifndef TWO_H
#define TWO_H

#include <string>
using namespace std;

enum class logTag { DEBUG, INFO, WARNING, ERROR, CRITICAL, EXTRA };

/*
  Imprime en el archivo "logtext.txt" el mensaje dado 
  con la etiqueta dada. En caso de no existir el archivo logtext lo crea. 
  Parametros:
    <string> message : mensaje a imprimir
    <logTag> severityLevel : etiqueta del mensaje 
  */
void logMessage(string message, logTag severityLevel);

/*
  Imprime en el archivo "logtext.txt" un mensaje alertando un error en el archivo dado, aclarando la linea en la que ocurrió el error.
  En caso de no existir el archivo logtext lo crea. 
  Parametros:
    <string> message : mensaje de error
    <string> fileName : nombre del archivo que tiene el error
    <int> errorLine : número de linea en la que ocurrió el error
  */
void logMessage(string message, string fileName, int errorLine);

/*
  Imprime en el archivo "logtext.txt" un mensaje de seguridad con el usuario involucrado.
  En caso de no existir el archivo logtext lo crea. 
  Parametros:
    <string> message : mensaje de seguridad
    <string> userName : nombre del usuario afectado

  */
void logMessage(string message, string userName);

#endif