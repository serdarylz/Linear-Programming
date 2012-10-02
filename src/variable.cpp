#include "variable.hpp"

int Variable::i_ = 0;

Variable::Variable(glp_prob *lp)
    : lp_(lp)
{
    i_++;
}
