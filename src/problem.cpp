#include "problem.hpp"


Problem::Problem(const std::string& name)
{
    pb_ = glp_create_prob();
    glp_set_prob_name(pb_, name.c_str());
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
