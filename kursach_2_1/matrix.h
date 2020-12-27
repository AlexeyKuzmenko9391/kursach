#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <typeinfo>

class matrix
{
	friend class Matrix;
protected:
	uint16_t size;

	virtual void Clear();
	virtual std::ostream& print(std::ostream& out);
	virtual std::istream& read(std::istream& in);

public:
	uint16_t GetSize();
	virtual void Editing(uint16_t i, uint16_t j);
	virtual void SetNewMatrixSize(uint16_t size);
	void foutMatrix(std::string fileName);
	void finMatrix(std::string fileName);


	virtual matrix& operator=(const matrix& copied);
	virtual matrix& operator/(const matrix& obj);
	friend std::ostream& operator<< (std::ostream& out, matrix& object);
	friend std::istream& operator>> (std::istream& in, matrix& object);

	matrix();
	matrix(uint16_t size);
	matrix(const matrix& copied);
	virtual ~matrix();
};

