CC=gcc
BINDIR=/bin
SHARED=/usr/share
LOCBIN=~/.local/bin
SRC=\
	dummy.c \
	dummyfiles/all_h3lp.c \
	dummyfiles/assets/assets.c \
	dummyfiles/development/development.c \
	dummyfiles/gaming/gaming.c \
	dummyfiles/multimedia/multimedia.c \
	dummyfiles/networking/networking.c \
	dummyfiles/packages/packages.c \
	dummyfiles/programming/programming.c \
	dummyfiles/security/security.c \
	dummyfiles/utilities/utilities.c
TARGET=dummy
HEADER=dummyfiles/headers.h
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
