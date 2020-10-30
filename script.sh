#!/bin/bash
#SBATCH --account=inf503-fall18
#SBATCH --job-name=HW6P1A                               # the name of your job
#SBATCH --output=/scratch/INF503/HW6/HW6P1A.txt         # this is the file your output and errors go to
#SBATCH --time=00:01:00                                 # (max time) 1 min, hmm ya that sounds good 
#SBATCH --workdir=/home/INF503/HW6/                     # your work directory
#SBATCH --mem=1000                                      # (total mem) 1GB of memory hmm, sounds good to me
#SBATCH -c1                                             # 1 cpus, sounds good to me

# load a module for example
module load gcc

# Compile your application here
# make -C /home/INF503/HW6/ clean
# make -C /home/INF503/HW6/

# Run your application, precede the application command with srun
# An example here
./homework6 /scratch/DENV2.fa A
srun date
