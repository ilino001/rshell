# Basic Command rshell in C++
##### Collaborators: Tiffany Ceden, Isaac Lino, Nathaniel Song
## A command shell called rshell in C++. 

It performs with the following steps:

  1. Print a command prompt (e.g.  $ )
  2. Read in a command on one line. Commands will have the form:
cmd       = executable [ argumentList ] [ connector cmd ]
connector = || or && or ;

where executable is an executable program in the PATH and argumentList is a list of zero or more arguments separated by spaces. The connector is an optional way you can run multiple commands at once. If a command is followed by ;, then the next command is always executed; if a command is followed by &&, then the next command is executed only if the first one succeeds; if a command is followed by ||, then the next command is executed only if the first one fails. 

For example:
     $ ls ­a
     $ echo hello
     $ mkdir test
is equivalent to:
     $ ls ­a; echo hello; mkdir test

There should be no limit to the number of commands that can be chained together using these operators, and your program must be able to handle any combination of operators. For example, you should be able to handle the command:
     $ ls ­a; echo hello && mkdir test || echo world; git status

1. Execute the command. This will require using the syscalls fork, execvp, and waitpid. Previous cs100 students created two video tutorials (a  fun cartoon tutorial  ;   more serious explanation ). You should also refer to the man pages for detailed instructions.

2. You must have a special built­in command of exit which exits your shell.

3. Anything that appears after a # character should be considered a comment. For example, in the command ls ­lR /, you would execute the program /bin/ls passing into it the parameters ­lR and /. But in the command ls # ­lR /, you would execute /bin/ls, but you would not pass any parameters because they appear in the comment section. You should also note that the # may or may not be followed by a space before the comment begins
