#include <iostream>
#include <memory>
#include <cstring>

using namespace std;

class String {
public:
    String() = default;

    explicit String(char *const str) {
        std::cout << "Constructor \n";
        m_size = strlen(str) + 1;
        m_data = new char[m_size];
        memcpy(m_data, str, m_size);
    }

    String(String const &rhs) {
        std::cout << "Copy Constructor \n";
        m_size = rhs.m_size;
        m_data = new char[m_size];
        memcpy(m_data, rhs.m_data, m_size);
    }

    String &operator=(String const &rhs) {
        if (this == &rhs) {
            return *this;
        }
        std::cout << "Copy Assignment operator \n";
        m_size = rhs.m_size;
        m_data = new char[m_size];
        memcpy(m_data, rhs.m_data, m_size);
        return *this;
    }

    String(String &&rhs) noexcept {
        std::cout << "Move Constructor \n";
        m_size = rhs.m_size;
        m_data = rhs.m_data;
        rhs.m_data = nullptr;
        rhs.m_size = 0;
    }

    String &operator=(String &&rhs) noexcept {
        std::cout << "Move Assignment \n";
        m_size = rhs.m_size;
        m_data = rhs.m_data;
        rhs.m_data = nullptr;
        rhs.m_size = 0;
        return *this;
    }

    void print_data() {
        std::cout << "contents: " << m_data << std::endl;
    }

    ~String() {
        std::cout << "Destructor \n";
        delete m_data;
    }

private:
    uint64_t m_size;
    char *m_data;

};

class Entity {
public:
    explicit Entity(String const &str) : m_str(str) {
        std::cout << "Entity Copied" << std::endl;
    }

    explicit Entity(String &&str) : m_str(std::move(str)) {
        std::cout << "Entity Moved" << std::endl;
    }

    void print_data() {
        m_str.print_data();
    }

    Entity(Entity const &obj) = delete;

    Entity &operator=(Entity const &obj) = delete;

    Entity(Entity &&obj) = delete;

    Entity &operator=(Entity &&obj) = delete;

private:
    String m_str;
};

int main() {
    //Create and move the object
    auto entity = std::make_shared<Entity>(String((char *) "Pankaj"));
    entity->print_data();
}