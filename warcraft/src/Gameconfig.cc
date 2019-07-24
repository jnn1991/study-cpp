#include"func.h"
#include "Gameconfig.h"

#include <fstream>
#include <iostream>

using std::cout;
using std::string;
using std::endl;
using std::ifstream;
using std::map;
using std::vector;
using std::istream;
using namespace warcraft;

GameConfig * GameConfig::_pInstance = nullptr;

/* GameConfig::AutoRelease GameConfig::_autoRelease; */

void GameConfig::readFromStream(ifstream & is)
{
    InitData fileData;
    int groupsNumber;
    is >> groupsNumber;
    while(groupsNumber)
    {
        is >> fileData._initElements;
        is >> fileData._cityCount;
        is >> fileData._minutes;
        for(size_t i = 0;i != 5;i++)
        {
            is >> fileData._initLifes[(WarriorType)i];
        }
        for(size_t i = 0;i != 5;i++)
        {
            is >> fileData._initAttacks[(WarriorType)i];
        }
        _groups.push_back(fileData);
        groupsNumber--;
    }
}

GameConfig * GameConfig::getInstance()
{
    if(_pInstance==nullptr)
        _pInstance = new GameConfig();
    return _pInstance;

}
void GameConfig::destroy()
{
    if(_pInstance)
        delete _pInstance;
}

void readFromConsole();//从控制台终端获取数据
void GameConfig::readFromFile(const string & filename)//从配置文件中获取测试数据
{
    ifstream ifs;
    ifs.open(filename);
    readFromStream(ifs);
    
}

size_t GameConfig::cityCount() const
{
  return  _groups[_currentGroupId]._cityCount; 
}
size_t GameConfig::headquartersInitalElements() const
{
  return  _groups[_currentGroupId]._initElements; 
}
size_t GameConfig::warriorInitalLife(WarriorType key) const
{
    auto pLife = _groups[_currentGroupId]._initLifes.find(key);
    auto end =_groups[_currentGroupId]._initLifes.end();
    if(pLife == end)
        return -1;
    else
        return pLife->second;
}
size_t GameConfig::warriorInitalAttack(WarriorType key) const
{
    auto pAttacks= _groups[_currentGroupId]._initAttacks.find(key);
    auto end =_groups[_currentGroupId]._initAttacks.end();
    if(pAttacks== end)
        return -1;
    else
        return pAttacks->second;
}
