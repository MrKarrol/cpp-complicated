#pragma once

#include <iostream>
#include <mutex>
#include <string>
#include <vector>


class Pcout
{
public:
    template<typename T>
    Pcout& operator << (const T& v)
    {
        const std::lock_guard<decltype(m_mutex)> lock(m_mutex);
        std::cout << v;
        return *this;
    }

    Pcout& operator << (std::ostream& (*f)(std::ostream&))
    {
        const std::lock_guard<decltype(m_mutex)> lock(m_mutex);
        std::cout << *f;
        return *this;
    }

private:
	std::mutex m_mutex;

};


void Task1()
{
    Pcout pcout;
    std::atomic_bool is_running{ true };
    std::vector<std::thread> thread_pool;
    for (int i = 0; i < 10; ++i)
        thread_pool.emplace_back([&pcout, &is_running]()
            {
                while (is_running)
                {
                    pcout << "It's me, Mario No" << std::this_thread::get_id() << "!" << std::endl;
                    std::this_thread::sleep_for(std::chrono::milliseconds(2));
                }
            });
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    is_running.store(false);
    for (auto& thread : thread_pool)
        if (thread.joinable())
            thread.join();
    pcout << "Where are you, Mario??" << std::endl;
}