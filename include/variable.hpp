#ifndef _VARIABLE_H_
#define _VARIABLE_H_

#include <glpk.h>
#include <string>

class Variable
{
public:
    Variable(glp_prob *lp);
    ~Variable() = default;

private:
    static int  i_;
    std::string name_;
    glp_prob    *lp_;
};

#endif /* _VARIABLE_H_ */
