#include "bbg_log.h"

#include <sys/stat.h>
#include <unistd.h>
#include <iostream>
#include <string>
#include <stdio.h>

static int flag  = 0;
static int logFileNum = 0;
static std::shared_ptr<mylogStruct> logPtr = std::make_shared<mylogStruct>();

bool isFileExist(std::string& fileName)
{
    struct stat buffer;
    return (stat (fileName.c_str(), &buffer) == 0);
}

std::shared_ptr<mylogStruct> getLogStream()
{
    if (1 == flag)
    {
        return logPtr;
    }

    std::string fileName = "bbg_log_0.log";

    for (int i = 0; i < 500; i++)
    {
        fileName = "bbg_log_" + std::to_string(i) + ".log";
        if (!isFileExist(fileName))
        {
            logFileNum = i;
            break;
        }
    }

    logPtr->mylog_.open(fileName);

    flag = 1;

    return logPtr;
}

int getLogFileNum()
{
    return logFileNum;
}

