#pragma once
#include "matrix_int.h"
#include "matrix_float.h"
#include "matrix_double.h"

class Matrix
{	
protected:
	matrix* mat;

public:
	uint16_t GetSize();
	void Clear();
	void SetType(std::string);
	void Editin(uint16_t i, uint16_t j);
	void FileIn(std::string filename);
	void FileOut(std::string filename);

	Matrix& operator=(const Matrix& copied);
	Matrix& operator/(const Matrix& obj);
	friend std::ostream& operator<< (std::ostream& out, Matrix& object);
	friend std::istream& operator>> (std::istream& in, Matrix& object);

	Matrix();
	Matrix(std::string type);
	Matrix(int size, std::string type);
	Matrix(const Matrix& copied);
	~Matrix();

};