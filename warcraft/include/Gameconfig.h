#pragma once

#include"func.h"
using std::cout;
using std::string;
using std::endl;
using std::istream;
using std::map;
using std::vector;

namespace warcraft
{

class GameConfig
{
public:
    static GameConfig * getInstance();
    static void destroy();

    void readFromConsole();//从控制台终端获取数据
    void readFromFile(const string & filename);//从配置文件中获取测试数据
    void nextGropId() { ++_currentGroupId; }//测试下一组数据

    size_t groups() const { return _groups.size();  }
    size_t currentGroupId() const {    return _currentGroupId;}
    size_t cityCount() const;
    size_t headquartersInitalElements() const;
    size_t warriorInitalLife(WarriorType key) const;
    size_t warriorInitalAttack(WarriorType key) const;

private:
    GameConfig() :_currentGroupId(0){   cout << "GameConfig()"<< endl;}
    ~GameConfig() { cout << "~GameConfig()" << endl;}
    void readFromStream(istream & is);

    struct InitData
    {
        size_t _initElements;
        size_t _cityCount;
        size_t _minutes;
        map<WarriorType,size_t> _initLifes;
        map<WarriorType,size_t> _initAttacks;
    };

private:
    static GameConfig * _pInstance;

    vector<InitData> _groups;//N组数据
    size_t _currentGroupId;//当前正在测试的一组数据
    vector<WarriorType> _initWarriorOrder;//输入时武士的生命值和攻击力设置顺序
};


}
