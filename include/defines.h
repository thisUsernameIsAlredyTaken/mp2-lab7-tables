#ifndef __DEFINES_H__
#define __DEFINES_H__

#include <string>

using TKey = std::string;

constexpr int TabHashStep =  1;
constexpr int TabMaxSize  =  500;

constexpr int ListOk    =  0;
constexpr int ListEmpty = -101;
constexpr int ListNoMem = -102;
constexpr int ListNoPos = -103;

constexpr int BalLeft  = -1;
constexpr int BalOk    =  0;
constexpr int BalRight =  1;

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

using PTDatValue    = PTDatValue*;
using PTTabRecord   = PTTabRecord*;
using PTWord        = PTWord*;
using PTRootLink    = PTRootLink*;
using PTDatLink     = PTDatLink*;
using PTDatList     = PTDatList*;
using PTTable       = PTTable*;
using PTScanTable   = PTScanTable*;
using PTSortTable   = PTSortTable*;
using PTArrayTable  = PTArrayTable*;
using PTArrayHash   = PTArrayHash*;
using PTBalanceNode = PTBalanceNode*;
using PTBalanceTree = PTBalanceTree*;
using PTHashTable   = PTHashTable*;
using PTListHash    = PTListHash*;
using PTTreeNode    = PTTreeNode*;
using PTTreeTable   = PTTreeTable*;

#endif
