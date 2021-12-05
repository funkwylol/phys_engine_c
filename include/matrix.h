#pragma once
#include <math.h>
#include <cmath>
#include <vector>

class Matrix {
	public:
		std::vector<int> rows;
		int columns; 
};

Matrix createMatrix(int rows, int columns) {
	Matrix m1;
	m1.columns = columns;
	for (int n; n < rows; n++) {
		m1.rows.push_back(0);
	}
	return m1;
}

int matrixSize(Matrix m) {
	int n = m.rows.size() * m.columns;
	return n;
}