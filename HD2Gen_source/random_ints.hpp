#ifndef randomints_hpp
#define randomints_hpp

#include <string>
#include <vector>
#include <random>
#include <ctime>    // for seeding

inline void random_choice(std::vector<unsigned int> &storage, const unsigned int &returns=1,
    const unsigned int &min=0, const unsigned int &max=10)
{
    unsigned int seed = (std::time(nullptr));
    std::default_random_engine rd{seed};    // a seed source for the random number engine
    std::mt19937 gen(rd());                 // mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<unsigned> u(min, max);

    unsigned int r;
    for (int i=0; i<returns; ++i)
    {
        r=u(gen);
        storage.push_back(r);
    }
}
#endif