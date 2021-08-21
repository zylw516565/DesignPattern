#ifndef _ISO8601_HELPER_H_
#define _ISO8601_HELPER_H_

//@file     ISO8601Helper.h
//@brief    ����ISO8601ʱ���ʽ��Unixʱ�����ת��.
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
    // ������currentTimeToISO8601
    // ���ܣ�ȡϵͳ��ǰ����ʱ���,ת��ISO8601��ʽ�ַ���
    // ���룺
    // �����
    // ����ֵ��string �ɹ�:����ISO8601��ʽ�ַ���, ���򷵻�ʧ��  ��ʽ����:2021-08-20T10:19:49Z
    // ��ע��ע��,������������ʱ���Ƕ�����,ת����Ϊ0ʱ��,ת���ɺ��ʱ���ȱ���ʱ����8��Сʱ
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
    // ������localtimeToISO8601
    // ���ܣ��Ѵ���ı���Unixʱ���,ת��ISO8601��ʽ�ַ���
    // ���룺std::time_t, Unixʱ���  ��ʽ����:1629454444
    // �����
    // ����ֵ��string �ɹ�:����ISO8601��ʽ�ַ���, ���򷵻�ʧ��  ��ʽ����:2021-08-20T10:19:49Z
    // ��ע��ע��,������������ʱ���Ƕ�����,ת����Ϊ0ʱ��,ת���ɺ��ʱ���ȱ���ʱ����8��Сʱ
    // 2021-08-20        Peter.Zhang
    /**********************************************************************************/
    static string localtimeToISO8601(const time_t timestamp)
    {
        char buf[32];
        strftime(buf, sizeof(buf), "%FT%TZ", gmtime(&timestamp));
        return buf;
    }

    /**********************************************************************************/
    // ������ISO8601ToLocalTimeStamp
    // ���ܣ���ISO8601��ʽ�ַ���ת�ɱ��ص�Unixʱ���
    // ���룺string, ISO8601��ʽ�ַ���
    // �����
    // ����ֵ��std::time_t �ɹ�: ����Unixʱ���, ʧ��: ���� -1;  ��ʽ����:1629454444
    // ��ע��ע��,�����ISO8601��ʽʱ����0ʱ��, ת����Ϊ������,ת���ɺ��ʱ����ISO8601��ʽʱ���8��Сʱ
    // 2021-08-20        Peter.Zhang
    /**********************************************************************************/
    static time_t ISO8601ToLocalTime(const string& time)
    {
        struct tm  time_struct = {};
        #ifndef WIN32
        strptime(time.data(), "%Y-%m-%dT%H:%M:%SZ", &time_struct);
        #endif
        time_struct.tm_hour += 8;    //0ʱ��ʱ��ת����(UTC+08)������ʱ��

        return mktime(&time_struct);
    }

    /**********************************************************************************/
    // ������ISO8601ToLocalTimeString
    // ���ܣ���ISO8601��ʽ�ַ���ת�ɱ���ʱ���ַ���
    // ���룺string, ISO8601��ʽ�ַ���
    // �����
    // ����ֵ��string �ɹ�: ���ر���ʱ���ַ���, ʧ��: ���ؿ��ַ���;  ��ʽ����:2021-08-20 18:14:04 
    // ��ע��ע��,�����ISO8601��ʽʱ����0ʱ��, ת����Ϊ������,ת���ɺ��ʱ����ISO8601��ʽʱ���8��Сʱ
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