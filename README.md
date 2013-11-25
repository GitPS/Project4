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

__Graphs__

__Questions and Answers__

_Scalar Multiplication_

Which experiment produces the best overall performance?

* The best overall performing experiment was when we had the `i` value in our outer loop and the `j` value in our inner loop.  This would be the `run_experiment_ij()` function.

Describe the cause of the divergence of performance between the experiments.

*  The reason there is a difference in the divergence between the two expirments is based on how memory is managed by the system.  The divergence in the graph is caused by the values needed not being stored in a quick access part of memory.

_Matrix Multiplication_

Which experiment(s) produces the best overall performance?  Why?

* The best overall performing experiments would be the `kji` and `jki` functions.  Initially they take ~300 megaFLOPS to execute, but as the matrix size increases the runtime actually decreases.  This is caused by the values being stored in memory which allows a faster lookup time. 

Rank the six experiments from best to worst in terms of MFLOPS.

* Matrix Multiplication `ijk`
* Matrix Multiplication `jki`
* Matrix Multiplication `kji`
* Matrix Multiplication `kij`
* Matrix Multiplication `jik`
* Matrix Multiplication `ikj`

Describe the cause of the divergence of performance between the experiments.

* There is a relatively equal divergence pattern for all of the experiments except for `ijk`.  The cause of the divergence is caused by main memory not having quick access to the value needed for the next calculation.  `ijk` starts out much better than the rest because it, initially, has quick reference to the values needed for the calculations as they are the first values of the matrix as it resides in memory. 

You may notice that some of the experiments pair up.  Why does that happen?

*  The majority of the graphs initialy start out at around the same MFLOPS.  The only exception to this would be the `ijk` experiment.  This graph starts at a much lower MFLOPS because the neede values are stored in location of memory that does not require an extensive lookup.  The other graphs follow similiar paths as eachother as they load/access values into memory. 



