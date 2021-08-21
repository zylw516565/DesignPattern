#include "ISO8601Helper.h"

#include <iostream>

#if 0
int main()
{
    time_t timeStamp1 = time(NULL);
    string strISO8601 = ISO8601Helper::localtimeToISO8601(timeStamp1);
    time_t timeStamp2 = ISO8601Helper::ISO8601ToLocalTime(strISO8601);
    string strLocalTime = ISO8601Helper::ISO8601ToLocalTimeString(strISO8601);

    fprintf(stderr, "timeStamp1[%d], strISO8601[%s], timeStamp2[%d], strLocalTime[%s]\n", timeStamp1, strISO8601.c_str(), timeStamp2, strLocalTime.c_str());
    if (timeStamp1 == timeStamp2)
    {
        fprintf(stderr, "ISO8601Helper test passed!!! timeStamp1[%d], timeStamp2[%d]\n", timeStamp1, timeStamp2);
    }
    else
    {
        fprintf(stderr, "ISO8601Helper test not pass!!! timeStamp1[%d], timeStamp2[%d]\n", timeStamp1, timeStamp2);
    }

    time_t diff = timeStamp2 - timeStamp1;
    int hour = (timeStamp2 - timeStamp1) / 3600;
    fprintf(stderr, "diff[%d], hour[%d]", diff, hour);

    getchar();
}

#endif
