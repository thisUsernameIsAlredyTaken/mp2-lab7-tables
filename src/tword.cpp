#include "tword.h"

PTDatValue TWord::GetCopy() {
    return new TWord(word);
}
