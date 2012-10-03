#include "variable.hpp"

#include "problem.hpp"


int Variable::j_ = 1;

Variable::Variable(const Problem& pb)
{
    lp_ = pb.pb_;
    colNumber_ = j_++;

    glp_add_cols(lp_, 1);
}

void Variable::set_name(const std::string& name) {
    glp_set_col_name(lp_, colNumber_, name.c_str());
}

void Variable::set_bounds(int type, double lb, double ub) {
    glp_set_col_bnds(lp_, colNumber_, type, lb, ub);
}

void Variable::set_coef(double coef) {
    glp_set_obj_coef(lp_, colNumber_, coef);
}

unsigned
Variable::getColNumber() const
{
    return colNumber_;
}
