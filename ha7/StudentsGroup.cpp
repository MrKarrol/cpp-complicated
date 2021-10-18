#include "StudentsGroup.h"

#include <fstream>
#include <sstream>
#include <numeric>

const std::string filename = "students_group.bin";

bool operator == (const protobuf::FullName& lhv, const protobuf::FullName& rhv)
{
	return std::tie(lhv.first_name(), lhv.second_name(), lhv.third_name()) == std::tie(rhv.first_name(), rhv.second_name(), rhv.third_name());
}

template<typename C, typename T>
std::basic_ostream<C, T>& operator << (std::basic_ostream<C, T>& out, const protobuf::FullName& name)
{
	out << name.first_name() << " " << name.second_name();
	if (name.has_third_name())
		out << " " << name.third_name();
	return out;
}

template<typename C, typename T>
std::basic_ostream<C, T>& operator << (std::basic_ostream<C, T>& out, const protobuf::Student& student)
{
	out << student.name() << ", grades: ";
	std::copy(student.grades().begin(), student.grades().end(), std::ostream_iterator<int32_t>(out, " "));
	if (student.grades().size())
	{
		const auto average = std::accumulate(student.grades().begin(), student.grades().end(), 0.f) / student.grades().size();
		out << ", average: " << average;
	}
	return out;
}

void StudentsGroup::AddStudent(const protobuf::Student& student)
{
	*m_group.add_students() = student;
}

void StudentsGroup::Open()
{
	std::ifstream in(filename, std::ios::binary);
	m_group.ParseFromIstream(&in);
}

void StudentsGroup::Save()
{
	std::ofstream out(filename, std::ios::binary);
	m_group.SerializeToOstream(&out);
}

double StudentsGroup::GetAverageScore(const protobuf::FullName& name)
{
	const auto student_iter = std::find_if(m_group.students().begin(), m_group.students().end(), [name](const auto student) {return student.name() == name; });
	if (student_iter != m_group.students().end())
		return student_iter->average();
	throw std::invalid_argument("no student with that name");
}

std::string StudentsGroup::GetAllInfo(const protobuf::FullName& name)
{
	const auto student_iter = std::find_if(m_group.students().begin(), m_group.students().end(), [name](const auto student) {return student.name() == name; });
	if (student_iter == m_group.students().end())
		throw std::invalid_argument("no student with that name");

	std::stringstream ss;
	ss << *student_iter;
	return ss.str();
}

std::string StudentsGroup::GetAllInfo()
{
	std::stringstream ss;
	for (const auto student : m_group.students())
		ss << student << std::endl;
	return ss.str();
}
