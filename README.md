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
make release # Does also work with bmake
sudo make install
```

## Usage

will document later

## License

```
BSD 2-Clause License

Copyright (c) 2025, Amarnath P.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
```