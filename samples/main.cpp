#include "listhash.h"
#include "arraytable.h"
#include "balancetree.h"
#include "arrayhash.h"
#include "sorttable.h"
#include "scantable.h"
#include "word.h"

#include <iostream>
#include <string>

using namespace std;

constexpr int TABSIZE = 100;

PTScanTable pTab = nullptr;
string *pKeys = nullptr;
int dataCount = 0, mem;


int main() {
    TScanTable scan(TABSIZE);
    TSortTable sort(TABSIZE);
    TTreeTable tree;
    TBalanceTree baltree;
    TArrayHash arrhash(TABSIZE);
    TListHash listhash(TABSIZE);

    


    return 0;
}
