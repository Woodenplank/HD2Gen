#include <string>
#include <cctype>
#include <algorithm>
#include <vector>
#include <list>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "random_ints.hpp"
#include "list_extra.hpp"

//#define strlist std::list<std::string>

struct Warbond{
    Warbond(std::string s, std::list<std::string> pri, std::list<std::string> sec, std::list<std::string> thr):
        searchname(s), primaries(pri), secondaries(sec), throwables(thr) {}
    Warbond() = default;

    friend inline bool operator==(const Warbond&wb, const std::string&s)
    {
        return wb.searchname == s;
    }
    std::string searchname;
    std::list<std::string> primaries={};
    std::list<std::string> secondaries={};
    std::list<std::string> throwables={};
};

const std::vector<Warbond> Warbonds={
    Warbond("standard",
        {"Liberator","Liberator Penetrator","R-63 Dilligence","R-63CS Dilligence Counter-Sniper","Plas-1 Scorcher","LAS-5 Scythe","SG-8 Punisher","SG-8S Punisher Slugger","SG-225 Breaker","SG-225SP Breaker Spray-and-pray","SMG-37 Defender"},
        {"P-2 Peacemaker","P-19 Redeemer"},
        {"G-3 Smoke","G-12 High Explosive","G-6 Frag","G-16 Impact"}),
    Warbond("borderlinejustice",
        {"R-6 Deadeye"},
        {"LAS-58 Talon"},
        {"TED-63 Dynamite"}),
    Warbond("chemicalagents",
        {},
        {"P-11 Stim Pistol"},
        {"G-4 Gas"}),
    Warbond("controlgroup",
        {"VG-70 Variable"},
        {},
        {"G-31 Arc"}),
    Warbond("cuttingedge",
        {"ARC-12 Blitzer","SG-8 Punisher Plasma","LAS-16 Sickle"},
        {"Las-7 Dagger"},
        {"G-23 Stun"}),
    Warbond("democraticdetonation",
        {"BR-14 Adjudicator","Exploding Crossbow","R-36 Eruptor"},
        {"GP-31 Grenade Pistol"},
        {"G-123 Thermite"}),
    Warbond("dustdevils",
        {"AR-2 Coyote"},
        {},
        {"G7-Pineapple"}),
    Warbond("forceoflaw",
        {"AR-32 Pacifier"},
        {"P-92 Warrant"},
        {"G-109 Urchin"}),
    Warbond("freedomsflame",
        {"SG-451 Punisher Cookout","FLAM-66 Torcher"},
        {"P-72 Crisper"},
        {}),
    Warbond("mastersofceremony",
        {"R-2 Amendment"},
        {"CQC-2 Saber"},
        {"G-142 Pyrotech"}),
    Warbond("polarpatriots",
        {"AR-61 Tenderizer","Plas-101 Purifier","SMG-72 Pummeler"},
        {"P-113 Verdict"},
        {"G-13 Incendiary Impact"}),
    Warbond("servantsoffreedom",
        {"LAS-17 Double-Edge Sickle"},
        {"GP-20 Ultimatum","CQC-5 Combat Hatchet"},
        {"G-50 Seeker"}),
    Warbond("steeledveterans",
        {"JAR-5 Dominator","SG-225IE Breaker Incendiary","Liberator Concussive"},
        {"P-4 Senator"},
        {"G-10 Incendiary"}),
    Warbond("truthenforcers",
        {"SMG-32 Reprimand","SG-20 Halt"},
        {"Plas-15 Loyalist"},
        {}),
    Warbond("urbanlegends",
        {},
        {"CQC-30 Stun Baton","CQC-19 Stun Lance"},
        {}),
    Warbond("vipercommandos",
        {"Liberator Carbine"},
        {"SG-22 Bushwhacker"},
        {"K-2 Throwing Knife"}),
    Warbond("supercitizen",
        {"MP-98 Knight"},
        {},
        {}),
    Warbond("killzone",
        {"StA-52 Assault Rifle","StA-11 SMG","PLAS-39 Accelerator Rifle"},
        {},
        {}),
    Warbond("halo",
        {"MA5C Assault Rifle","M90A Shotgun","M7S SMG"},
        {"M6C/SOCOM Pistol"},
        {}),
    Warbond("superstore",
        {},
        {"CQC-5 Combat Hatchet", "CQC-30 Stun Baton", "P-92 Warrant"},
        {})
};
const std::vector<std::string> WarbondsNameList={
    "standard",
    "borderlinejustice",
    "chemicalagents",
    "controlgroup",
    "cuttingedge",
    "democraticdetonation",
    "forceoflaw",
    "freedomsflame",
    "mastersofceremony",
    "polarpatriots",
    "servantsoffreedom",
    "steeledveterans",
    "truthenforcers",
    "urbanlegends",
    "vipercommandos",
    "killzone",
    "halo",
    "supercitizen",
    "superstore"
};

const std::string excludeFileName="HD2_WarbondExclusions.txt";

