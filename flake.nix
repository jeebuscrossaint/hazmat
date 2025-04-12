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
            makeWrapper
          ];

          buildInputs = with pkgs; [
            openssl
            cjson
          ];

          # Create config.mk with build settings
          preBuild = ''
            cat > config.mk << EOF
            CC = tcc
            CFLAGS = -Wall -Wextra -I./include -I${pkgs.openssl.dev}/include -I${pkgs.cjson}/include
            LDFLAGS = -L${pkgs.openssl.out}/lib -L${pkgs.cjson}/lib -lssl -lcrypto -lcjson
            TARGET = hazmat
            SOURCES = \$(wildcard src/*.c)
            OBJECTS = \$(SOURCES:.c=.o)
            BINDIR = $out/bin
            EOF
          '';

          # Create bin directory
          preInstall = ''
            mkdir -p $out/bin
          '';

          # Wrap binary with correct library path
          postInstall = ''
            wrapProgram $out/bin/hazmat \
              --prefix LD_LIBRARY_PATH : ${pkgs.lib.makeLibraryPath [ pkgs.openssl pkgs.cjson ]}
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
