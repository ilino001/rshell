# Basic Command rshell in C++
<<<<<<< HEAD
=======
##### Collaborators: Tiffany Ceden, Isaac Lino
## A command shell called rshell in C++. 
>>>>>>> ca86d66754e257184db49770dac4c856efb094dc

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

Your subset of the test command should allow the user to run the command using the keyword test
$ test -e test/file/path
Additionally, your rshell should allow the user to use the symbolic version of the command
$ [ -e test/file/path ]
You command should also allow the user to run tests using the following flags


-e checks if the file/directory exists

<<<<<<< HEAD
3. Anything that appears after a # character should be considered a comment. For example, in the command ls ­lR /, you would execute the program /bin/ls passing into it the parameters ­lR and /. But in the command ls # ­lR /, you would execute /bin/ls, but you would not pass any parameters because they appear in the comment section. You should also note that the # may or may not be followed by a space before the comment begins. 
 
Collaborators: Tiffany Cedeno, Isaac Lino, Nathaniel Song

=======
-f checks if the file/directory exists and is a regular file

-d checks if the file/directory exists and is a directory


If a user does not specify a flag, then the -e functionality will be used by default.
You will also add an extra feature that the test command currently does not have. Your test command will print out to the terminal if it evaluated to True or False
If the command test ­e /test/file/path evaluates to True, then print display the following
(True)
   
And likewise, if the above command evaluates to False, then print False in the same manner
(False)

Additionally, your test command should work with the connectors && and || 

$ test -e /test/file/path && echo “path exists”

#### or 

$ [ -e /test/file/path ] && echo “path exists”

This will check if path exists at /test/file/path, and if path does exist will print “path exists”.
When your input requires you to have multiple outputs, simply print the (True) or (False) labels as they are evaluated, so the above command (assuming the path exists) would print

(True)

path exists
>>>>>>> ca86d66754e257184db49770dac4c856efb094dc
