#include "constraint.hpp"

#include "problem.hpp"
#include <iostream>


int Constraint::i_ = 1;

Constraint::Constraint(const Problem& pb)
{
    lp_ = pb.pb_;
    lineNumber_ = i_++;

    glp_add_rows(lp_, 1);
}

void Constraint::set_name(const std::string& name) {
    glp_set_row_name(lp_, lineNumber_, name.c_str());
}

void Constraint::set_bounds(int type, double lb, double ub) {
    glp_set_row_bnds(lp_, lineNumber_, type, lb, ub);
}

unsigned
Constraint::getLineNumber() const
{
    return lineNumber_;
}
