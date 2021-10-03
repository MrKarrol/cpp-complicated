#include "matrix.h"

#include <cmath>
#include <stdexcept>
#include <algorithm>
#include <string>
#include <iomanip>


Matrix::Matrix(uint8_t side, const std::vector<int>& data)
	: m_side(side)
	, m_matrix(data)
{
	if (m_side < 2 || m_matrix.size() != m_side * m_side)
		throw std::invalid_argument("matrix is not square");
}

Matrix::Matrix(uint8_t side, std::vector<int>&& data)
	: m_side(side)
	, m_matrix(std::move(data))
{
	if (m_side < 2 || m_matrix.size() != m_side * m_side)
		throw std::invalid_argument("matrix is not square");
}

int Matrix::Get(uint8_t row, uint8_t col) const
{
	if (row >= m_side || col >= m_side)
		throw std::invalid_argument("matrix coords are invalid");

	return m_matrix.at(static_cast<uint32_t>(row) * m_side + col);
}

uint8_t Matrix::GetSide() const noexcept
{
	return m_side;
}

int Matrix::GetDeterminant() const
{
	if (m_side == 2)
		return Get(0, 0) * Get(1, 1) - Get(0, 1) * Get(1, 0);

	int determinant = 0;
	for (int col = 0; col < m_side; ++col)
	{
		const int base = Get(0, col) * (col % 2 == 0 ? 1 : -1);
		determinant += base * GetMinor(0, col).GetDeterminant();
	}
	return determinant;
}

Matrix Matrix::GetMinor(uint8_t x, uint8_t y) const
{
	if (x >= m_side || y >= m_side)
		throw std::invalid_argument("matrix coords are invalid");

	std::vector<int> minor;
	const auto minor_side = m_side - 1;
	minor.reserve(static_cast<uint32_t>(minor_side) * (minor_side));

	for (int row = 0; row < m_side; ++row)
		for (int col = 0; col < m_side; ++col)
		{
			if (row == x || col == y)
				continue;
			minor.emplace_back(Get(row, col));
		}

	return Matrix(minor_side, std::move(minor));
}

std::ostream& operator << (std::ostream& out, const Matrix& matrix)
{
	const auto max = *std::max_element(std::begin(matrix.m_matrix), std::end(matrix.m_matrix));
	const auto ch_width = std::to_string(max).size() + 2;
	out << std::endl;
	for (int row = 0; row < matrix.GetSide(); ++row)
	{
		for (int col = 0; col < matrix.GetSide(); ++col)
		{
			out << std::setw(ch_width) << std::setfill(' ') << matrix.Get(row, col);
		}
		out << std::endl;
	}
	return out;
}
