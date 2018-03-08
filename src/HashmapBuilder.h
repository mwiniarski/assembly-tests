//
// Created by Michael Winiarski on 07/03/2018.
//

#ifndef SAMPLEPROJECT_HASHMAPBUILDER_H
#define SAMPLEPROJECT_HASHMAPBUILDER_H

#include <string>
#include <vector>
#include <math.h>
#include <memory>

class HashmapBuilder {
public:
    struct Word {
        Word(uint16_t s, uint16_t i)
            :sequence(s), index(i)
        {}

        uint16_t sequence;
        uint16_t index;
    };

    HashmapBuilder(uint32_t readsCount);

    void buildHashmap(std::vector<std::string>& reads);

private:
    int hash(std::string str);
    uint32_t readsCount_ = 0;
    uint32_t wordsMapSize_ = 0;
    uint32_t wordLength_ = 0;

    std::unique_ptr<std::vector<Word> []> wordsMap_;
};


#endif //SAMPLEPROJECT_HASHMAPBUILDER_H
