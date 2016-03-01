![image](https://raw.githubusercontent.com/chenshuiluke/fill/master/fill.png)

fill is a C program that generates files of a theoretically unlimited size using the GNU MultiPrecision Arithmetic Library
#Building

##Requirements

1. make

2. the GNU Multiprecision Arithmetic Library (arch linux: `gmp` Ubuntu: `libgmp-dev` Windows: Install and configure it in MinGW)

##Procedure

1. Just run `make` after you clone the repository.

2. `cd bin`

3. Run the program

    [luke@luke-server bin]$ ./fill
    Please enter the name of the file you want to create.
    test
    test
    Please enter the size of the file in bytes.
    400000

4. Check the size

    [luke@luke-server bin]$ ls -l
    total 488
    -rwxr-xr-x 1 luke users  12228 Feb 29 22:50 fill
    -rwxr-xr-x 1 luke users  78054 Feb 29 22:44 fill.exe
    -rwxr-xr-x 1 luke users   1895 Feb 29 22:44 gmon.out
    -rw-r--r-- 1 luke users 400000 Feb 29 22:52 test



