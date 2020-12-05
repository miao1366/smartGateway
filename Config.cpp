#include <iostream>  //cout
#include <fstream>   //ifstream
#include <string.h>  //memset()  strncpy()

#include "cJSON.h"

#include "Config.h"

using namespace std;

#define CJSON_GET_ITEM()                                                                \
            cJSON *pstCjsonItem = cJSON_GetObjectItem(pstCjson, pcKey);                  \
            if (nullptr == pstCjsonItem) {                                               \
                std::cout << "cjson get item failed. pckey = " << pcKey << std::endl;   \
                return;                                                                 \
            }                                                                           \


int Config::readConfig(const char *fileName) {
    
    std::ifstream fstream(fileName);
    if (!fstream) {
        std::cout << "open config file failed " << std::endl;
        return 1;
    }
    fstream.seekg(0, std::ios::end);
    int streamLength = fstream.tellg();
    char buffer[streamLength +1];
    memset(buffer, 0, streamLength +1);
    fstream.read(buffer, streamLength);
    if (fstream.gcount() != streamLength) {
        fstream.close();
        std::cout << "read file data failed " << std::endl;
        return 1;
    }
    fstream.close();

    cJSON *pstJsonRoot = cJSON_Parse(buffer);
    if (NULL == pstJsonRoot) {
        std::cout << "cJSON_Parse() failed " << std::endl;
        return 1;
    }
    getCjsonValue(pstJsonRoot, "ntp_enabled", this->ntp_enabled);
    getCjsonValue(pstJsonRoot, "ntp_host", this->ntp_host);
    getCjsonValue(pstJsonRoot, "ntp_port", this->ntp_port);
    getCjsonValue(pstJsonRoot, "cloud_host", this->cloud_host);
    getCjsonValue(pstJsonRoot, "cloud_port", this->cloud_port);
    getCjsonValue(pstJsonRoot, "cloud_user", this->cloud_user);
    getCjsonValue(pstJsonRoot, "cloud_password", this->cloud_password);

    cJSON * pstCjsonArray = cJSON_GetObjectItem(pstJsonRoot, "devices");
    if (nullptr != pstCjsonArray) {
        int iArraySize = cJSON_GetArraySize(pstCjsonArray);
        for(int i = 0; i < iArraySize; ++i) {
            DeviceInfo deviceInfo = {0};
            cJSON *pstArrayItem = cJSON_GetArrayItem(pstCjsonArray, i);
            getCjsonValue(pstArrayItem, "name", deviceInfo.chName, NAME_LENGTH -1);
            getCjsonValue(pstArrayItem, "device_id", deviceInfo.iId);
            getCjsonValue(pstArrayItem, "device_type", deviceInfo.iType);
            
            cJSON *pstCjsonSensors = cJSON_GetObjectItem(pstArrayItem, "sensors");
            int iSensorSize = cJSON_GetArraySize(pstCjsonSensors);
            for (int j =0; j < iSensorSize; ++j) {
                SensorInfo *pstSensor = (SensorInfo *)malloc(sizeof(SensorInfo));
                memset(pstSensor, 0, sizeof(SensorInfo));
                cJSON *pstSensoritem = cJSON_GetArrayItem(pstCjsonSensors ,j);
                getCjsonValue(pstSensoritem, "name", pstSensor->pcName, NAME_LENGTH -1); 
                getCjsonValue(pstSensoritem, "channel_id", pstSensor->iId); 
                getCjsonValue(pstSensoritem, "sensor_id", pstSensor->iChannelId); 
                getCjsonValue(pstSensoritem, "sensor_type", pstSensor->iType); 
            } 
            
            m_deviceVet.push_back(deviceInfo);
        }
    }
    


 








    cJSON_Delete(pstJsonRoot);
}


void Config::getCjsonValueInt(const cJSON *pstCjson, const char *pcKey, int &iObject) {
    
    CJSON_GET_ITEM()
    iObject = pstCjsonItem->valueint;
}

void Config::getCjsonValueShort(const cJSON *pstCjson, const char *pcKey, short &sObject) {

    CJSON_GET_ITEM()
    sObject = (short)pstCjsonItem->valueint;
    
}

void Config::getCjsonValueStr(const cJSON *pstCjson, const char *pcKey, 
                           std::string &strObject) {
    CJSON_GET_ITEM()
    strObject = std::string(pstCjsonItem->valuestring);
}

void Config::getCjsonValueChar(const cJSON *pstCjson, const char *pcKey, 
                           char *pcObject, size_t uiObjectSize) {
    CJSON_GET_ITEM()
    strncpy(pcObject, pstCjsonItem->string, min(strlen(pstCjsonItem->string), uiObjectSize));
}

