#include "HD2_filtering.hpp"

std::ofstream outfile(excludeFileName, std::ofstream::app);
std::list<std::string> revalidate;
int wbfilter(std::vector<std::string> args){
    for (auto &str : args){
        std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c){ return std::tolower(c); });
        
        bool match_any=false;
        for (auto &comp : WarbondsNameList) 
        {
            bool match = std::equal(str.cbegin()+1, str.cend(), comp.cbegin());
            if (match)
            {   
                match_any = true;
                if (str[0]=='+')
                    revalidate.push_back(comp);
                if (str[0]=='-')
                    if (outfile)    outfile << comp << "\n";
            }
        }
        if (!match_any)
        {
            std::cout << "Input \"" << str << "\" could not be interpreted as a Warbond exclusion.\n"
                        << "Control spelling, do not use spaces, and make sure to include a '-' before Warbond name!" << std::endl;
            return 1;
        }
    }
    if (outfile.is_open())
        outfile.close();

    //revalidation
    std::list<std::string> list_to_print;
    std::ifstream exclusion_file(excludeFileName);
    if (exclusion_file){
        std::string line;
        while(std::getline(exclusion_file,line))
            list_to_print.push_back(line);
        exclusion_file.close();
    }
    remove(list_to_print,revalidate);

    std::ofstream truncatefile(excludeFileName);
    for (std::string s : list_to_print)
        truncatefile << s << '\n';

    if (truncatefile.is_open())
        truncatefile.close();
    return 0;
}