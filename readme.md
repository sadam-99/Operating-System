# main() function description-
        ## Command line Argument passing.
                    - argu_c: It is the total number of the arguments taken in the command line.
                    - Number of Input files 
                    - files names(including input and output files)
        ## fork() function call.
        ## opening of the files using fopen.
        ## calculating the frequency of every character.
        ## writing the contents for all the files into the the output file.
        ## using the wait function for the termination of all the child processes and for the parent process to finally get executed.
# Names of Input Files-
        f1.txt
        f2.txt 
        f3.txt 
        f4.c 
        f5.txt 
        f6.txt 
        f7.txt 
        f8.yml 
        f9.txt 
        f10.txt 
        f11.c 

# Output File name-
        output.txt


# How to use the code:
        ## Compile:
                gcc os_project.c
        ## Run :
                ./a.out 11 f1.txt f2.txt f3.txt f4.c f5.txt f6.txt f7.txt f8.yml f9.txt f10.txt f11.c output.txt

# Error Checking:
        ## If the Number of arguments are less than 4 
                                - Error Displayed:- Please provide sufficient number of arguments and files
        ## If the number of files(argument) and total number of input files provided in the argument are mismatching.
                                - Error Displayed:- Please provide sufficient number of Input files

# Some Details for Input and Output files for Results are also provided in description.txt
