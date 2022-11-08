//
// Created by Teni on 10/10/2022.
//

#ifndef _JVTIME_H_
#define _JVTIME_H_

#include <strings.h>
#include <string>
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <cstdlib>
#include <sstream>
#include <ctime>
#include <exception>
#include <time.h>

// for Json::value
#include <json/json.h>
#include <json/reader.h>
#include <json/writer.h>
#include <json/value.h>

using namespace std;

class JvTime
{
private:
protected:
public:
    bool good;
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
    char tail4[64];

    JvTime(const char *);
    JvTime() { }
    struct std::tm * getStdTM(void);
    int setStdTM(struct std::tm *);
    std::string * getTimeString(void);
    Json::Value dump2JSON();
    bool JSON2Object(Json::Value);
};

JvTime *getNowJvTime(void);

#endif /* _JVTIME_H_ */
