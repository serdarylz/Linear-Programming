#ifndef _PROBLEM_H_
#define _PROBLEM_H_

#include <string>
#include <vector>

#include "constraint.hpp"
#include "variable.hpp"


class Problem
{
public:
    friend class Constraint;
    friend class Variable;

    enum Optimization
    {
        MAXIMIZE,
        MINIMIZE
    };

    Problem(const std::string& name);
    ~Problem();

    void setOptimization(const Optimization& flag);
    void setConstraintsValues(const Constraint& c, const Variable& v, double value);

    std::vector<double> solve();

private:
    glp_prob* pb_;
    std::vector<int> rows_;
    std::vector<int> cols_;
    std::vector<double> values_;
};


#endif /* _PROBLEM_H_ */
