TARGET   = echobot

CC       = g++
# compiling flags here
CFLAGS   = -Wall -c $(DEBUG)
LINKER   = g++ -o

# linking flags here
LFLAGS = -Wall -lgloox -lpthread $(DEBUG)

# change these to set the proper directories where each files shoould be
SRCDIR   = src
OBJDIR   = obj
BINDIR   = bin

SOURCES  := $(wildcard $(SRCDIR)/*.cpp)
INCLUDES := $(wildcard $(SRCDIR)/*.h)

OBJECTS  := $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
rm       = rm -f

$(BINDIR)/$(TARGET): $(OBJECTS)
	@$(LINKER) $@ $(LFLAGS) $(OBJECTS)
	@echo "Linking complete!"

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	@$(CC) $(CFLAGS) $< -o $@
	@echo "Compiled "$<" successfully!"

MKDIR_P = mkdir -p

all: directories  ${BINDIR}/${TARGET}

.PHONY: directories
directories:
	${OBJ_DIR} ${BIN_DIR} 

${OBJ_DIR}:
	${MKDIR_P} ${OBJDIR}

${BIN_DIR}:
	${MKDIR_P} ${BINDIR}

.PHONY: clean
clean:
	@$(rm) $(OBJECTS)
	@echo "Cleanup complete!"

.PHONY: remove
remove: clean
	@$(rm) $(BINDIR)/$(TARGET)
	@echo "Executable removed!"
