/* Null, because instance will be initialized on demand. */
#include "FunnyLogger.h"

std::string FunnyLogger::log_file = "./log.txt";

std::string FunnyLogger::getLogFile() {
    return log_file;
}

void FunnyLogger::setLogFile(std::string path){
    log_file = path;
}

void FunnyLogger::log(const char *_pcFormat, ...)
{
    FILE *fp = fopen(log_file.c_str(), "a+");
    if(fp == NULL)
    {
            return;
    }        

    va_list aptr;
    va_start(aptr, _pcFormat);
    vfprintf(fp, _pcFormat, aptr);
    va_end(aptr);

    fclose(fp);
    fp = NULL;
}