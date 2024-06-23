#include "db.h"
#include <mariadb++/account.hpp>
#include <mariadb++/connection.hpp>

void create_list(const std::string& name) {
    // create a new "master/root" account
    mariadb::account_ref account = mariadb::account::create("localhost", "root", "password");

    // create a new connection
    mariadb::connection_ref connection = mariadb::connection::create(account);

    //create a new table in the database
    connection->execute("CREATE TABLE " + name + " (id INT, password VARCHAR(255));");

    // insert hash into table
    connection->execute("INSERT INTO " + name + " (id, password) VALUES (1, '" + hashed_password + "');");
}

void delete_list() {
    std::cout << "Deleting list... " << std::end;
}
