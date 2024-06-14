#include <fstream>
#include <functional>
#include <iostream>
#include <optional>
#include <string>
#include <filesystem>

std::optional<bool> give_square_root(int x) {
    if (x != 0) {
        return 3 * 3;
    }
    return std::nullopt;
}

void optional_example() {
    std::optional<int> int_optional = give_square_root(3);
    if (int_optional.has_value()) {
        std::cerr << "Have value " << int_optional.value() << std::endl;
    }

    int_optional = give_square_root(0);
    if (!int_optional.has_value()) {
        std::cerr << "Has no value " << std::endl;
    }
    int_optional.reset();
}

std::optional<std::string> read_files(std::string const &file_name) noexcept {
    std::ifstream file(file_name);
    if (!file.is_open()) {
        return std::nullopt;
    }
    std::string contents((std::istreambuf_iterator<char>(file)),
                         std::istreambuf_iterator<char>());
    return contents;
}

void one_more_example() {
    auto file_path = std::filesystem::current_path();
    std::string const file_name = "example.txt";
    std::string file = file_path.string().append("/").append(file_name);
    std::cout << "file is: " << file << std::endl;
    auto file_contents = read_files(file);
    if (file_contents.has_value()) {
        std::cerr << file_contents.value();
    }
}

int main() {
    optional_example();
    one_more_example();
}
