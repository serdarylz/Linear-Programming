#ifndef _VARIABLE_H_
#define _VARIABLE_H_

#include <glpk.h>
#include <string>

class Variable
{
public:
    Variable(const std::string& name);
    ~Variable() = default;

private:
    std::string name_;
};

#endif /* _VARIABLE_H_ */
