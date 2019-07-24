#include "func.h"
#include "Gameconfig.h"
#include "GameTime.h"
#include <iostream>
using std::cout;
using std::endl;
using std::vector;
using namespace warcraft;
int test0()
{
    //武士生命值设置时的顺序
    vector<WarriorType> types1 = {
        DRAGON_TYPE,  
        NINJA_TYPE,  
        ICEMAN_TYPE,  
        LION_TYPE,  
        WOLF_TYPE
    };
    //Rde武士制造顺序
    vector<WarriorType> types2 = {
        ICEMAN_TYPE,
        LION_TYPE,
        WOLF_TYPE,
        NINJA_TYPE,
        DRAGON_TYPE,
    };

    //Blue武士制造顺序
    vector<WarriorType> types3 = {
        LION_TYPE,
        DRAGON_TYPE,
        NINJA_TYPE,
        ICEMAN_TYPE,
        WOLF_TYPE
    };

    //先测试游戏配置类
   warcraft::GameConfig::getInstance()->readFromFile("warcraft.conf");

#if 1
    //游戏时间类
    for(int idx=0;idx!=100;++idx)
    {
        GameTime::getInstance()->showTime();
        GameTime::getInstance()->updateTime();
    }
#endif
    GameConfig::destroy();
    GameTime::destroy();
    
    return 0;
}
int main(void)
{
    test0();
    /* return 0; */
}

