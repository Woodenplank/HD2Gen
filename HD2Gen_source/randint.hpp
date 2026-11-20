#ifndef randint_hpp
#define randint_hpp

#include <stdio.h>
#include <stdint.h>
#include <vector>
#include <ctime>
/*
Bob Jenkins small state noncryptographic pseudorandom number generator
from https://burtleburtle.net/bob/rand/talksmall.html
*/
typedef uint32_t  u4;
typedef struct { u4 a; u4 b; u4 c; u4 d;} ranctx;
#define rot(x,k) ((x<<k)|(x>>(32-k)))

static u4 ranval( ranctx *x ) {
  u4 e = x->a - rot(x->b, 27);
  x->a = x->b ^ rot(x->c, 17);
  x->b = x->c + x->d;
  x->c = x->d + e;
  x->d = e + x->a;
  return x->d;
}
static void raninit( ranctx *x, u4 seed ) {
  u4 i;
  x->a = 0xf1ea5eed;
  x->b = x->c = x->d = seed;
  for (i=0; i<20; ++i) {
    (void)ranval(x);
  }
}

inline void random_choice(std::vector<uint32_t> &storage, const uint32_t &returns=1,
    const uint32_t &min=0, const uint32_t &max=10)
{
    // generate a seed from current time and 'warm up' the prng
    ranctx rng;
    // NOTE:    std::time output precision is on the order of seconds
    //          running the program twice in single second will give you identical results
    u4 seed = (std::time(nullptr));
    raninit(&rng, seed);

    unsigned int r;
    for (int i=0; i<returns; ++i)
    {
        u4 r = ranval(&rng) % (max+1);
        storage.push_back(r);
    }
}
#endif