# TEST GPIO

A simple project that uses a new gpio library for input and output pin interaction.

main.cpp contains functions that will list all of the available gpio chips and lines for IO interaction purposes.
io_test.cpp implements methods that allow the input and output interaction.

## Table of contents

- [TEST GPIO](#test-gpio)
  - [Table of contents](#table-of-contents)
  - [Requirements](#requirements)
    - [LibGpiod](#libgpiod)
  - [License](#license)

## Requirements

- A C++20 compliant compiler (GCC-13.2, Clang-17, etc.).
- Raspberry Pi 4

### LibGpiod

Use the following command to GPIOD library:

```bash
sudo apt-get install libgpiod-dev
```

## License

Copyright 2021 Arturs Kalnins

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
