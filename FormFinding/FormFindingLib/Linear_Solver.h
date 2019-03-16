#pragma once

#include "Eigen/Sparse"
#include "Eigen/LU"

namespace LinearSolver {

	bool go_Solve(
		Eigen::VectorXd *Pos_x,
		Eigen::SparseLU<Eigen::SparseMatrix<double> > &solver,
		Eigen::VectorXd *B_x,
		Eigen::VectorXd *delta_x,
		Eigen::SparseMatrix<double> *Aff
		);
}