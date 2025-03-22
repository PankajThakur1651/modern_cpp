#include <iostream>
#include <mutex>
#include <fstream>
#include <thread>
std::once_flag g_flag;
using namespace std;
class LogFile
{
    std::mutex mu_;
    std::ofstream file_;
public:
    LogFile() = default;
    void shared_print(std::string id, int value)
    {
        std::call_once(g_flag, [&]()
        {
            file_.open("logs.txt");
        });
        std::unique_lock<std::mutex> lk(mu_);
        file_ << "From " << id << " value " << value << std::endl;
    }

    ~LogFile()
    {
        if (file_)
        {
            file_.close();
        }

    }
};

void function1(LogFile &log)
{
    for (int i = 0 ;i<100;i++)
    {
        log.shared_print("Function1", i);
    }
}
int main()
{
    LogFile log;
    std::thread t1(function1, std::ref(log));
    std::thread t2(function1, std::ref(log));
    log.shared_print("Main", 1);

    t1.join();
    t2.join();
}