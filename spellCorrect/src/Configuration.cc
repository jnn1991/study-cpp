#include "Configuration.h"

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using std::string;
using std::cout;
using std::endl;
using std::map;
using std::ifstream;
using std::istringstream;
using std::ostringstream;


map<string,string> & Configuration::getConfigMap()
{
    ifstream ifs;
    ifs.open(_filepath);
    if(!ifs.good())
    {
        cout<< ">> ifstream open file error!"<<endl;
        return _configMap;
    }
    string key,value;
    string line;
    while(getline(ifs,line))
    {
        istringstream iss(line);
        while(!iss.eof())
        {
            iss >> key >> value;
            _configMap[key] = value;
        }
    }
    return _configMap;
}
