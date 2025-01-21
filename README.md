# 42_pipex
A repository to track my progress with the pipex project from 42 wolfsburg
Programm takes 4 Arguments:
./pipex "infile" "cmd1" "cmd2" "outfile"
infile is the name of a file which holds content
that content is then sent through the frist command (cmd1)
the output of that is then stored in a pipe and passed to 
command 2 (cmd2)
Now the outpt of that is then stored in a file (outifle)

Compile programm with "make"
Compile bonus version which can take more than two commands as arguments with "make bonus"
If you have one and want the other version I recommend running "make fclean" first.
The two versions dont switch into each other very well.

Remove objkect files with "make clean"
Recompile normal programm with "make re"

Example:
Normal:
./pipex "list of people.txt" "grep good" "grep e" "list of good people with e.txt"
./pipex "unimportant file" "ls -l" "wc -l" "number of files in cd.txt"

Bonus:

./pipex "list of numbers.txt" "grep 1" "grep 2" "grep 3" "grep 4" "special numbers.txt"
->writes all numbers that have a 1, 2, 3 AND 4 into "special numbers.txt"