# 42_pipex
A repository to track my progress with the pipex project from 42 wolfsburg
Programm takes 4 Arguments:
./pipex "infile" "cmd1" "cmd2" "outfile"
infile is the name of a file which holds content
that content is then sent through the frist command (cmd1)
the output of that is then stored in a pipe and passed to 
command 2 (cmd2)
Now the outpt of that is then stored in a file (outifle)

Example:
./pipex "list of people.txt" "grep good" "grep e" "list of good people with e.txt"
./pipex "unimportant file" "ls -l" "wc -l" "number of files in cd.txt"