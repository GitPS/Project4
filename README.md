#### CS 441 Project 4 ####

__Authors__

Phillip Sime

2013-11-24

__Summary__

This software models main memory performance when performing intensive calculations.  The two types of calculations used in this program are scalur multiplication and matrix multiplication.  This software also incorporates a highly accurate timing mechanism which will output the average time take to perform each calculation in megaFLOPS.

__Build__

To build this software, simply navigate to the directory containing the Makefile and all other included files on a unix-based machine or virtual machine. Type the command `make` into the terminal to trigger the build. This will cause the gcc build commands listed in the Makefile to execute, compiling the source code into an executable file.

__Usage__

To use this software, there are two seperate commeands depending on the which type of calculation you would like to use for modeling.  

The first command is `./scalarmult <N-limit>` where `<N-limit>` is an optional argument for the size of the NxN matrix used for calculations.  N will initially start out at 2 and increase by powers of 2 until `<N-limit>` is reached.  If no second argument is provided the program will default to an N of 1024.

The second command is `./matrixmult <N-limit>` where `<N-limit>` is an optional argument for the size of the NxN matrix used for calculations.  N will initially start out at 2 and increase by powers of 2 until `<N-limit>` is reached.  If no second argument is provided the program will default to an N of 1024.

__Test Cases__

__Examples__

TODO

__Known Bugs and Problem Areas__
* No bugs or problem areas are known at this time.

