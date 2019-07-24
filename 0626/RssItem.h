#pragma once

#include "tinyxml2.h"
#include <string>
#include <regex>
#include <iostream>
#include <vector>
#include <fstream>
#include <boost/lexical_cast.hpp>
using std::string;

struct RssItem
{
    string title;
    string link;
    string description;
    string content;
};

class RssReader
{
public:
    /* RssReader() ; */

    void parseRss();
    void dump(const string & filename);

private:
    std::vector<RssItem> _rss;
};

