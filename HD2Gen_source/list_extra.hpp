#ifndef list_extra_hpp
#define list_extra_hpp

#include <list>
#include <string>
std::list<std::string>& remove(std::list<std::string> &, const std::list<std::string> &);
std::list<std::string>& remove(std::list<std::string> &, const std::string &);
#endif