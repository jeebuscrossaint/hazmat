include config.mk

.PHONY: all clean run debug install uninstall release

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

run: $(TARGET)
	./$(TARGET)

debug: $(TARGET)
	./$(TARGET); echo "Exit status: $$?"

install: $(TARGET)
	install -m 0755 $(TARGET) $(BINDIR)/$(TARGET)

uninstall:
	rm -f $(BINDIR)/$(TARGET)

release: CFLAGS = $(RELEASE_FLAGS)
release: $(TARGET)
	strip $(TARGET)