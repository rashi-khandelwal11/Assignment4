# Assignment4

Git Commands used -
'git init' : Intialize a new git repository.
'git add' : Stages changes,allowing you to prepare files for the next commit.
'git commit ': Records the staged changes with a message, creating a new snapshot.
'git push ': Uploads your local commits to a remote repository.

Makefile -
Makefile is a script used to automate the build process of a program.

target: Q3.cpp Q4.cpp This line indicates that target depends on the source files 'Q3.cpp' and 'Q4.cpp'.

g++ -c Q3.cpp This line indicates that g++ compiler compiles this source code (Q3.cpp) and convert it into object file. The '-c' flag indicates that we want to compile the source code to an object file without linking it into an executable.

g++ -o main1 Q3.o This time g++ compiler link the previously compiled oopd1.o object file with necessary libraries and create an executable named main. The -o flag specifies the output executable name.

./main1 This line runs the main executable that was just created.

g++ -c Q4.cpp g++ -o main2 Q4.o ./main2 Similarly,these lines do the same process for Q4.cpp.

In summary, this Makefile automates the process of compiling and building two separate programs, main1 and main2, from the corresponding source files Q3.cpp and Q4.cpp. It compiles each source file into an object file, links the object file with necessary libraries, and creates an executable. Finally, it runs the executables main1 and main2. This process is useful for managing larger projects where multiple source files need to be compiled and linked together.
