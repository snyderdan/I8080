SOURCE_DIR = src
OUTPUT_DIR = bin
SOURCES = $(wildcard $(SOURCE_DIR)/*.*)

ifeq ($(OS), Windows_NT)
	ROOT = $(SOURCE_DIR)/I8080.asm
	EXECUTABLE=$(OUTPUT_DIR)/I8080.dll
else
	ROOT = $(SOURCE_DIR)/I8080.asm
	EXECUTABLE=$(OUTPUT_DIR)/I8080.o
endif

default: $(EXECUTABLE)

$(OUTPUT_DIR):
	mkdir $(OUTPUT_DIR)


$(EXECUTABLE): $(SOURCES) $(OUTPUT_DIR)
	fasm $(ROOT) $(EXECUTABLE)

clean:
	rm -R $(OUTPUT_DIR)