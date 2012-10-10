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

void
Problem::setConstraintsValues(const Constraint& c, int col, double value)
{
    rows_.push_back(c.getLineNumber());
    cols_.push_back(col);
    values_.push_back(value);
}

std::vector<int>
Problem::solve()
{
    std::cout << "Rows : " << glp_get_num_rows(pb_) << std::endl;
    std::cout << "Cols : " << glp_get_num_cols(pb_) << std::endl;

    std::vector<int> res;
    unsigned size = glp_get_num_cols(pb_) * glp_get_num_rows(pb_);

    glp_load_matrix(pb_, size, rows_.data(), cols_.data(), values_.data());
    glp_simplex(pb_, nullptr);

    // glp_iocp* param = new glp_iocp;
    // param->gmi_cuts = GLP_ON;
    // param->mir_cuts = GLP_ON;
    // glp_init_iocp(param);
    // glp_intopt(pb_, param);

    std::cout << "z = " << glp_get_obj_val(pb_) << std::endl;

    for (int i = 1; i <= glp_get_num_cols(pb_); ++i) {
        std::cout << glp_get_col_name(pb_, i) << " : " << glp_get_col_prim(pb_, i) << std::endl;

        if (glp_get_col_prim(pb_, i) == 1)
            res.push_back(i);
    }

    return res;
}
