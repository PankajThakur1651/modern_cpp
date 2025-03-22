#include <iostream>
#include <mutex>
using namespace std;
#include <fstream>
std::once_flag g_flag;
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
        std::unique_lock<std::mutex> lk(mu_, std::defer_lock);
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

int main()
{
    LogFile log;
    log.shared_print("Main", 1);
}