#include <iostream>
#include <log4cpp/Category.hh>
#include <log4cpp/RollingFileAppender.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/PatternLayout.hh>

using std::cout;
using std::endl;
using namespace log4cpp;
int main(void)
{
    PatternLayout * ptnLayout1 = new PatternLayout();
    ptnLayout1->setConversionPattern("%d: [%p] %c %x: %m%n");
    PatternLayout * ptnLayout2 = new PatternLayout();
    ptnLayout2->setConversionPattern("%d: [%p] %c %x: %m%n");
    PatternLayout * ptnLayout3 = new PatternLayout();
    ptnLayout3->setConversionPattern("%d: [%p] %c %x: %m%n");

    OstreamAppender * ostreamAppender = new OstreamAppender("ostreamAppender",&cout);
    ostreamAppender->setLayout(ptnLayout1);

    FileAppender * fileAppender = new FileAppender("fileAppender","error.log");
    fileAppender->setLayout(ptnLayout2);

    RollingFileAppender * rollingFileAppender= new 
        RollingFileAppender("rollingFileAppender","roolingerror.log",5*1024,2);
    rollingFileAppender->setLayout(ptnLayout3);

    Category & root = Category::getRoot();
    root.setAppender(ostreamAppender);
    root.addAppender(fileAppender);
    root.addAppender(rollingFileAppender);
    root.setPriority(Priority::DEBUG);

    int cnt=100;
    while(cnt--){
        root.alert("alert message");
        root.crit("crit message");
        root.debug("debug message");
        root.error("error message");
        root.emerg("emerg message");
        root.info("info message");
        root.fatal("fatal message");
        root.warn("warn message");
    }
    Category::shutdown();//回收资源

    return 0;
}

