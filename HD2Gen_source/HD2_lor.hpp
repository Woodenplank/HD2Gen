#ifndef HD2_lor_hpp
#define HD2_lor_hpp
#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "random_ints.hpp"
#include "HD2_wb.hpp"
#include "HD2_content.hpp"

extern const std::vector<std::string> WarbondsNameList;
extern const std::vector<Warbond> Warbonds;
extern const std::string excludeFileName;

std::list<std::string> BuildOptions(std::vector<Warbond>, std::vector<std::string>&, std::string);
std::string loadgen(const std::list<std::string> &);
int Randomize();

#endif