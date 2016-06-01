#ifndef BBG_LOG_H
#define BBG_LOG_H

#include <memory>
#include <fstream>


struct mylogStruct
{
	std::ofstream mylog_;
};

std::shared_ptr<mylogStruct> getLogStream();
int getLogFileNum();

#define BBGLOG getLogStream()->mylog_<<__TIME__ <<" "<<__FILE__<<" "<<__LINE__<<" "


#endif
