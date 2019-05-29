#ifndef __DEFINES_H__
#define __DEFINES_H__

#include <string>

using TKey = std::string;

constexpr int TabHashStep = 1;
constexpr int TabMaxSize  = 500;

constexpr int ListOk    =  0;
constexpr int ListEmpty = -101;
constexpr int ListNoMem = -102;
constexpr int ListNoPos = -103;

constexpr int BalLeft  = -1;
constexpr int BalOk    =  0;
constexpr int BalRight =  1;

constexpr int HeightOk  = 0;
constexpr int HeightInc = 1;

enum TLinkPos    {FIRST, CURRENT, LAST};
enum TDataPos    {FIRST_POS, CURRENT_POS, LAST_POS};
enum TSortMethod {INSERT_SORT, MERGE_SORT, QUICK_SORT};

class TDatValue;        //
class TTabRecord;       //
class TWord;            //
class TRootLink;        //
class TDatLink;         //
class TDatList;         //
class TTable;           //
class TArrayTable;      //
class TScanTable;       //
class TSortTable;       //
class THashTable;       //
class TArrayHash;       //
class TTreeNode;        //
class TBalanceNode;     //
class TTreeTable;       //
class TBalanceTree;     //
class TListHash;        //

using PTDatValue    = TDatValue*;
using PTTabRecord   = TTabRecord*;
using PTWord        = TWord*;
using PTRootLink    = TRootLink*;
using PTDatLink     = TDatLink*;
using PTDatList     = TDatList*;
using PTTable       = TTable*;
using PTScanTable   = TScanTable*;
using PTSortTable   = TSortTable*;
using PTArrayTable  = TArrayTable*;
using PTArrayHash   = TArrayHash*;
using PTBalanceNode = TBalanceNode*;
using PTBalanceTree = TBalanceTree*;
using PTHashTable   = THashTable*;
using PTListHash    = TListHash*;
using PTTreeNode    = TTreeNode*;
using PTTreeTable   = TTreeTable*;

#endif