std::list<std::string> primaries={
        /* ---- Assault rifles ---- */
    "AR-2 Coyote",
    "AR-32 Pacifier",
    "AR-61 Tenderizer",
    "BR-14 Adjudicator",
    "Liberator",
    "Liberator Penetrator",
    "Liberator Concussive",
    "Liberator Carbine",
    "MA5C Assault Rifle",
    "StA-52 Assault Rifle",
    "VG-70 Variable",    

        /* ---- Marksman Rifles ---- */
    "R-2 Amendment",
    "R-63 Dilligence",
    "R-63CS Dilligence Counter-Sniper",
    "R-6 Deadeye",

        /* ---- Submachineguns ---- */
    "M7S SMG",
    "MP-98 Knight",
    "SMG-32 Reprimand",
    "SMG-37 Defender",
    "SMG-72 Pummeler",
    "StA-11 SMG",

        /* ---- Explosive ---- */
    "Eruptor",
    "Exploding Crossbow",

        /* ---- Shotgun ---- */
    "Breaker",
    "Breaker Spray-and-pray",
    "Breaker Incendiary",
    "M90A Shotgun",
    "SG-20 Halt",
    "SG-8 Punisher",
    "SG-8S Punisher Slugger",
    "SG-451 Punisher Cookout",    

        /* ---- Energy based ---- */
    "SG-8 Punisher Plasma",
    "ARC-12 Blitzer",
    "LAS-5 Scythe",
    "LAS-16 Sickle",
    "LAS-17 Double-Edge Sickle",
    "Plas-1 Scorcher",
    "Plas-101 Purifier",
    "PLAS-39 Accelerator Rifle",

        /* ---- Special ---- */
    "JAR-5 Dominator",
    "Scorcher"
};
std::list<std::string> secondaries={
        /* ---- Pistol ---- */
    "M6C/SOCOM Pistol",
    "P-2 Peacemaker",
    "P-19 Redeemer",
    "P-113 Verdict",
    "P-4 Senator",
    "P-92 Warrant",   

        /* ---- Melee ---- */
    "CQC-2 Saber",
    "CQC-5 Combat Hatchet",
    "CQC-30 Stun Baton",
    "CQC-19 Stun Lance",

        /* ---- Special ---- */
    "P-72 Crisper",
    "GP-31 Grenade Pistol",
    "GP-20 Ultimatum",
    "P-11 Stim Pistol",
    "SG-22 Bushwhacker",
    "LAS-58 Talon",
    "Las-7 Dagger",
    "Plas-15 Loyalist"
};
std::list<std::string> throwables={
        /* ---- Special Throwables ---- */
    "G-109 Urchin",
    "G-123 Thermite",
    "G-13 Incendiary Impact",
    "G-142 Pyrotech",
    "G-16 Impact",
    "G-23 Stun",
    "G-3 Smoke",
    "G-4 Gas",
    "G-50 Seeker",
    "K-2 Throwing Knife",
    "G-31 Arc",

            /* ---- Standard Throwables ---- */
    "TED-63 Dynamite",
    "G7-Pineapple",
    "G-12 High Explosive",
    "G-10 Incendiary",
    "G-6 Frag"
};


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

int main(int argc, char **argv)
{
    bool debug = false;   /* Enable for intermediary text reports */

    if (argc == 1) // standard execution. Generates a random loadout from the available equipment set.
    {
        std::vector<std::string> exclusion_list;
        std::ifstream exclusion_file(excludeFileName);
        if (exclusion_file){
            std::string line;
            while(std::getline(exclusion_file,line))
            {
                if (debug) std::cout << "Excluded: " << line << "\n";
                exclusion_list.push_back(line);
            }
            exclusion_file.close();
        }
        else {
            std::cout << "Could not open file " << excludeFileName << "\n"
                    << "Please ensure that a file of that name is in the folder, and is accessible." << std::endl;
            return 1;
        }

        for (Warbond wb : Warbonds) for (std::string s : exclusion_list)  {
                if (wb==s)
                {/*  This is for C++11 standard, 
                     which does not include the remove function in STL */
                    remove(primaries, wb.primaries);
                    remove(secondaries, wb.secondaries);
                    remove(throwables, wb.throwables);
                }
            }
        if (debug) std::cout << "Removed unwanted Warbonds from the random pool" << std::endl;
        
        
        std::cout << "Your loadout shall be: " << loadgen(primaries) << ", " << loadgen(secondaries)
                  << " and " << loadgen(throwables) << "." << std::endl;
        system("pause");
        return 0;
    }


    std::string current_exec_name = argv[0];
    std::vector<std::string> all_args;
    all_args.assign(argv + 1, argv + argc);

    if (argc==2 && (all_args[0]=="--h" or all_args[0]=="--help"))   // cmd list help
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

    else if (argc==2 && (all_args[0]=="--ls" || all_args[0]=="--list"))   // list warbond names
    {
        std::cout << "The program recognizes the following Warbond names/synonyms: " << std::endl;
        for (std::string s : WarbondsNameList)
            std:: cout << s << "\n";
        std::cout << std::flush;
        return 0;
    }

    /* ---- ---- ---- ---- ---- Warbond filtering ---- ---- ---- ---- ---- */
    else
    {
        std::ofstream outfile(excludeFileName, std::ofstream::app);
        std::list<std::string> revalidate;
        for (auto &str : all_args){
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
                std::cout << "Input \"" << str << "\" could not be interpreted as a Warbond exclusion.\n"
                          << "Control spelling, do not use spaces, and make sure to include a '-' before Warbond name!" << std::endl;
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
    }


    return 0;
}