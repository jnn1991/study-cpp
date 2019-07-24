#include "IndexProducer.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <set>

using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::istringstream;
using std::ostringstream;
using std::unordered_map;

IndexProducer::IndexProducer(const string & dict_path)
    :_dict_path(dict_path)
{}

void IndexProducer::build_index()
{
    ifstream ifs;
    ifs.open(_dict_path);//读取词典
    if(!ifs.good()) {
        cout << ">> ifstream open " << _dict_path<< " error!" << endl;
        return ;
    }
    pair<string,int> word_cont;
    string line;
    string key ;
    int _count;
    while(getline(ifs,line))
    {
        istringstream iss(line);
        while(!iss.eof())
        {
            iss >> key >> _count;
        }
        word_cont = make_pair(key,_count);
        _dict.push_back(word_cont);
    }
    ifs.close();
    for(size_t idx = 0; idx != _dict.size();idx++ )
    {
        for(auto c:_dict[idx].first)
        {
            _index[c].insert(idx);
        }
    }
}

void IndexProducer::store_index(const char * filepath )
{
    ofstream ofs;
    ofs.open(filepath);
    if(!ofs)
    {
        cout << "ofstream open file error!" << endl;
        return;
    }
    for(const auto & one : _index)
    {
        ofs << one.first << ": " ; 
        for(auto it = one.second.begin();it!=one.second.end();it++)
        {
            ofs << *it << " ";
        }
        ofs << '\n';
    }
    ofs.close();

}
