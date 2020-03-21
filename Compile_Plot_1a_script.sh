!#/bin/bash

#read -p "Write normal C++ file name, e.g. file.cxx : " cxx
#read -p "Read the object file name : " object

#read -p "Write OpenMP C++ file name, e.g. file.cxx : "  ompcxx
#read -p "Read the object file name : " ompobject
cxx="cmplx_num_1a.cxx"
ompcxx="cmplx_num_1a_omp.cxx"
#To Check existance of normal C++ file and creating object file------------
if [ -e ${cxx} ]
then
    if [ -z ${object} ]
    then
        object=${cxx%.cxx}
        echo "Normal C++ file ${cxx}"
	echo "The name of Objectfile has been created as ${object}"
    else
    
        #objectfile=${object}
        echo "Normal C++ file ${cxx}"
    fi
    echo "Yes the file ${cxx} is exist and ......................."
    
  
else
   echo "The file named as ${cxx} is not exist"
fi;
#-----------------------------------------------------------------------

#To Check existance of OpenMP C++ file and creating object file------------
if [ -e ${ompcxx} ]
then
    if [ -z ${ompobject} ]
    then
        ompobject=${ompcxx%.cxx}
        echo "OpenMP C++ file ${ompcxx}"
	echo "The name of Objectfile has been created as ${ompobject}"
    else
    
        #objectfile=${object}
        echo "Normal C++ file ${ompcxx}"
    fi
    echo "Yes the file ${ompcxx} is exist and ......................."
    
  
else
   echo "The file named as ${ompcxx} is not exist"
fi;
#-----------------------------------------------------------------------------

#Compiling the normal and OpenMP C++ files---------------------------
g++ -o ${object} ${cxx}
./${object}

g++ -fopenmp -o ${ompobject} ${ompcxx}
./${ompobject}























