#include "constraint.hpp"

int Constraint::i_ = 0;

Constraint::Constraint(glp_prob *lp)
    : lp_(lp)
{
    i_++;
}

void Constraint::set_name(const std::string& name) {
    glp_set_row_name(lp_, i_, name.c_str());
}

void Constraint::set_bounds(int type, double lb, double ub) {
    glp_set_row_bnds(lp_, i_, type, lb, ub);
}
