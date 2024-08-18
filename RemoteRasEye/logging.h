#ifndef LOGGING_H
#define LOGGING_H

extern char ERROR[3][64];

void getCurrentTime(char* curtm, size_t size);
void writeLog(char* err); 

#endif // LOGGING_H
