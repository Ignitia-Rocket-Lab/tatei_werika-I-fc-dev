# tatei_werika-I-fc-dev

This repository constitutes the firmware for the Tatei Werika I flight computer by Ignitia. This flight computer has the following characteristics and features:

- Something...

## Getting Started


### Prerequisites

This project has been configured and created to work with the following tech stack:

- [VSCode](https://code.visualstudio.com/download)
- [STM32 VS Code Extension](https://marketplace.visualstudio.com/items?itemName=stmicroelectronics.stm32-vscode-extension)
- [STM32CubeMX](https://www.st.com/en/development-tools/stm32cubemx.html)
- [STM32CubeProgrammer](https://www.st.com/en/development-tools/stm32cubeprog.html)
- [CMake](https://cmake.org/)
- [Ninja](https://ninja-build.org/)
- CMSIS Toolchain

The install will also require installation of the CMSIS Toolchain for ARM devices, which provides header files like `core_cm4.h`. We recommend, due to easy of installation, the developer to install CMSIS via installing an IDE that includes these files. We have configured the CMake for it to work with the installation of [Microchip MPLAB](https://www.microchip.com/en-us/tools-resources/develop/mplab-x-ide) with all the required extra packages.

Last but not least, install the following packages:
```bash
sudo apt install ninja-build clang-format gcc-arm-none-eabi
```

> After installation of MSIS Toolchain, update the include at the end of CMakeLists.txt to make sure CMSIS packages are being included correclty, id est, change `X.XX` for your toolchain version the line `set(XC32_VERSION "vX.XX")`.

**Style:**
- [Clang-format VSCode extension](https://marketplace.visualstudio.com/items?itemName=xaver.clang-format)
- [GNU ARM Toolchain](https://developer.arm.com/downloads/-/arm-gnu-toolchain-downloads)


### Installing

A step by step series of examples that tell you how to get a development
environment running

Say what the step will be

    Give the example

And repeat

    until finished

End with an example of getting some data out of the system or using it
for a little demo

## Running the tests

Explain how to run the automated tests for this system

### Sample Tests

Explain what these tests test and why

    Give an example

### Style test

Checks if the best practices and the right coding style has been used.

    Give an example

## Deployment

Add additional notes to deploy this on a live system

## Built With

  - [Contributor Covenant](https://www.contributor-covenant.org/) - Used
    for the Code of Conduct
  - [Creative Commons](https://creativecommons.org/) - Used to choose
    the license

## Contributing

Please read [CONTRIBUTING.md](CONTRIBUTING.md) for details on our code
of conduct, and the process for submitting pull requests to us.

## Versioning

We use [Semantic Versioning](http://semver.org/) for versioning. For the versions
available, see the [tags on this
repository](https://github.com/PurpleBooth/a-good-readme-template/tags).

## Authors

  - **Billie Thompson** - *Provided README Template* -
    [PurpleBooth](https://github.com/PurpleBooth)

See also the list of
[contributors](https://github.com/PurpleBooth/a-good-readme-template/contributors)
who participated in this project.

## License

This project is licensed under the [CC0 1.0 Universal](LICENSE.md)
Creative Commons License - see the [LICENSE.md](LICENSE.md) file for
details

## Acknowledgments

  - Hat tip to anyone whose code is used
  - Inspiration
  - etc