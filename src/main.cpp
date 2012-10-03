#include <glpk.h>
#include <stdio.h>

#include "problem.hpp"


int main()
{
    Problem pb("pb");

    pb.setOptimization(Problem::MAXIMIZE);

    Constraint p(pb);
    Constraint q(pb);
    Constraint r(pb);

    p.set_name("p");
    p.set_bounds(GLP_UP, 0.0, 100.0);

    q.set_name("q");
    q.set_bounds(GLP_UP, 0.0, 600.0);

    r.set_name("r");
    r.set_bounds(GLP_UP, 0.0, 300.0);

    Variable x(pb);
    Variable y(pb);
    Variable z1(pb);

    x.set_name("x1");
    x.set_bounds(GLP_LO, 0.0, 0.0);
    x.set_coef(10.0);

    y.set_name("x2");
    y.set_bounds(GLP_LO, 0.0, 0.0);
    y.set_coef(6.0);

    z1.set_name("x3");
    z1.set_bounds(GLP_LO, 0.0, 0.0);
    z1.set_coef(4.0);

    pb.setConstraintsValues(p, x, 1.0);
    pb.setConstraintsValues(p, y, 1.0);
    pb.setConstraintsValues(p, z1, 1.0);
    pb.setConstraintsValues(q, x, 10.0);
    pb.setConstraintsValues(r, x, 2.0);
    pb.setConstraintsValues(q, y, 4.0);
    pb.setConstraintsValues(r, y, 2.0);
    pb.setConstraintsValues(q, z1, 5.0);
    pb.setConstraintsValues(r, z1, 6.0);

    pb.solve();

    return 0;
}
