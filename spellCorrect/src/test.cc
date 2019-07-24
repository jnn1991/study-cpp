#include "DictProducer.h"
#include "IndexProducer.h"

#include <iostream>
using std::cout;
using std::endl;

int test0()
{
    DictProducer dict("../test/new_Holy_Bible");
    dict.build_dict();
    dict.store_dict("../data/dict.dat");
    IndexProducer index("../data/dict.dat");
    index.build_index();
    index.store_index("../data/index.dat");
    return 0;
}

int main(void)
{
    test0();   
    return 0;
}

