#include "DictProducer.h"
#include "Configuration.h"

#include <fstream>
#include <string>
#include <map>
#include <iostream>
#include <sstream>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::map;
using std::pair;
using std::stringstream;
using std::istringstream;
using std::ostringstream;

DictProducer::DictProducer(const string & dir)
    :_dir(dir)
{}

void DictProducer::build_dict()
{
    Configuration config;
    map<string,string> path;
    path=config.getConfigMap();
    ifstream ifs;
    ifs.open(path["dir_en"]);
    if(!ifs.good())
    {
        cout << ">> ifstream open file error" << endl;
        return;
    }
    string word;
    while(ifs >> word)
    {
        for(auto &c : word)
        {
            if(!isalpha(c))
            {
                c=' ';
            }
            c=tolower(c);
        }
        int index=0;
        while( (index = word.find(' ',index)) != string::npos  )
        {
            word.erase(index,1);
        }
        if(word=="")
            continue;
        else
            ++_dict[word];
    }
    ifs.close();
}

void DictProducer::store_dict(const char * filepath)//将词典写入文件
{
    ofstream ofs;
    ofs.open(filepath);
    if(!ofs)
    {
        cout << "ofstream open file error!" << endl;
        return;
    }
    for (const auto &w : _dict)
    {
        ofs << w.first << "   " << w.second << endl;
    }
    ofs.close();
}

void DictProducer::show_files() const//查看文件路径，作为测试用
{
    cout << _dir << endl;
}

/* void show_dict() const;//查看词典，作为测试用 */
/* void get_file();//获取文件的决对路径 */

void DictProducer::push_dict(const string & word)//存储某个单词
{
    ++_dict[word];
}
void store_index(const char * filepath);//将索引写入文件
