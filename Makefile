MCU = atmega324p
AVRDUDE_DEVICE = m324p -F
PORT = \\\\.\USBSER000

CFLAGS=-g -Wall -mcall-prologues -mmcu=$(MCU) -Os
CC=avr-gcc
OBJCOPY=avr-objcopy 
OBJDUMP=avr-objdump
LDFLAGS=

TARGET=led_strip

all: $(TARGET).hex

%.hex: %.elf
	$(OBJCOPY) -R .eeprom -O ihex $< $@
	
%.elf: %.o
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@

program: $(TARGET).hex
	bootloadHID.exe -r $<

clean:
	del /f *.o *.hex *.elf *.map
