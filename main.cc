#include "cli/cli.hh"

int main(int argc, char* argv[]) {
    password_manager_cli cli;
    cli.run(argc, argv);
    return 0;
}
