//
// Created by Michael Winiarski on 07/03/2018.
//

#include "HashmapBuilder.h"

HashmapBuilder::HashmapBuilder(uint32_t readsCount)
    :readsCount_(readsCount)
{}

int HashmapBuilder::hash(std::string str)
{
    unsigned ret = 0, multip = 1;
    for(long i = str.size() - 1; i >= 0; i--)
    {
        char a = str[i];
        ret += multip * (a <= 'C' ? (a == 'A' ? 0 : 1) : (a == 'G' ? 2 : 3));
        multip <<= 0x02;
    }
    return ret;
}

void HashmapBuilder::buildHashmap(std::vector<std::string> &reads)
{
    readsCount_ = (uint32_t) reads.size();
    wordsMapSize_ = (uint32_t) std::pow(4, wordLength_);
    wordsMap_ = std::make_unique<std::vector<Word> []>(wordsMapSize_);

    for(unsigned it = 0; it < readsCount_; it++)
    {
        for(unsigned i = 0; i <= reads[it].length() - wordLength_; ++i)
        {
            wordsMap_[hash(reads[it].substr(i, wordLength_))].emplace_back(it, i);
        }
    }
}
