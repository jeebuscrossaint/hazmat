# Makefile
include config.mk

.PHONY: all clean run debug install uninstall release compress

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS)

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

release: $(TARGET)
	strip $(TARGET)
	@if command -v upx >/dev/null 2>&1; then \
		upx --best $(TARGET); \
	else \
		echo "UPX not found. Install it for additional compression."; \
	fi