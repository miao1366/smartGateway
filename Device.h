#ifndef _DEVICE_H__
#define _DEVICE_H__

#include "include/sensorctl.h"

class Device {
public:
    Device(const sensor_t& sensor);
    ~Device();
private:
    sensorctl_context_t     *m_context;
    sensor_t                m_sensor;
};

#endif  //_DEVICE_H__