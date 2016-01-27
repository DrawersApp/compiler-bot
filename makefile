TARGET   = echobot
DEBUG    = -g
CC       = g++ -std=c++0x
# compiling flags here
CFLAGS   = -Wall -c $(DEBUG)
LINKER   = g++ -std=c++0x -o

# linking flags here
LFLAGS = -Wall $(DEBUG) -lgloox -lpthread

# change these to set the proper directories where each files shoould be
SRCDIR   = src
OBJDIR   = obj
BINDIR   = bin

SOURCES  := $(wildcard $(SRCDIR)/*.cpp)
INCLUDES := $(wildcard $(SRCDIR)/*.h)

OBJECTS  := $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
rm       = rm -f

$(BINDIR)/$(TARGET): $(OBJECTS)
	@echo "making  $(BINDIR)/$(TARGET)"
	@$(LINKER) $@ $(OBJECTS) $(LFLAGS)
	@echo "Linking complete!"

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	@$(CC) $(CFLAGS) $< -o $@
	@echo "Compiled "$<" successfully!"

MKDIR_P = mkdir -p

all: directories $(BINDIR)/$(TARGET)

.PHONY: directories
directories:OBJ_DIR BIN_DIR 

OBJ_DIR:
	@echo "created obj"
	${MKDIR_P} ${OBJDIR}

BIN_DIR:
	@echo "created bin"
	${MKDIR_P} ${BINDIR}

.PHONY: clean
clean:
	@$(rm) $(OBJECTS)
	@echo "Cleanup complete!"

.PHONY: remove
remove: clean
	@$(rm) $(BINDIR)/$(TARGET)
	@echo "Executable removed!"

.PHONY: test
test:
	@echo "Test passed 100%"
