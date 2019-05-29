#include "tword.h"

TWord::TWord(const std::string &w)
  : word(w) {}


std::string TWord::GetWord() {
    return word;
}

void TWord::SetWord(const std::string &w) {
    word = w;
}

bool TWord::operator==(const TWord &w) {
    return w.word == word;
}