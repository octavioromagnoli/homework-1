#include "2.h"
#include <iostream>
using namespace std;
#include <fstream>

int main() {
  int severity;
  string message;
  int logging = 1;
  
  while(logging){
    cout << "Ingrese el nivel de severidad del mensaje (0: DEBUG, 1: INFO, 2: WARNING, 3: ERROR, 4: CRITICAL, 5: EXTRA): "<<endl;

    cin >> severity;
    /* Ejemplo realista de uso de logMessage, si el usuario no sigue las instrucciones e ingresa 
     valores erroneos ("asjfid", por ejemplo) el programa termina en error y se registra en logmessage*/
    if (cin.fail()){
      logMessage("Se ingresó un nivel de seguridad invalido, se espera valor de tipo int", logTag::ERROR);
      throw runtime_error("ERROR, nivel de seguridad invalido (revisar log)");
    };
    if(severity > 5 || severity < 0){
      cout << "Valor invalido, se continuará con la etiqueta DEBUG"<<endl; //Decisión arbitraria de diseño
      severity = 0;
    }
    cin.ignore(); // Limpia el buffer de cin para poder ingresar el mensaje despues  

    cout << "Ingrese el mensaje a logear: "<<endl;
    getline(cin, message);
    
    logMessage(message, static_cast<logTag>(severity));
    
    cout<<"Desea continuar registrando? 1(YES)/0(NO)"<<endl;
    cin >> logging;
    if(logging != 1){
      logging = 0; //si se ingresa algo distinto de 1 se cierra el loop
    }
  }

  cout<<"###CONSIGNAS RESTANTES ###"<<endl<<"Se imprimirá en el log un mensaje de error en archivo.genial"<<endl;
  
  logMessage("Este mensaje es para probar el log de error en archivos", "archivo.genial", 44);
  
  cout<<endl<<"Se imprimirá en el log un mensaje de seguridad"<<endl;
  
  logMessage("Access Denied", "Octavio_Romagnoli");
  
  try {
    cout << endl << "Ocurrirá un error en runtime y se logueará con logMessage" << endl;
    throw runtime_error("ARCHIVO INEXISTENTE");
  } catch (exception& e) {
      logMessage(e.what(), __FILE__, __LINE__);
      return 1;
  }
  
  return 0;
}

void logMessage(string message, logTag severityLevel) {
  ofstream logFile("logtext.txt", ios::app);
  string severityName;
  if (!logFile.is_open()) {
    cerr << "Error: no se pudo abrir el archivo de log." << endl;
    return;
  }
  switch (severityLevel) {
    case logTag::DEBUG:
      severityName = "DEBUG";
      break;
    case logTag::INFO:
      severityName = "INFO";
      break;
    case logTag::WARNING:
      severityName = "WARNING";
      break;
    case logTag::ERROR:
      severityName = "ERROR";
      break;
    case logTag::CRITICAL:
      severityName = "CRITICAL";
      break;
    case logTag::EXTRA:
      severityName = "EXTRA";
      break;
  }

  logFile<< "[" << severityName <<"] "<< message << endl;
  
  logFile.close();
}

void logMessage(string message, string fileName, int errorLine){
  ofstream logFile("logtext.txt", ios::app);
  if (!logFile.is_open()) {
    cerr << "Error: no se pudo abrir el archivo de log." << endl;
    return;
  }
  logFile << "ERROR: in file \""<< fileName << "\", line " << errorLine << " -" << message << endl;
  logFile.close();
}

void logMessage(string message, string userName){
  ofstream logFile("logtext.txt", ios::app);
  if (!logFile.is_open()) {
    cerr << "Error: no se pudo abrir el archivo de log." << endl;
    return;
  }
  logFile << "[SECURITY] "<< message << " user: " << userName << endl;
  logFile.close();
}