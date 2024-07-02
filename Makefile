# SFML_PATH: Path to the SFML library directory.
SFML_PATH := ./SFML/

# LIBS: Libraries to link against during the linking phase.
LIBS := -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

# CPPFLAGS: Compiler flags for C and C++ files.
CPPFLAGS := -I$(SFML_PATH)/include

# LDFLAGS: Additional flags to pass to the linker.
LDFLAGS := -L$(SFML_PATH)/lib

# SRCS: List of source files to compile
SRCS := $(wildcard Source/*.cpp)

# OBJS: List of object files to build from source files.
OBJS := $(patsubst Source/%.cpp, Build/%.o, $(SRCS))

# Path to the icon file
ICON_FILE := Resources/Images/Logo.ico

# Resource file
RESOURCE_FILE := resource.rc

# Object file for the source
RESOURCE_OBJ := resource.o

# Target to build the FlapMind executable.
FlapMind: $(OBJS) $(RESOURCE_OBJ)
	g++ $(LDFLAGS) $(OBJS) $(RESOURCE_OBJ) -o $@ $(LIBS)

# Rule to compile each source file into an object file.
Build/%.o: Source/%.cpp
	g++ -c $(CPPFLAGS) $< -o $@

# Rule to compile resource file to object file
$(RESOURCE_OBJ) : $(RESOURCE_FILE)
	windres $(RESOURCE_FILE) -o $(RESOURCE_OBJ) -O coff

# Target to run the FlapMind executable.
run: FlapMind
	./FlapMind

# Target to clean up object files and the executable.
clean: 
	rm -f Build/*.o FlapMind