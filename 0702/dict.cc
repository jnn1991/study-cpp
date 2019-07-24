#include <iostream>
#include <fstream>
#include <string>
#include <map>
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using std::istringstream;
using std::ostringstream;
using std::stringstream;
using std::map;

class Dictionary
{
public:
    void read(const std::string & filename)
    {
        ifs.open(filename);
        if(!ifs.good())
        {
            cout<< ">> ifstream open file error!"<<endl;
            return;
        }
        while(ifs>>word)
        {
            for(auto &c : word)
            {
                if(!isalpha(c))
                {
                    c='\0';
                }
                c=tolower(c);
            }
            if(word=="" && word ==" ")
            {
                continue;
            }else{
                ++word_count[word];
            }
        }
    }

    void store(const std::string & filename)
    {
        ofs.open(filename);
        if(!ofs) {
            cout << "ofstream open file error!" << endl;
            return ;
        }
        for (const auto &w : word_count)
        {

            ofs <<"| " <<w.first<<" "<<w.second<<endl;
        }


    }

private:
    map<string,size_t> word_count;
    string word;
    ifstream ifs;
    ofstream ofs;
};

int main(void)
{
    Dictionary dic;
    dic.read("/home/ning/new_Holy_Bible");
    dic.store("dict.txt");
    return 0;
}

