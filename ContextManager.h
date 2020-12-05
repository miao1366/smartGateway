#ifndef _CONTEXTMANAGER_H_
#define _CONTEXTMANAGER_H_

#include <string>
#include <map>

#include "include/sensorctl.h"

class ContextManager {
public:
    ContextManager();
    ~ContextManager();
    int contextRegist(const std::string& contextName, int contextType);
    sensorctl_context_t* getContext(const std::string& contextName) const;
private:
    std::map<std::string, sensorctl_context_t*> m_contextMap;
};

#endif //_CONTEXTMANAGER_H_