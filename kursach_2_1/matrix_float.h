#pragma once
#include "matrix.h"

class matrix_float : public matrix
{
protected:
	float** value;

	virtual void Clear() override;
	std::ostream& print(std::ostream& out) override;
	std::istream& read(std::istream& in) override;

	matrix_float& operator=(const matrix_float& copied);

public:
	void Editing(uint16_t i, uint16_t j) override;
	void SetNewMatrixSize(uint16_t size) override;

	matrix& operator=(const matrix& obj) override;
	matrix& operator/(const matrix& obj) override;

	matrix_float();
	matrix_float(uint16_t size);
	matrix_float(const matrix& copied);
	~matrix_float() override;
};