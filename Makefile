include config.mk

.PHONY: all clean run debug install uninstall release

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS) $(LDFLAGS)

# Special compile rule for source files
src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

run: $(TARGET)
	./$(TARGET)

debug: $(TARGET)
	./$(TARGET); echo "Exit status: $$?"

install: $(TARGET)
	mkdir -p $(DESTDIR)$(BINDIR)
	install -m 0755 $(TARGET) $(DESTDIR)$(BINDIR)/$(TARGET)

uninstall:
	rm -f $(BINDIR)/$(TARGET)

release: CFLAGS = $(RELEASE_FLAGS)
release: clean $(TARGET)
	strip $(TARGET)
