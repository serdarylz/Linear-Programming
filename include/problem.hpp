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

    Problem(const std::string& name, bool isMIP = false);
    ~Problem();

    void setOptimization(const Optimization& flag);
    void setConstraintsValues(const Constraint& c, const Variable& v, double value);
    void setConstraintsValues(const Constraint& c, int col, double value);

    std::vector<int> solve();

private:
    glp_prob* pb_;
    std::vector<int> rows_;
    std::vector<int> cols_;
    std::vector<double> values_;
    bool isMIP_; // Is the problem a Mixed Integer linear Problem ?
};


#endif /* _PROBLEM_H_ */
