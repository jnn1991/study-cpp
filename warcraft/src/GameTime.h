#ifndef __GameTime_h__
#define __GameTime_h__

#include <func.h>

namespace warcraft
{

class GameTime
{
public:
    static GameTime * getInstance();
    static void destroy();

    void showTime() const;//打印时间
    void updateTime();//更新时间
    void reset() {  _hour = 0; _minute = 0;}
private:
    GameTime(size_t hour = 0, size_t minute = 0)
    : _hour(hour)
    , _minute(minute)
    {}


private:
    static GameTime * _pInstance;
    size_t _hour;
    size_t _minute;
};

/* GameTime * GameTime::_pInstance = nullptr; */
}

#endif
