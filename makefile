
## SETTINGS ##
CXX = g++
CXXFLAGS = -std=c++0x 
CXXFLAGS += -Wall 
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
#CXXFLAGS += -O3
#LDFLAGS = 


## FILES - change these as needed ##

# Default files - likely correct
OBJS = main.o utility.o 
HEADERS = utility.hpp 

# Project specific - Change as needed
OBJS +=	simulation.o critter.o
HEADERS += simulation.hpp critter.hpp 

# Output name
OUTPUT = EXECUTE 


## PROCEDURES - all automated based on FILES ##
# Linking Objects
${OUTPUT}: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o $@ 

# Creating Objects
%.o: %.cpp
	${CXX} ${CXXFLAGS} -c $<

# CleanUp (ignores errors)
clean:
	rm -f ${OBJS} ${OUTPUT}
