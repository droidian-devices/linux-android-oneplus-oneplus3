ccflags-y += -D__CHECK_ENDIAN__

obj-$(CONFIG_BACKPORT_MT7601U)	+= mt7601u.o

mt7601u-objs	= \
	usb.o init.o main.o mcu.o trace.o dma.o core.o eeprom.o phy.o \
	mac.o util.o debugfs.o tx.o

CFLAGS_trace.o := -I$(src)
