# First use make to just compile all of the cpp and header files.
# put the makefile in the same directory as header files and cpp files.
# Then run the make command in the same directory to compile and link the object files. 

monsoon$ make

# Then after making the program try to submit a job with SBATCH.
# I used 2 different sbatch files for 2 different jobs.

monsoon$ sbatch HW6P1A.sh
monsoon$ sbatch HW6P1B.sh



#In each script file, this structure is appeared:

# Loading the GCC module
monsoon$ module load gcc

# Executable file is (homework2) after finishing compiling and linking.
# Running the program with four input arguments 1)the Path of the Genome    
# 2)The problem flag which can be {A or B}


monsoon$ ../homework6 /scratch/as3874/DENV2.fa A
monsoon$ ../homework6 /scratch/as3874/DENV2.fa B


monsoon$ srun date


