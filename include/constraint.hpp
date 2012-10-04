#ifndef _CONSTRAINT_H_
#define _CONSTRAINT_H_

#include <glpk.h>
#include <string>

class Problem;

class Constraint
{
public:
    Constraint(const Problem& pb);
    ~Constraint() = default;

    void set_name(const std::string& name);
    void set_bounds(int type, double lb, double ub);

    unsigned getLineNumber() const;

private:
    glp_prob    *lp_;
    static int  i_;
    unsigned    lineNumber_;
};

#endif /* _CONSTRAINT_H_ */
