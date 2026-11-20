#include <string>
#include <cctype>       // cannot remember wtf this is for
#include <algorithm>
#include <vector>
#include <list>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "HD2_lor.hpp"
#include "HD2_filtering.hpp"
#include "HD2_textopt.hpp"

extern const std::string excludeFileName="HD2_WarbondExclusions.txt";
int main(int argc, char **argv){
    if (argc == 1)
    {
        Randomize();
        return 0;
    }   
        

    // additional arguments supplied
    std::vector<std::string> all_args;
    all_args.assign(argv + 1, argv + argc);

    if (argc==2 && (all_args[0]=="--h" or all_args[0]=="--help"))
        return help();
    else if (argc==2 && (all_args[0]=="--ls" || all_args[0]=="--list"))
        return listopts();
    else
        wbfilter(all_args);

    return 0;
}
// build: 
// g++ HD2Gen_source\HD2Randomizer.cpp HD2Gen_source\HD2_lor.cpp HD2Gen_source\HD2_filtering.cpp HD2Gen_source\list_extra.cpp HD2Gen_source\HD2_textopt.cpp -o HD2Randomizer.exe