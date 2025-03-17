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

    cout<<endl<<"Desea continuar loggeando? 1(YES)/0(NO)";
    cin >> logging;
    cout<<endl;
  }

  return 0;
}