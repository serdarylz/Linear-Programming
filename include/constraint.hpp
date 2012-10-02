#ifndef _CONSTRAINT_H_
#define _CONSTRAINT_H_

#include <glpk.h>
#include <string>

class Constraint
{
public:
    Constraint(glp_prob *lp);
    ~Constraint() = default;
    void set_name(const std::string& name);
    void set_bounds(int type, double lb, double ub);

private:
    glp_prob    *lp_;
    static int  i_;
};

#endif /* _CONSTRAINT_H_ */
