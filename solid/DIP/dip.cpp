#include <iostream>
#include <list>
#include <memory>

using namespace std;

// Abstraction
class Product_repository {
public:
    virtual list<std::string> get_all_product_names() = 0;
    virtual ~Product_repository() = default;
};

// Low-level module
class SQL_Product_repository : public Product_repository {
public:
    list<std::string> get_all_product_names() override {
        return {"Soap", "Toothpaste"};
    }
};

// High-level module, depends on abstraction
class Product_catalog {
    std::shared_ptr<Product_repository> repository;

public:
    // Constructor injection
    Product_catalog(std::shared_ptr<Product_repository> repo)
            : repository(std::move(repo)) {}

    void list_all_products() {
        auto all_product = repository->get_all_product_names();
        for (const auto &obj : all_product) {
            std::cout << obj << " ";
        }
    }
};

int main() {
    auto repo = std::make_shared<SQL_Product_repository>();
    Product_catalog catalog(repo);
    catalog.list_all_products();
}
