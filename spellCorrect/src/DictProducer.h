#pragma once

#include <string>
#include <vector>
#include <map>

using std::string;
using std::map;
using std::vector;

class DictProducer
{
public:
    DictProducer(const string& dir);
    void build_dict();//创建英文字典
    void store_dict(const char * filepath);//将词典写入文件
    void show_files() const;//查看文件路径，作为测试用
    void store_index(const char * filepath);//将索引写入文件
    void show_dict() const;//查看词典，作为测试用
    void get_file();//获取文件的决对路径
    void push_dict(const string & word);//存储某个单词

private:
    string _dir;//语料库文件存放路径
    vector <string> _files;//语料库文件的绝对路径集合
    map<string,int> _dict;//词典内容

    /* SplitTool * _splitTool; */
    

};

