#include "Mylogger.h"

#include <iostream>
using std::cout;
using std::endl;

namespace wd
{
Mylogger * Mylogger::_pInstance = nullptr;

Mylogger * Mylogger::getInstance()
{
    if(_pInstance == nullptr) {
        _pInstance =new Mylogger();
    }
    return _pInstance;
}
void Mylogger::destroy()
{
    if(_pInstance)
        delete _pInstance;
}
void Mylogger::error(const char * msg)
{
    _root.error(msg);
}
void Mylogger::warn(const char * msg)
{
    _root.warn(msg);
}
void Mylogger::info(const char * msg)
{
    _root.info(msg);
}
void Mylogger::debug(const char * msg)
{
    _root.debug(msg);
}

Mylogger::Mylogger()
: _root(Category::getRoot().getInstance("root"))
{
    PatternLayout *ptn1 = new PatternLayout();
    ptn1->setConversionPattern("%d [%p] %m%n");

    PatternLayout *ptn2 = new PatternLayout();
    ptn2->setConversionPattern("%d [%p] %m%n");

    OstreamAppender * ostreamAppenderd = new OstreamAppender("ostreamAppenderd",&cout);
    ostreamAppenderd->setLayout(ptn1);

    FileAppender *fileAppender = new FileAppender("fileAppender","debug.log");
    fileAppender->setLayout(ptn2);

    _root.addAppender(ostreamAppenderd);
    _root.addAppender(fileAppender);
    _root.setPriority(Priority::DEBUG);

    cout << "Mylogger()" << endl;
}

Mylogger::~Mylogger()
{
    Category::shutdown();
    cout << "~Mylogger()" << endl;
}
}//end of namespace wd

