/**
 * Project cpp_study
 */


#ifndef _QUERYRESULT_H
#define _QUERYRESULT_H
#include <memory>
#include <string>
#include <vector>
#include <set>
#include <iostream>

using std::ostream;
using std::string;
using std::vector;
using std::map;
using std::set;
using std::shared_ptr;

class QueryResult {
    friend ostream& print(ostream&, const QueryResult&);
public:
    typedef vector<string>::size_type line_no;
    typedef set<line_no>::const_iterator line_it;
    QueryResult(
                string s
                ,shared_ptr<set<line_no> p
                ,shared_ptr<vector<string>> f
                )
        :_sought(s)
        ,_lines(p)
        ,_file(f)
    {}
    set<line_no>::size_type size() const {  return _lines->size();  }
    line_it begin() const { return _lines->begin();  }
    line_it end() const {   return _lines->end();   }
    shared_ptr<std::vector<string>> get_file()  { return _file; }
private: 
    string _sought;
    shared_ptr<vector<string>> _file;
    shared_ptr<set<int>> _lines;
};

ostream &print(ostream&,const QueryResult&);
#endif //_QUERYRESULT_H
