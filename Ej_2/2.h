#ifndef LOGGING_H
#define LOGGING_H

#include <string>
using namespace std;

enum class logTag { DEBUG, INFO, WARNING, ERROR, CRITICAL, EXTRA };

// Function declarations
void logMessage(string message, logTag severityLevel);
void logMessage(string message, string fileName, int errorLine);
void logMessage(string message, string userName);

#endif // LOGGING_H