#pragma once

#include <vector>
#include <cstdint>
#include <iostream>


class Matrix
{
public:
	Matrix(uint8_t side, const std::vector<int> &data);
	Matrix(uint8_t side, std::vector<int>&& data);

	int GetDeterminant() const;
	Matrix GetMinor(uint8_t row, uint8_t col) const;
	int Get(uint8_t row, uint8_t col) const;
	uint8_t GetSide() const noexcept;

	friend std::ostream& operator << (std::ostream& out, const Matrix& matrix);

private:
	const uint8_t m_side;
	const std::vector<int> m_matrix;

};

std::ostream& operator << (std::ostream& out, const Matrix& matrix);
