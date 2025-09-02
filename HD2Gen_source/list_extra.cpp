#include "list_extra.hpp"

std::list<std::string>& remove(std::list<std::string> &list, const std::list<std::string> &values)
{
    for (std::string to_delete : values)
        remove(list, to_delete);
    return list;
}
std::list<std::string>& remove(std::list<std::string> &list, const std::string &value)
{
    std::list<std::string>::iterator first=list.begin();
    std::list<std::string>::iterator end=list.end();
    while(first != end)
    {
        std::list<std::string>::iterator next = first;
        ++next;
        if (*first == value)
            list.erase(first);
        first=next;
    }
    return list;
}