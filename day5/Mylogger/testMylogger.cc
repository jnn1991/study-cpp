#include "Mylogger.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

void test0()
{
    wd::Mylogger::getInstance()->error(prefix("error message"));
    wd::Mylogger::getInstance()->warn("warn message");
    wd::Mylogger::getInstance()->info("info message");
    wd::Mylogger::getInstance()->debug("debug message");
}
void test1()
{
    LogError("error message");
    LogWarn("warn message");
    LogInfo("info message");
    LogDebug("debug message");
}

int main(void)
{
    /* test0(); */   
    test1();
    wd::Mylogger::getInstance()->destroy();
    return 0;
}

