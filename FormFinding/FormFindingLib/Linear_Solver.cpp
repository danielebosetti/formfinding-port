#pragma warning (disable:4244)

#include "Linear_Solver.h"

#include <cmath> 
#include <iostream> 

namespace LinearSolver {

	bool go_Solve(
		Eigen::VectorXd *Pos_x,
		Eigen::SparseLU<Eigen::SparseMatrix<double> > &solver,
		Eigen::VectorXd *B_x,
		Eigen::VectorXd *delta_x,
		Eigen::SparseMatrix<double> *Aff
		) {
		Eigen::SimplicialLDLT<Eigen::SparseMatrix<double>> sparseSolver(*Aff);
		std::cout << std::endl << "Calling SOLVE ... ";
		*Pos_x = solver.solve(*B_x);
		*delta_x = *Aff**Pos_x - *B_x;
		if (solver.info() != Eigen::Success) {
			// solving failed
			std::cout << std::endl << "Solving FAILED ! ";
			std::cout << "\nPrecision of solution: |Ax-b|= " << delta_x->norm();
			return false;
		}
		else
			std::cout << std::endl << "Solving Success ";
		std::cout << std::endl << "Precision of solution: |Ax-b|=" << delta_x->norm();
		return true;
	}




}