# -- MCU specific stuff
MCU := atmega328p
F_CPU := 16000000UL

# -- programmer/avrdude options
PROGRAMMER_TYPE := usbtiny
AVRDUDE_FLAGS := -c $(PROGRAMMER_TYPE) -p $(MCU)

# -- compilers and other toolchain shit
CC := avr-gcc
OBJCOPY := avr-objcopy
OBJDUMP := avr-objdump
AVRSIZE := avr-size
AVRDUDE := avrdude

# -- makefile magic to build everything
TARGET = $(lastword $(subst /, ,$(CURDIR)))

SOURCES := $(shell find src/ -name '*.c')
OBJECTS := $(SOURCES:.c=.o)
HEADERS := $(shell find src/ -name '*.h')

# compilation flags
CFLAGS = -DF_CPU=$(F_CPU) -Isrc/
CFLAGS += -std=gnu99 -Wall
CFLAGS += -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums
CFLAGS += -ffunction-sections -fdata-sections
CFLAGS += -O3

LDFLAGS = -Wl,-Map,$(TARGET).map
LDFLAGS += -Wl,--gc-sections

ARCHFLAGS = -mmcu=$(MCU)

all: $(TARGET).hex

# pattern rules
%.o: %.c
	$(CC) $(CFLAGS) $(ARCHFLAGS) -c -o $@ $<

$(TARGET).elf: $(OBJECTS)
	$(CC) $(LDFLAGS) $(ARCHFLAGS) $^ -o $@

%.hex: %.elf
	$(OBJCOPY) -j .text -j .data -O ihex $< $@

%.eeprom: %.elf
	$(OBJCOPY) -j .eeprom --change-section-lma .eeprom=0 -O ihex $< $@ 

%.lst: %.elf
	$(OBJDUMP) -S $< > $@


# cleaning, building
.PHONY: all eeprom size clean flash fuses

clean:
	rm -f $(OBJECTS) $(TARGET).elf $(TARGET).hex $(TARGET).obj \
		$(TARGET).o $(TARGET).d $(TARGET).eep $(TARGET).lst \
		$(TARGET).lss $(TARGET).sym $(TARGET).map $(TARGET)~ \
		$(TARGET).eeprom

# uploading

flash: $(TARGET).hex
	$(AVRDUDE) $(AVRDUDE_FLAGS) -U flash:w:$<

flash_eeprom: $(TARGET).eeprom
	$(AVRDUDE) $(AVRDUDE_FLAGS) -U eeprom:w:$<

# fuses

LFUSE = 0xf7
HFUSE = 0xde
EFUSE = 0x05

FUSE_STRING = -U lfuse:w:$(LFUSE):m -U hfuse:w:$(HFUSE):m -U efuse:w:$(EFUSE):m 

fuses: 
	$(AVRDUDE) -c $(PROGRAMMER_TYPE) -p $(MCU) \
	           $(PROGRAMMER_ARGS) $(FUSE_STRING)
show_fuses:
	$(AVRDUDE) -c $(PROGRAMMER_TYPE) -p $(MCU) $(PROGRAMMER_ARGS) -nv	

set_default_fuses:  FUSE_STRING = -U lfuse:w:$(LFUSE):m -U hfuse:w:$(HFUSE):m -U efuse:w:$(EFUSE):m 
set_default_fuses:  fuses

