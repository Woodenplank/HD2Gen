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

// g++ HD2Gen_source\HD2Randomizer.cpp HD2Gen_source\HD2_lor.cpp HD2Gen_source\HD2_filter.cpp HD2Gen_source\list_extra.cpp -o HD2Randomizer.exe

extern const std::string excludeFileName="HD2_WarbondExclusions.txt";
int main(int argc, char **argv){

    if (argc == 1) // standard execution. Generates a random loadout from the available equipment set.
    {
        Randomize();
        return 0;
    }   

    // additional arguments supplied...
    std::vector<std::string> all_args;
    all_args.assign(argv + 1, argv + argc);

    /* ---- ---- ---- ---- ---- print information ---- ---- ---- ---- ---- */
    if (argc==2 && (all_args[0]=="--h" or all_args[0]=="--help"))
    {
        std::cout << ">Helldivers 2 Loadout Randomizer<"
                << "\n---------------------------------------------"
                << "\nAvailable options are:"
                << "\n\t --help (--h)      ---> Display these messages."
                << "\n\t --list (--ls)     ---> Prints a list of all warbond names"
                << "\n\t -warbondname      ---> Excludes a given warbond from the randomizer options (no spaces!)"
                << "\n\t +warbondname      ---> (re)includes a given warbond from the randomizer options (no spaces!)"
                << "\n\t [No arguments]    ---> Runs the randomizer."
                << std::endl;
    }
    else if (argc==2 && (all_args[0]=="--ls" || all_args[0]=="--list"))
    {
        std::cout << "The program recognizes the following Warbond names/synonyms: " << std::endl;
        for (std::string s : WarbondsNameList)
            std:: cout << s << "\n";
        std::cout << std::flush;
        return 0;
    }

    /* ---- ---- ---- ---- ---- Warbond filtering ---- ---- ---- ---- ---- */
    else
        wbfilter(all_args);


    return 0;
}