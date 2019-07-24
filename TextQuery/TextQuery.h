/**
 * Project cpp_study
 */


#ifndef _TEXTQUERY_H
#define _TEXTQUERY_H
#include "QueryResult.h"
#include <memory>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <fstream>

using std::string;
using std::vector;
using std::map;
using std::set;
using std::shared_ptr;
class QueryResult;

class TextQuery {
public: 
    using line_no = vector<string>::size_type;
    TextQuery(std::ifstream&);

    QueryResult query(const string&) const

    void display_map();
private: 
    shared_ptr<vector<string>> _file;
    map<string,shared_ptr<set<line_on>> _wm;
    static string cleanup_str(const string&);
};
#endif //_TEXTQUERY_H
