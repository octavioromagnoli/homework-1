#include <iostream>
using namespace std;
#include <fstream>

void logMessage(string message, int severityLevel) {
  ofstream logFile("logtext.txt", ios::app);
  string severityName;

  switch (severityLevel) {
    case 0:
      severityName = "DEBUG";
      break;
    case 1:
      severityName = "INFO";
      break;
    case 2:
      severityName = "WARNING";
      break;
    case 3:
      severityName = "ERROR";
      break;
    case 4:
      severityName = "CRITICAL";
      break;
    case 5:
      severityName = "EXTRA";
      break;
  }

  logFile<< "[" << severityName <<"] "<< message << endl;
  
  logFile.close();
}

void logMessage(string message, string fileName, int errorLine){
  ofstream logFile("logtext.txt", ios::app);
  logFile << "ERROR: in file \""<< fileName << "\", line " << errorLine << " -" << message << endl;
  logFile.close();
}

void logMessage(string message, string userName){
  ofstream logFile("logtext.txt", ios::app);
  logFile << "[SECURITY] "<< message << " user: " << userName << endl;
  logFile.close();
}

int main() {
  enum logTag {DEBUG, INFO, WARNING, ERROR, CRITICAL, EXTRA};

  int severity;
  string message;
  int logging = 1;

  while(logging){
    cout << "Ingrese el nivel de severidad del mensaje (0: DEBUG, 1: INFO, 2: WARNING, 3: ERROR, 4: CRITICAL, 5: EXTRA): ";
    cin >> severity;
    cin.ignore(); // Limpia el buffer de cin para poder ingresar el mensaje despues  

    cout << "Ingrese el mensaje a logear: ";
    getline(cin, message);

    logMessage(message, severity);

    cout<<endl<<"Desea continuar registrando? 1(YES)/0(NO)";
    cin >> logging;
    if(logging != 1){
      logging = 0; //si se ingresa algo distinto de 1 se cierra el loop
    }
  }

  cout<<endl<<"Se imprimirá en el log un mensaje de error en archivo.genial"<<endl;
  
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