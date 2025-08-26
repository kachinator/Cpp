
APPNAME_1 = Execution_scheduling_demo

CC = g++

# settings for windows
# # run g++ -v -E -x c++ -       to "see" the path that need to be added
CC_INCLUDE_1 = C:/cygwin64/lib/gcc/x86_64-pc-cygwin/12/include
INCLUDES_1 = -I$(CC_INCLUDE_1)/c++  -I$(CC_INCLUDE_1)/c++/x86_64-pc-cygwin -I$(CC_INCLUDE_1)/c++/backward -I$(CC_INCLUDE_1) 
CC_INCLUDE_2 = C:/cygwin64/usr
INCLUDES_2 = -I$(CC_INCLUDE_2)/include -I$(CC_INCLUDE_2)/include/w32api 


CFLAGS = -g -std=c++17 -Wall -Wfatal-errors -Wdisabled-optimization -Wpointer-arith -Wredundant-decls -Wno-cast-qua $(INCLUDES_1) $(INCLUDES_2) -march=x86-64

LDFLAGS = 
LIBS = -lpthread

SRCDIR=./src
OBJDIR=./obj

SRC_T1 = $(wildcard $(SRCDIR)/*.cpp)
OBJ_T1 := $(subst $(SRCDIR),$(OBJDIR),$(SRC_T1:.cpp=.o))

########################################################################################################
###############################   Targets beginning here   #############################################
########################################################################################################

all: $(APPNAME_1)
$(APPNAME_1): $(OBJ_T1)
	@echo [link program] $@
	$(CC) -o $@ $(OBJ_T1) $(LDFLAGS) $(LIBS)


# The $@ and $< are called automatic variables. The variable $@ represents the name of the target 
# and $< represents the first prerequisite required to create the output file
$(OBJDIR)/%.o:$(SRCDIR)/%.cpp | $(OBJDIR)
	@echo "[Compile] $@ $<"
	$(CC) $(CFLAGS) -c $< -o $@

# create needed obj directory
$(OBJDIR):
	@mkdir -p $(OBJDIR)
	
clean:
	@echo "[Clean] $(OBJ_T1)"
	rm  $(OBJ_T1)  $(APPNAME_1)

