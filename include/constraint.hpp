#ifndef _CONSTRAINT_H_
#define _CONSTRAINT_H_

#include <glpk.h>
#include <string>

class Constraint
{
public:
    Constraint(glp_prob *lp);
    ~Constraint() = default;

private:
    static int  i_;
    std::string name_;
    glp_prob    *lp_;
};

#endif /* _CONSTRAINT_H_ */
