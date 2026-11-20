#include "HD2_textopt.hpp"
int help()
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
    return 0;
}

int listopts()
{
    std::cout << "The program recognizes the following Warbond names/synonyms: " << std::endl;
    for (std::string s : WarbondsNameList)
        std:: cout << s << "\n";
    std::cout << std::flush;
    return 0;
}
