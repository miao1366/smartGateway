#include <iostream>   //std::cout

#include "ContextManager.h"

ContextManager::ContextManager() {
    if (libsensorctl_init() != 0) {
        std::cout << "libsensorctl_init() fail " << std::endl;
    }
}
ContextManager::~ContextManager() {

}

int ContextManager::contextRegist(const std::string& contextName, int contextType) {
    if (m_contextMap.count(contextName) == 1) {
        return 1;
    }
    sensorctl_context_t* pContext = bus_context_malloc();
    if (pContext == NULL) {
        return 2;
    }
    m_contextMap[contextName] = pContext;
    return 0;
}

sensorctl_context_t* ContextManager::getContext(const std::string& contextName) const{
    
    std::map<std::string, sensorctl_context_t*>::const_iterator it = m_contextMap.find(contextName);
    if (it != m_contextMap.cend()) {
        return it->second;
    }
    
    return nullptr;
}