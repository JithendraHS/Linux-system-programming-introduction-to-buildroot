#include <stdio.h>
#include <syslog.h>
#include <string.h>
int main(int argc, char*argv[]){
	openlog(NULL, LOG_CONS | LOG_PID | LOG_NDELAY, LOG_USER);
    if(argc < 3){
    	syslog(LOG_ERR, "!!! One or more aruguments not specified !!!");
	closelog();
	return 1;
    }else if(argc > 3){
    	syslog(LOG_ERR, "!!! More aruguments specified than expected!!!");
        closelog();
        return 1;	
    }
    if((argv[2] == NULL ) || (strlen(argv[2]) <= 0)){
        syslog(LOG_ERR, "Incorrect string");
        closelog();
        return 1;
    }
    FILE * filepointer = NULL;
    filepointer = fopen(argv[1], "wr");
    if(filepointer == NULL){
	syslog(LOG_ERR, "Failed to open file %s",argv[1]);
    }else{
    	fputs(argv[2], filepointer);
    	fputs("\n", filepointer);
    	syslog(LOG_DEBUG, "Writing %s to %s", argv[2], argv[1]);
    }

    fclose(filepointer);
    closelog();
    return 0;
}
