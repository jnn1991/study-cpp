/**
 * Project cpp_study
 */


#include "TextQuery.h"
#include "make_plural.h"
#include <fstream>
#include <sstream>
#include <cstddef>
#include <memory>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>
#include <utility>
#include <stdexcept>


using std::size_t;
using std::shared_ptr;
using std::istringstream;
using std::string;
using std::getline;
using std::vector;
using std::map;
using std::set;
using std::cerr;
using std::cout;
using std::cin;
using std::ostream;
using std::endl;
using std::ifstream;
using std::ispunct;
using std::tolower;
using std::strlen;
using std::pair;
using std::runtime_error;


typedef map<string, shared_ptr<set<TextQuery::line_no>>> wmType;

typedef wmType::const_iterator wmIter;

typedef shared_ptr<set<TextQuery::line_no> > lineType;

typedef set<TextQuery::line_no>::const_iterator lineIter;


TextQuery::TextQuery(ifstream &is): _file(new std::vector<string>) {
    string text;
    while(getline(is,text))
    {
        _file->push_back(text);
        int n = _file->size()-1;
        istringstream line(text);
        string word;
        while (line >> word){
            word = cleanup_str(word);
            lineType & lines = _wm[word];
            if(!lines)
                lines.reset(new set<line_no>);
            lines->insert(n);
        }

    }

}

string TextQuery::cleanup_str(const string & word)
{
    string ret;
    for (auto & c:word)
    {
        if(!ispunct(c))
            ret+=tolower(c);
    }
    return ret;
}

QueryResult TextQuery:: query(const string& sought) const{
    // we'll return a pointer to this set if we don't find sought
    static lineType nodata(new set<line_no>);

    // use find and not a subscript to avoid adding words to wm!
   wmIter loc = _wm.find(cleanup_str(sought));
   if(loc == _wm.end())
       return QueryResult(sought, nodata, _file);
   else
       return QueryResult(sought, loc->second, _file);

}

ostream &print(ostream & os,const QueryResult &qr)
{
    os << qr._sought << "occurs" << qr._lines->size() << " "
       << make_plural(qr._lines->size(), "time", "s") <<endl;

    // print each line in which the word appeared
    //for every element in the set 
    for (lineIter num = qr._lines->begin();num!=qr._lines->end();++num)
    {
        os << "\t(line" << *num + 1 <<") "
            << *(qr._file->begin() + *num)<<endl;
    }
    return os;
}

void TextQuery::display_map() {
    wmIter iter = _wm.begin(),iter_end = wm.end();

    for(;iter != iter_end;++iter)
    {
        cout << "word: " << iter->first << " {";
    }
    lineType text_locs = iter->second;
    lineIter loc_iter = text_locs->begin(),loc_iter_end = text_locs->end();
    while(loc_iter != loc_iter_end)
    {
        cout<<*loc_iter;
        if(++loc_iter != loc_iter_end)
            cout << ", ";
    }
    cout << "}\n";
    return;
}
