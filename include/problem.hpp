#ifndef _PROBLEM_H_
#define _PROBLEM_H_

#include <string>

#include "glpk.h"


enum Optimization
{
    MAXIMIZE,
    MINIMIZE
};

class Problem
{
public:
    Problem(const std::string& name);
    ~Problem();

    void setOptimization(const Optimization& flag);

    void addConstraints(unsigned n);
    void addVariables(unsigned n);

private:
    glp_prob* pb_;
};


#endif /* _PROBLEM_H_ */
