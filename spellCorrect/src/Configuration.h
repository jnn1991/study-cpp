#pragma once

#include <string>
#include <map>

#define CONFIG_FILE_PATH "../conf/config.ini"

class Configuration
{
public:
    Configuration()
        : _filepath(CONFIG_FILE_PATH)
    {}
    std::map<std::string,std::string> & getConfigMap();

private:
    std::string _filepath;
    std::map<std::string,std::string> _configMap;

};

