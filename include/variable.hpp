#ifndef _VARIABLE_H_
#define _VARIABLE_H_

#include <glpk.h>
#include <string>

class Problem;


class Variable
{
public:
    Variable(const Problem& pb);
    ~Variable() = default;

    void set_name(const std::string& name);
    void set_bounds(int type, double lb, double ub);
    void set_coef(double coef);

    unsigned getColNumber() const;

private:
    glp_prob    *lp_;
    static int  j_;
    unsigned    colNumber_;
};

#endif /* _VARIABLE_H_ */
