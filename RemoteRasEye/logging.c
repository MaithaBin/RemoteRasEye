#include <stdio.h>
#include <time.h>
#include "logging.h"

// Obtaining the current time
void getCurrentTime(char* curtm, size_t size){
	time_t tm = time(NULL);
	strftime(curtm, size,"%Y/%m/%d %a %H:%M:%S",localtime(&tm));
}

// Writing an error into a log file with hte occured time 
void writeLog(char* err){
	FILE* fptr = NULL;
	char date[128];
	
	getCurrentTime(date, sizeof(date));
	
	fptr = fopen("log.txt","a+");
	if(fptr != NULL){
		fprintf(fptr, "%s %s\n", date, err);
		fclose(fptr);
	}
}
