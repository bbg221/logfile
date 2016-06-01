#include "bbg_log.h"

#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>


// Get current date/time, format is YYYY-MM-DD.HH:mm:ss
const std::string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
    // for more information about date/time format
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    return buf;
}



static int flag  = 0;
static std::shared_ptr<mylogStruct> logPtr = std::make_shared<mylogStruct>();

std::shared_ptr<mylogStruct> getLogStream()
{
	if (1 == flag)
	{
		return logPtr;
	}

	std::string fileName = "bbg_log_" + currentDateTime() + ".log";
	logPtr->mylog_.open(fileName);

	flag = 1;

	return logPtr;
}

