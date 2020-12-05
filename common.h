#ifndef _COMMON_H__
#define _COMMON_H__
#include <string>
#include <vector>

#define NAME_LENGTH 16
#define HOST_LENGTH 16
#define PASSWORD_LENGTH 16 
#define SENSOR_MAX_NUM 4
typedef char  int_8;

struct SensorInfo {
  char pcName[NAME_LENGTH];
  int  iId;
  int  iType;
  int  iChannelId;
};


struct DeviceInfo {
  char chName[NAME_LENGTH];
  int  iId;
  int  iType;
  short  shtPublish_duration;
  size_t uiSensors_size;
  SensorInfo *pcSensor[SENSOR_MAX_NUM];
};

#endif //_COMMON_H__