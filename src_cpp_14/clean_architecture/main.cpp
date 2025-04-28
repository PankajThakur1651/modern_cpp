#include <iostream>
#include <memory>
#include <string>


// interfaces (IDataBase)
class IDataBase {
public:
    virtual void create_table(std::string const &table_name) = 0;

    virtual void delete_table(std::string const &table_name) = 0;

    virtual ~IDataBase() = default;
};


//Infrastructure = your SQLDataBase class
class SQLDataBase : public IDataBase {
public:
    void create_table(std::string const &table_name) override {
        std::cout << "Creating table: " << table_name << std::endl;
    }

    void delete_table(std::string const &table_name) override {
        std::cout << "Deleting table: " << table_name << std::endl;
    }
};

// Business Logic = your DB_operation
//Dependency Rule = your DB_operation depends only on an interface, not a concrete SQL class.
class DB_operation {
public:
    explicit DB_operation(IDataBase& db_operation)
            : db_operation_{db_operation} {
        std::cout << "DB_operation" << std::endl;
    }

    void create_table(std::string const &obj) {
        db_operation_.create_table(obj);
    }

    void delete_table(std::string const &obj) {
        db_operation_.delete_table(obj);
    }

private:
    IDataBase& db_operation_;
};

int main() {
    SQLDataBase sql_db;
    DB_operation db_op(sql_db);

    db_op.create_table("First");
    db_op.delete_table("First");
}
