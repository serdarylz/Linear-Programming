#ifndef _CONSTRAINT_H_
#define _CONSTRAINT_H_

#include <glpk.h>
#include <string>

class Constraint
{
public:
    Constraint(const std::string& name);
    ~Constraint() = default;

private:
    std::string name_;
};

#endif /* _CONSTRAINT_H_ */
