#ifndef PROJECTEULER_READABILITY_H
#define PROJECTEULER_READABILITY_H

#define NUM(...) NUM_(__VA_ARGS__, , , , , , , , , , )
#define NUM_(...) NUM_MSVCHACK((__VA_ARGS__))
#define NUM_MSVCHACK(numlist_) NUM__ numlist_
#define NUM__(a1_, a2_, a3_, a4_, a5_, a6_, a7_, a8_, ...) a1_##a2_##a3_##a4_##a5_##a6_##a7_##a8_

#endif //PROJECTEULER_READABILITY_H
