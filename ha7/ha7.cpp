#include "StudentsGroup.h"

#include <numeric>


void AddStudents(StudentsGroup& group)
{
	protobuf::Student rachel;
	rachel.mutable_name()->set_first_name("Rachel");
	rachel.mutable_name()->set_second_name("Ashwood");
	rachel.add_grades(5);
	rachel.add_grades(5);
	rachel.add_grades(5);
	rachel.set_average(5.0);
	group.AddStudent(rachel);

	protobuf::Student steve;
	steve.mutable_name()->set_first_name("Steve");
	steve.mutable_name()->set_second_name("Zorak");
	steve.mutable_name()->set_third_name("II");
	steve.add_grades(2);
	steve.add_grades(4);
	steve.add_grades(5);
	const auto average = std::accumulate(steve.grades().begin(), steve.grades().end(), 0.f) / steve.grades().size();
	steve.set_average(average);
	group.AddStudent(steve);
}

void CreateAndSave()
{
	StudentsGroup group;
	AddStudents(group);
	group.Save();
}

void LoadAndPrint()
{
	StudentsGroup group;
	group.Open();
	protobuf::FullName rachel;
	rachel.set_first_name("Rachel");
	rachel.set_second_name("Ashwood");
	protobuf::FullName steve;
	steve.set_first_name("Steve");
	steve.set_second_name("Zorak");
	steve.set_third_name("II");
	std::cout << "AllInfo: " << group.GetAllInfo(rachel) << std::endl;
	std::cout << "Average score of " << steve << " is " << group.GetAverageScore(steve) << std::endl;
	std::cout << "-------- All Info --------" << std::endl;
	std::cout << group.GetAllInfo() << std::endl;
}

int main()
{
	//CreateAndSave();
	LoadAndPrint();

	return 0;
}
