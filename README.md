# PPINP
Protein Protein Interaction Network Pipeline

PPINP finds new connections between two different species.  
This pipeline executes all programs needed for this process.  
Nucleotide sequence of two species in fasta file format is required for pipeline functionality. Examples of inputs can be found in the input folder of this pipeline as 1.fa and 2.fa.
Other entries in fasta format can be obtained from websites such as: https://www.ncbi.nlm.nih.gov/
Also required for pipeline functionality is the sequence of protein connections and the proteins in the database used. Examples of these entries can be obtained in the input folder of this pipeline as connections.txt and proteins.fa.
This pipeline uses protein connections and proteins from 9 reference species from the String portal available in the input folder as connections.txt and proteins.fa.
Other portals can be used in this pipeline such as Intact and Biogrid. If the user chooses to use another database, the database's connections and proteins file must be renamed to connections.txt and proteins.fa and placed in the input folder of this pipeline.
It is possible to run this pipeline with both BLAST outputs, in which case the execution command must be changed, as will be described below. You will also need 5 files for this command: the two inputs (1.fa and 2.fa), the connections file (connections.txt) and the two BLAST outputs, exemplified in the input folder as s_1_string.out and s_2_string.out .
This pipeline does not have optimizations, so it is not recommended to use large input files. Using large files can develop unexpected errors in the pipeline.


Requirements:
   Install python (sudo apt install python3-pip)
   Install biolib (sudo pip3 install pybiolib)

   All programs were implemented in c++.
   Required to run on Linux.


Use:
   Run ./ppinp.sh Par1 Par2 Par3 Par4 Par5 Par6 Par7

   Par1 must take on the value 1 or 2; 1 for the complete pipeline; 2 to not run BLAST.
   For Pair1=1
      Par2 must assume the name of the first incoming FASTA.
      Par3 must assume the name of the second incoming FASTA.
      Par4 must assume the name of the chosen database protein connections file.
      Par5 should assume the name of the chosen database protein names file.
      Par6 must assume the number of threads chosen

   For Par1=2
      Par2 must assume the name of the first incoming FASTA.
      Par3 must assume the name of the second incoming FASTA.
      Par4 must assume the name of the chosen database protein connections file.
      Par5 must assume the name of the first BLAST output file.
      Par6 should take the name of the second BLAST output file.
      Par7 must assume the number of threads chosen


Examples:
   ./ppinp.sh 1 1.fa 2.fa connections.txt proteins.fa 2
      or
   ./ppinp.sh 2 1.fa 2.fa connections.txt s_1_string.out s_2_string.out 2


Outputs: (all output files are in output folder)
   graph.fa: vertices or proteins found in the graph with their nucleotides.
   score.txt: protein connections found in the graph with its score.
   outputsignalp.txt: SignalP output with the name and location of the proteins found.
   outputtargetp.txt: Output from TargetP with the name and location of the proteins found.
   outputtmhmm.txt: TMHMM output with the name and location of the proteins found.
