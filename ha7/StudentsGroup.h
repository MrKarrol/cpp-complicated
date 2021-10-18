#pragma once

#include "StudentsGroup.pb.h"


class IRepository {
    virtual void Open() = 0; // �������� �������������� � ����
    virtual void Save() = 0; // �������� ������������ � ����
};

class IMethods {
    virtual double GetAverageScore(const protobuf::FullName& name) = 0;
    virtual std::string GetAllInfo(const protobuf::FullName& name) = 0;
    virtual std::string GetAllInfo() = 0;
};


class StudentsGroup
    : public IRepository
    , public IMethods
{
public:
    void AddStudent(const protobuf::Student &student);
    void Open() override;
    void Save() override;
    double GetAverageScore(const protobuf::FullName& name) override;
    std::string GetAllInfo(const protobuf::FullName& name) override;
    std::string GetAllInfo() override;

private:
    protobuf::StudentsGroup m_group;

};

template<typename C, typename T>
std::basic_ostream<C, T>& operator << (std::basic_ostream<C, T>& out, const protobuf::FullName& name);

template<typename C, typename T>
std::basic_ostream<C, T>& operator << (std::basic_ostream<C, T>& out, const protobuf::Student& student);
