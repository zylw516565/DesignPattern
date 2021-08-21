#ifndef _ISO8601_HELPER_H_
#define _ISO8601_HELPER_H_

//@file     ISO8601Helper.h
//@brief    处理ISO8601时间格式跟Unix时间戳的转换.
//@author   Peter.Zhang
//@date     2021-08-20
//@version  v1.0.0.0
//@note


#include <time.h>
#include <string>

using std::string;


class ISO8601Helper
{
public:

    /**********************************************************************************/
    // 函数：currentTimeToISO8601
    // 功能：取系统当前本地时间戳,转成ISO8601格式字符串
    // 输入：
    // 输出：
    // 返回值：string 成功:返回ISO8601格式字符串, 否则返回失败  格式例如:2021-08-20T10:19:49Z
    // 备注：注意,由于我们所处时区是东八区,转换后为0时区,转换成后的时间会比本地时间少8个小时
    // 2021-08-20        Peter.Zhang
    /**********************************************************************************/
    static string currentTimeToISO8601()
    {
        char buf[32];
        time_t timeStamp = time(NULL);        
        strftime(buf, sizeof(buf), "%FT%TZ", gmtime(&timeStamp));
        return buf;
    }

    /**********************************************************************************/
    // 函数：localtimeToISO8601
    // 功能：把传入的本地Unix时间戳,转成ISO8601格式字符串
    // 输入：std::time_t, Unix时间戳  格式例如:1629454444
    // 输出：
    // 返回值：string 成功:返回ISO8601格式字符串, 否则返回失败  格式例如:2021-08-20T10:19:49Z
    // 备注：注意,由于我们所处时区是东八区,转换后为0时区,转换成后的时间会比本地时间少8个小时
    // 2021-08-20        Peter.Zhang
    /**********************************************************************************/
    static string localtimeToISO8601(const time_t timestamp)
    {
        char buf[32];
        strftime(buf, sizeof(buf), "%FT%TZ", gmtime(&timestamp));
        return buf;
    }

    /**********************************************************************************/
    // 函数：ISO8601ToLocalTimeStamp
    // 功能：把ISO8601格式字符串转成本地的Unix时间戳
    // 输入：string, ISO8601格式字符串
    // 输出：
    // 返回值：std::time_t 成功: 返回Unix时间戳, 失败: 返回 -1;  格式例如:1629454444
    // 备注：注意,传入的ISO8601格式时间是0时区, 转换后为东八区,转换成后的时间会比ISO8601格式时间多8个小时
    // 2021-08-20        Peter.Zhang
    /**********************************************************************************/
    static time_t ISO8601ToLocalTime(const string& time)
    {
        struct tm  time_struct = {};
        #ifndef WIN32
        strptime(time.data(), "%Y-%m-%dT%H:%M:%SZ", &time_struct);
        #endif
        time_struct.tm_hour += 8;    //0时区时间转化成(UTC+08)东八区时间

        return mktime(&time_struct);
    }

    /**********************************************************************************/
    // 函数：ISO8601ToLocalTimeString
    // 功能：把ISO8601格式字符串转成本地时间字符串
    // 输入：string, ISO8601格式字符串
    // 输出：
    // 返回值：string 成功: 返回本地时间字符串, 失败: 返回空字符串;  格式例如:2021-08-20 18:14:04 
    // 备注：注意,传入的ISO8601格式时间是0时区, 转换后为东八区,转换成后的时间会比ISO8601格式时间多8个小时
    // 2021-08-20        Peter.Zhang
    /**********************************************************************************/
    static string ISO8601ToLocalTimeString(const string& time)
    {
        time_t time_unix = ISO8601ToLocalTime(time);
        if (time_unix == -1)
        {
            return "";
        }

        char current_time[32];
        strftime(current_time, sizeof(current_time), "%Y-%m-%d %H:%M:%S", localtime(&time_unix));
        std::string local_time_str(current_time);

        return local_time_str;
    }

};

#endif // _ISO8601_HELPER_H_