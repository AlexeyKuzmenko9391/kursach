#pragma once
#include "matrix.h"

class matrix_double : public matrix
{
protected:
	double** value;

	virtual void Clear() override;
	std::ostream& print(std::ostream& out) override;
	std::istream& read(std::istream& in) override;

	matrix_double& operator=(const matrix_double& copied);

public:
	void Editing(uint16_t i, uint16_t j) override;
	void SetNewMatrixSize(uint16_t size) override;

	matrix& operator=(const matrix& obj) override;
	matrix& operator/(const matrix& obj) override;

	matrix_double();
	matrix_double(uint16_t size);
	matrix_double(const matrix& copied);
	~matrix_double() override;
};