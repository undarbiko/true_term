#ifndef FunnyLogger_H
#define FunnyLogger_H
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <stdarg.h>

class FunnyLogger
{
    private:
        static std::string log_file;
        FunnyLogger() = delete;
        FunnyLogger(FunnyLogger const&) = delete;
        virtual ~FunnyLogger();
    public:
        static void setLogFile(std::string path);
        static std::string getLogFile();
        static void log(const char *_pcFormat, ...);
};

#endif //FunnyLogger_H