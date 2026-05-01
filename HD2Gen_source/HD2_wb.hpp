#ifndef HD2_wb_hpp
#define HD2_wb_hpp
#include <list>
#include <string>

struct Warbond{
    Warbond(std::string s, std::list<std::string> pri, std::list<std::string> sec, std::list<std::string> thr, std::list<std::string> sup):
        searchname(s), primaries(pri), secondaries(sec), throwables(thr), supports (sup){}
    Warbond() = default;

    friend inline bool operator==(const Warbond&wb, const std::string&s)
    {
        return wb.searchname == s;
    }
    std::string searchname;
    std::list<std::string> primaries={};
    std::list<std::string> secondaries={};
    std::list<std::string> throwables={};
    std::list<std::string> supports={};
};

#endif