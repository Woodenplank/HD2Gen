#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "random_ints.hpp"
#include "HD2_wb.hpp"
#include "HD2_content.hpp"
#include "HD2_lor.hpp"

std::list<std::string> BuildOptions(std::vector<Warbond> bonds, std::vector<std::string> &exclusion_list, std::string which)
{
    std::list<std::string> out;
    for (Warbond wb : bonds) for (std::string s : exclusion_list)  {
        if (!(wb==s))
        {
            if (which=="p" or which=="primaries")
                for (std::string s : wb.primaries)
                    out.push_back(s);
            else if (which=="s" or which=="secondaries")
                for (std::string s : wb.secondaries)
                    out.push_back(s);
            else if (which=="t" or which=="throwables")
                for (std::string s : wb.throwables)
                    out.push_back(s);
            else if (which=="p" or which=="supports")
                for (std::string s : wb.supports)
                    out.push_back(s);
        }
        // else skip this warbond
    }
    return out;
}

std::string loadgen(const std::list<std::string> &listing)
{
    std::string output;
    std::vector<unsigned int> rand_ints;
    random_choice(rand_ints, 1, 0, listing.size());
    
    auto it = listing.cbegin();
    std::advance(it, rand_ints[0]);
    output = *it;

    return output;
}

int Randomize(){
    // build list of Warbonds to exclude, if the user doesn't want them in the randomizer
    std::vector<std::string> exclude;
    std::ifstream exclusion_file(excludeFileName);
    if (exclusion_file){
        std::string line;
        while(std::getline(exclusion_file,line))
            exclude.push_back(line);
        exclusion_file.close();
    }
    else {
        std::cout << "Could not open file " << excludeFileName << "\n"
                << "Please ensure that a file of that name is in the folder, and is accessible." << std::endl;
        return 1;
    }

    // build available options for each slot
    std::list<std::string> primaries = BuildOptions(Warbonds, exclude, "p");
    std::list<std::string> secondaries = BuildOptions(Warbonds, exclude, "s");
    std::list<std::string> throwables = BuildOptions(Warbonds, exclude, "t");
    std::list<std::string> supports = BuildOptions(Warbonds, exclude, "supports");

    char r='r';
    while (r != 'a')
    {
        std::cout << "Your loadout shall be: " << loadgen(primaries) << ", " << loadgen(secondaries)
                << " with " << loadgen(throwables) << " and " << loadgen(supports) << ".\n"
                << "[R]eroll / [A]ccept " << std::flush;
        std::cin >> r;
    }
    return 0;
}