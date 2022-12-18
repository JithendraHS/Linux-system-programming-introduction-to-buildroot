# Platform Overrides
PLATFORM = HOST
GCC = gcc
ifeq ($(PLATFORM),HOST)
  CC = $(GCC)
  CFLAGS = -g -o $@ $^
else
  CC = aarch64-none-linux-gnu-$(GCC)
  CFLAGS = -g -o $@ $^
endif
SOURCES = writer.c
OBJS = $(SOURCES:.c=.o)
TARGET = $(OBJS:.o=)

%.o : %.c
	$(CC) $(CFLAGS)
	@echo --created object file $@--

.PHONY: build
build: $(TARGET)

$(TARGET):$(SOURCES)
	$(CC) $(CFLAGS)
	
.PHONY: clean
clean:
	@echo "--cleaning--"
	rm -f *.o $(TARGET)
