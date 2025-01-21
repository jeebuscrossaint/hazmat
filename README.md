<div align="center">

# 🔐 HAZMAT

<img src="https://raw.githubusercontent.com/jeebuscrossaint/hazmat/master/hazmat-banner.svg" alt="HAZMAT Banner" width="600"/>

[![License](https://img.shields.io/badge/license-BSD--2--Clause-blue.svg)](LICENSE)
[![Built with TCC](https://img.shields.io/badge/built%20with-TinyCC-orange.svg)](https://bellard.org/tcc/)
[![Platform](https://img.shields.io/badge/platform-Linux-lightgrey.svg)]()
[![Language](https://img.shields.io/badge/language-C99-green.svg)]()

*A blazingly fast and tiny CLI password manager written in C99 using TinyCC*

[Installation](#installation) • [Features](#features) • [Usage](#usage) • [Contributing](#contributing)

</div>

---

## ✨ Features

- 🔒 Secure password storage using OpenSSL encryption
- 🗑️ Secure data shredding with military-grade wiping
- 📦 JSON-based data storage
- 🚀 Blazingly fast and lightweight (< 200KB binary)
- 🐧 Native Linux support
- 🔑 Master password protection

## 🚀 Installation

### Prerequisites

- `tinycc` - The Tiny C Compiler
- `openssl` - Cryptography and SSL/TLS Toolkit
- `cjson` - Lightweight JSON parser
- `coreutils` - For the `shred` command (included in most Unix systems)

### Building from Source

```bash
git clone https://github.com/jeebuscrossaint/hazmat.git
cd hazmat
make release  # Also works with bmake
sudo make install
```

## AUR Package
```bash
yay/paru -S hazmat # or your preferred AUR helper
```

## 🔧 Usage
```hazmat [OPTIONS]```

## Options
- `help` - Display help message
- `init` - Initialize password store
- `shred` - Securely delete all data
- `add` - Add a new entry
- `delete` - Delete an entry
- `show` - Display entry information
- `import` - Import data from file
- `export` - Export data to file

## 🤝 Contributin
Contributions are welcome! Feel free to submit a PR. 
Do adhere to the `CONTRIBUTING.md` guidelines along with the code abiding by our `BSD-2-Clause` license.

## 📜 License
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

<div align="center"> Made with ❤️ by <a href="https://github.com/jeebuscrossaint">Amarnath P.</a> </div>