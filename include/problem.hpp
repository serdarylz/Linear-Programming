#ifndef _PROBLEM_H_
#define _PROBLEM_H_

#include <string>
#include <vector>

#include "constraint.hpp"
#include "variable.hpp"


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

    void addConstraints(const Constraint& c);
    void addVariables(const Variable& v);

private:
    glp_prob* pb_;
    std::vector<Constraint> constraints_;
    std::vector<Variable> variables_;
};


#endif /* _PROBLEM_H_ */
