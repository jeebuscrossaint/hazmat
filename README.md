# hazmat

*CLI password manager in C11 using tinycc*
____________________________________________________

## put fancy crap for the freakme.md

## Features
basically nothing yet lol

## Installation

We have a few dependencies to install before we can build the project.

First thing is that I am pretty sure this project only compiles using `tinycc` so you will need to install that.

Secondly we also use `openssl` for hashing and encryption so you will need to install that as well.

Thirdly we also need `cJSON` for parsing and writing json files so you will need to install that as well.

Also the program relies internally on the `shred` command to securely delete files so you will need to install that as well. Most UNIX like systems should have this command by default. Anyways this program can't build on Windows so you should be fine. Also I think it can't build on BSD either since of use of Linux specific headers but if someone wants to patch that I would be happy to accept the PR.

Alright once we have the dependencies installed we can build the project.

Should probably mention the program is also on the AUR so you can install it from there as well.

```bash
git clone https://github.com/jeebuscrossaint/hazmat.git
cd hazmat
make release
sudo make install
```

## Usage

will document later

## License

