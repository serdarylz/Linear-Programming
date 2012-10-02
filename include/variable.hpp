#ifndef _VARIABLE_H_
#define _VARIABLE_H_

#include <glpk.h>
#include <string>

class Variable
{
public:
    Variable(glp_prob *lp);
    ~Variable() = default;
    void set_name(const std::string& name);
    void set_bounds(int type, double lb, double ub);
    void set_coef(double coef);

private:
    glp_prob    *lp_;
    static int  j_;
    std::string name_;
    int         type_;
    double      lb_;
    double      ub_;
};

#endif /* _VARIABLE_H_ */
