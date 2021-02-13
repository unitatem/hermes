#include <chrono>
#include <iostream>
#include <thread>

using namespace std::chrono_literals; // ns, us, ms, s, h, etc.

int main()
{
    std::cout << "START" << std::endl;

    while (true)
    {
        for (int i = 0; i < 10; i++)
        {
            std::cout << "." << std::flush;

            std::this_thread::sleep_for(1s);
            // std::this_thread::sleep_until(std::chrono::system_clock::now() + 1s);
        }
        std::cout << std::endl;
    }
}
