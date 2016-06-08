
# Unit-Tests with Unity and Keil on STM32F429I-DISCO

## Description

This project is an example project on how to configure the IDE Keil uVision
for simple unit-tests with the test framework unity. The project was created
using the initialization code generator STM32CubeMX for a STM32F429I-DISCO
board.

## Project Structure

 - Drivers
 - Inc: include files for peripherals
 - Src: source files for peripherals
 - MDK-ARM: Keil uVision project
 - Test: source files for tests
 - Usr: user's source and include files
 - Lib: external libraries
 - Log: generated log files

## Target 'Test'

The project is setup to have two targets, "Test" and "STM32F429I". The "Test"
target is configured to use the simulator. To run the tests the target needs 
to be built and a debug session needs to be started in Keil. Before any build
a ruby script provided by unity is invoked to generate the test runner for the
unit-tests (Test\my_test_Runner.c).

The path to Ruby needs to be configured correctly in Keil, on my setup it is 
located at D:\Ruby23\bin\ruby.exe.

    "Options for Target 'Test'" -> "User" -> "Before Build/Rebuild" -> "Run #1"
    ruby.exe ..\Lib\unity\auto\generate_test_runner.rb ..\\Test\\my_test.c

The test results can be seen in Keil's "Debug (printf) Viewer). The results are
additionally forwarded to the log file Log\ITM0.log. The log file can be 
configured in MDK-ARM/simulator.ini.

## Target 'STM32F429I'

The target 'STM32F429I' compiles the source code for the target device, which
simply toggles a LED on a button press.

## Create More Tests

For any test case a separate 'Test' target needs to be created, which excludes the
other test cases. Otherwise the linker complains about multiple defined symbols.

This solution is not suited for huge projects but it works fine for smaller
projects. The test cases can be automated using Keil's commandline interface,
see http://www.keil.com/support/man/docs/uv4/uv4_commandline.htm.

## Problems

After test execution in the simulator for target 'Test', the debugger runs into
the HardFault_Handler.


## Further Information

- http://www.throwtheswitch.org/unity
- http://www.keil.com
- http://www.st.com




