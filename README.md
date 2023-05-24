# simple_shell
this program mimics the behavieur of the Thompson shell
## Learning Objectives
- how does the shell works
- how to work with pid and ppid
- how to manipulate the env varaibles
- how to create processes.
- how to use the three prototypes of main
- how does the shell uses the path
- how to use execve
- what and how to use EOF / "end-of-file"
## Output
will work the same way as the sh in interactive and non-interactive mode

example of sh:
`echo "alx" | /bin/sh
/bin/sh: 1: alx: not found
# in interactive mode 
$ slx
./hsh: 1: slx: not found`
same error with our shell hsh:
`echo "alx" | ./hsh
./hsh: 1: alx: not found
# in interactive mode 
$ slx
sh: 1: slx: not found`
