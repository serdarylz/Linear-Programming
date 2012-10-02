#include "variable.hpp"

int Variable::j_ = 0;

Variable::Variable(glp_prob *lp)
    : lp_(lp)
{
    j_++;
}

void Variable::set_name(const std::string& name) {
    glp_set_col_name(lp_, j_, name.c_str());
}

void Variable::set_bounds(int type, double lb, double ub) {
    glp_set_col_bnds(lp_, j_, type, lb, ub);
}

void Variable::set_coef(double coef) {
    glp_set_obj_coef(lp_, j_, coef);
}
