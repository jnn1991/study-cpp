#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>

using std::string;
using std::pair;
using std::vector;
using std::map;
using std::unordered_map;
using std::set;

class IndexProducer
{
public:
    IndexProducer(const string & dict_path);
    void build_index();//创建索引
    void store_index(const char * filepath);//将索引写入文件

private:
    string _dict_path;//词典存放路径
    vector < pair < string, int > > _dict;//读取词典内容
    unordered_map < char, set<int> > _index;//索引内容

};

