#ifndef _CONFIG_H__
#define _CONFIG_H__

#include <string>
#include <vector>

#include "cJSON.h"

#include "common.h"    //struct DeviceInfo
#include "include/sensorctl.h"

using namespace std;



class Config {
public:
    Config();
    int readConfig(const char *fileName);
    ~Config();

private:
    void getCjsonValueInt(const cJSON *pstCjson, const char *pcKey, int &iObject);
    void getCjsonValueShort(const cJSON *pstCjson, const char *pcKey, short &sObject);
    void getCjsonValueStr(const cJSON *pstCjson, const char *pcKey, std::string &strObject);
    void getCjsonValueChar(const cJSON *pstCjson, const char *pcKey, char *pcObject, size_t uiObjectSize);

private:
    short     ntp_enabled;
    string    ntp_host;
    short   ntp_port;
    string    cloud_host;
    short   cloud_port;
    string    cloud_user;
    string    cloud_password;
    vector<DeviceInfo>  m_deviceVet;
    vector<sensor_t>    m_sensorVet;
};

#endif  //_CONFIG_H__ 华为