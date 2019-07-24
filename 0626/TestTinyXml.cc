#include "RssItem.h"
using namespace std;
using namespace tinyxml2;

/* RssReader::RssReader() */


void RssReader::parseRss()
{
    XMLDocument doc;
    RssItem * rssItem = new RssItem;
    doc.LoadFile("coolshell.xml");
    if(doc.ErrorID()){
        cout << "doc load error!" << endl;
        return;
    }
    XMLElement * itemElement;
        itemElement = doc.FirstChildElement("rss")->FirstChildElement("channel")->FirstChildElement("item");
    do{

        XMLElement * titleElement = itemElement->FirstChildElement("title");
        XMLElement * linkElement = itemElement->FirstChildElement("link");
        /* XMLElement * descriptionElement = itemElement->FirstChildElement("description"); */
        XMLElement * contentElement = itemElement->FirstChildElement("content:encoded");

        rssItem->title= titleElement->GetText();
        rssItem->link = linkElement->GetText();
        /* rssItem->description = descriptionElement->GetText(); */
        const char * content = contentElement->GetText();

        /* cout << "title:" << rssItem->title<< endl; */
        /* cout << "link:" << rssItem->link << endl; */
        /* cout << "content:" << content << endl; */
        /* cout << "description:" << rssItem->description << endl; */

        std::regex re("<[^>]*>");

        rssItem->content  = std::regex_replace(content,re,"");
        /* cout << "content:" << endl */
        /*     << contentProcess << endl; */
        _rss.push_back(*rssItem); 

    }while((itemElement = itemElement->NextSiblingElement("item")));
    delete(rssItem);
}

void RssReader::dump(const string & filename)
{
    std::ofstream ofs;
    ofs.open(filename,std::ios::out );
    if(!ofs)
    {
        cout << "fstream error" << endl;
        return;
    }
    int i=0;
    for(auto item = _rss.begin();item != _rss.end();item++)
    {
        std::string s=boost::lexical_cast<std::string>(++i);
        std::string doc = 
            "<doc>\n"
            "    <docid>"
            + s +
            "</docid>\n"
            "    <title>"
            + item->title +
            "</title>\n"
            "   <link>"
            + item->link +
            "</link>\n"
            "   <content>"
            + item->content +
            "</content>\n"
            "</doc>\n";
        ofs << doc;
    }
    cout << ofs.tellp() << std::endl;
    ofs.close();
}



int main(void)
{
    RssReader rssReader;
    rssReader.parseRss();
    rssReader.dump("pagelib.txt");
    return 0;
}

