#pragma once
#include "matrix.h"

class matrix_int : public matrix
{
protected:
	int** value;

	virtual void Clear() override;
	std::ostream& print(std::ostream& out) override;
	std::istream& read(std::istream& in) override;

	matrix_int& operator=(const matrix_int& copied);

public:
	void Editing(uint16_t i, uint16_t j) override;
	void SetNewMatrixSize(uint16_t size) override;

	matrix& operator=(const matrix& obj) override;
	matrix& operator/(const matrix& obj) override;

	matrix_int();
	matrix_int(uint16_t size);
	matrix_int(const matrix& copied);
	~matrix_int() override;
};