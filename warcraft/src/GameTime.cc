/* #include "GameTime.h" */
#include "func.h"
#include "GameTime.h"

#include <iostream>
#include <iomanip>
using std::cout;
using std::endl;
using std::setw;
using std::setfill;
using namespace warcraft;

GameTime * GameTime::_pInstance = nullptr;

GameTime * GameTime::getInstance()
{

    if(_pInstance == nullptr)
    {
        _pInstance = new GameTime();
    }
    return _pInstance;
}

void GameTime::destroy()
{
    if(_pInstance)
        delete _pInstance;
}

void GameTime::showTime() const
{
    cout<<setw(3)<<setfill('0')<< _hour << ":" << setw(2)<<setfill('0') << _minute ;

}

void GameTime::updateTime()
{
    _minute+=10;
    if(_minute==60)
    {
        _hour++;
        _minute=0;
    }
}

