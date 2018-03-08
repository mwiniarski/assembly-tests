//
// Created by Michael Winiarski on 07/03/2018.
//

#include <fstream>
#include <iostream>
#include "FileLoader.h"

void FileLoader::loadFastaReads()
{
    std::ifstream in(readsPath_);
    const unsigned maxLength = 26;
    if(!in.is_open())
    {
        std::cout << "Can't open file " + readsPath_ << std::endl;
        exit(0);
    }

    int tab[maxLength] = {0};
    std::string buffer;
    while(getline(in, buffer)) {
        if(buffer[0] == '>' || buffer.size() >= 1000 * maxLength)
            continue;

        reads_.push_back(buffer);
        tab[buffer.size() / 1000]++;
    }

    for(unsigned i=0; i < maxLength; i++)
    {
        std::cout << i * 1000 << "-" << i * 1000 + 999;
        std::cout << ": " << tab[i] << std::endl;
    }

    std::cout << "Reads count: " << reads_.size() << std::endl;
    in.close();
}