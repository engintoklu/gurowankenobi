#include <iostream>
#include <string>
#include "gurowan.hpp"

int main()
{
    GRBEnv env;
    GRBModel model(env);

    model.set(GRB_IntAttr_ModelSense, GRB_MINIMIZE);

    GRBVar x1 = model.addVar(0, 100, 1, GRB_CONTINUOUS, "x1");
    GRBVar x2 = model.addVar(0, 100, 1, GRB_CONTINUOUS, "x2");
    GRBVar x3 = model.addVar(0, 2, 0, GRB_INTEGER, "x3");

    model.update();

    model.addConstr(6 * x2 - 3 * x1 <= 20 - x3, "Constr1");
    model.addConstr(x1 >= 5, "Constr2");
    model.addConstr(x1 <= 3, "Constr3");

    std::cout << "#vars: " << model.get(GRB_IntAttr_NumVars) << std::endl;
    std::cout << "#constrs: " << model.get(GRB_IntAttr_NumConstrs) << std::endl;

    std::cout << std::endl;

    //std::cout << model.toStringGMPL() << std::endl;

    model.optimize();

    std::cout << "REPORTING RESULTS:" << std::endl;

    std::cout << "x1:" << x1.get(GRB_DoubleAttr_X) << std::endl;
    std::cout << "x2:" << x2.get(GRB_DoubleAttr_X) << std::endl;
    std::cout << "x3:" << x3.get(GRB_DoubleAttr_X) << std::endl;
    std::cout << "objective:" << model.get(GRB_DoubleAttr_ObjVal) << std::endl;
    std::cout << "status:" << model.get(GRB_IntAttr_Status) << std::endl;

    return 0;
}
