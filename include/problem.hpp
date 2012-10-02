#ifndef _PROBLEM_H_
#define _PROBLEM_H_

#include <string>


class Problem
{
public:
    Problem(const std::string& name);
    ~Problem();

private:
    std::string name_;
};


#endif /* _PROBLEM_H_ */
