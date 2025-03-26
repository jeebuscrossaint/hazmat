{
  description = "HAZMAT - A blazingly fast CLI password manager";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
    utils.url = "github:numtide/flake-utils";
  };

  outputs = {
    self,
    nixpkgs,
    utils,
  }:
    utils.lib.eachDefaultSystem (
      system: let
        pkgs = nixpkgs.legacyPackages.${system};
      in {
        packages.default = pkgs.stdenv.mkDerivation {
          pname = "hazmat";
          version = "0.0.9";

          src = ./.;

          nativeBuildInputs = with pkgs; [
            tinycc
            pkg-config
          ];

          buildInputs = with pkgs; [
            openssl
            cjson
          ];

          # Create config.mk with build settings
          preBuild = ''
            cat > config.mk << EOF
            CC = tcc
            CFLAGS = -Wall -Wextra -I${pkgs.openssl.dev}/include -I${pkgs.cjson}/include
            LDFLAGS = -L${pkgs.openssl.out}/lib -L${pkgs.cjson}/lib -lssl -lcrypto -lcjson
            TARGET = hazmat
            OBJECTS = main.o init.o help.o shred.o master.o random.o
            BINDIR = $out/bin
            EOF
          '';

          # Create bin directory
          preInstall = ''
            mkdir -p $out/bin
          '';

          meta = with pkgs.lib; {
            description = "A blazingly fast and tiny CLI password manager written in C99";
            homepage = "https://github.com/jeebuscrossaint/hazmat";
            license = licenses.bsd2;
            platforms = platforms.linux;
            maintainers = with maintainers; ["Amarnath P."];
          };
        };

        devShells.default = pkgs.mkShell {
          buildInputs = with pkgs; [
            tinycc
            pkg-config
            openssl
            cjson
            # Development tools
            gdb
            valgrind
          ];
        };
      }
    );
}
