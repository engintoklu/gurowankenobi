#include <iostream>
#include <string>
#include "gurowan.hpp"

int main()
{
    GRBEnv env;
    GRBModel model(env);

    // set the model sense (minimization or maximization)
    model.set(GRB_IntAttr_ModelSense, GRB_MINIMIZE);

    // add variables to the model
    //GRBVar varname = model.addVar(lowerBound, upperBound,
    //    coefficientInObjFunc, varType, varnameAsString);
    GRBVar x1 = model.addVar(0, 100, 1, GRB_CONTINUOUS, "x1");
    GRBVar x2 = model.addVar(0, 100, 1, GRB_CONTINUOUS, "x2");
    GRBVar x3 = model.addVar(0, 2, 0, GRB_INTEGER, "x3");

    // actually updating is not necessary in gurowankenobi
    // the following line is for compatibility
    model.update();

    // add the constraint Constr1: 6*x2-3*x1 <= 20-x3
    model.addConstr(6 * x2 - 3 * x1 <= 20 - x3, "Constr1");

    std::cout << "num. of vars: "
              << model.get(GRB_IntAttr_NumVars) << std::endl;

    std::cout << "num. of constrs: "
              << model.get(GRB_IntAttr_NumConstrs) << std::endl;

    std::cout << std::endl;

    // solve the model
    model.optimize();

    // show the results
    std::cout << "REPORTING RESULTS:" << std::endl;

    std::cout << "x1:" << x1.get(GRB_DoubleAttr_X) << std::endl;
    std::cout << "x2:" << x2.get(GRB_DoubleAttr_X) << std::endl;
    std::cout << "x3:" << x3.get(GRB_DoubleAttr_X) << std::endl;
    std::cout << "objective:" << model.get(GRB_DoubleAttr_ObjVal) << std::endl;

    int status;
    status = model.get(GRB_IntAttr_Status);
    std::cout << "status:" << status << std::endl;

    if (status == GRB_OPTIMAL)
    {
        std::cout << "It's optimal!" << std::endl;
    }

    return 0;
}
