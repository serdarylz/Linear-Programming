#include "problem.hpp"

#include <iostream>


Problem::Problem(const std::string& name)
{
    pb_ = glp_create_prob();
    glp_set_prob_name(pb_, name.c_str());

    rows_.push_back(0);
    cols_.push_back(0);
    values_.push_back(0.0);
}

Problem::~Problem()
{
    glp_delete_prob(pb_);
}

void
Problem::setOptimization(const Optimization& flag)
{
    if (flag == MAXIMIZE)
        glp_set_obj_dir(pb_, GLP_MAX);
    else if (flag == MINIMIZE)
        glp_set_obj_dir(pb_, GLP_MIN);
}

void
Problem::setConstraintsValues(const Constraint& c, const Variable& v, double value)
{
    rows_.push_back(c.getLineNumber());
    cols_.push_back(v.getColNumber());
    values_.push_back(value);
}

std::vector<double>
Problem::solve()
{
    glp_load_matrix(pb_, values_.size() - 1, rows_.data(), cols_.data(), values_.data());
    glp_simplex(pb_, nullptr);

    std::vector<double> res;

    res.push_back(glp_get_obj_val(pb_));

    for (int col = 1; col <= glp_get_num_cols(pb_); ++col)
        res.push_back(glp_get_col_prim(pb_, col));

    std::cout << "z = " << glp_get_obj_val(pb_) << std::endl;
    std::cout << "x1 = " << glp_get_col_prim(pb_, 1) << std::endl;
    std::cout << "x2 = " << glp_get_col_prim(pb_, 2) << std::endl;
    std::cout << "x3 = " << glp_get_col_prim(pb_, 3) << std::endl;

    return res;
}
