MIDI_DIR = protocol/midi

SRC += midi.c \
	   midi_device.c \
	   bytequeue/bytequeue.c \
	   bytequeue/interrupt_setting.c \
	   sysex_tools.c \
     qmk_midi.c \
	   $(LUFA_SRC_USBCLASS)

VPATH += $(TMK_PATH)/$(MIDI_DIR)
