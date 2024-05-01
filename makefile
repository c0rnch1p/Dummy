CC=gcc
BINDIR=/bin
SHARED=/usr/share
LOCBIN=~/.local/bin
SRC=\
	dummy.c \
	helpfiles/all_h3lp.c \
	helpfiles/assets/assets.c \
	helpfiles/development/development.c \
	helpfiles/gaming/gaming.c \
	helpfiles/multimedia/multimedia.c \
	helpfiles/networking/networking.c \
	helpfiles/packages/packages.c \
	helpfiles/programming/programming.c \
	helpfiles/security/security.c \
	helpfiles/utilities/utilities.c
TARGET=dummy
HEADER=helpfiles/headers.h
CFLAGS=-lmenu -lncurses -lm

all: $(TARGET)

$(TARGET): $(SRC) $(HEADER)
	$(CC) $(SRC) -o $(TARGET) $(CFLAGS)

install: $(TARGET)
	mv $(TARGET) $(LOCBIN)
	sudo mv $(LOCBIN)/$(TARGET) $(BINDIR)
	sudo cp -r ../Dummy $(SHARED)

clean:
	rm -f $(LOCBIN)/$(TARGET)
	sudo rm -f $(BINDIR)/$(TARGET)
	sudo rm -rf $(SHARED)/Dummy
