#include "constraint.hpp"

int Constraint::i_ = 0;

Constraint::Constraint(glp_prob *lp)
    : lp_(lp)
{
    i_++;
}

