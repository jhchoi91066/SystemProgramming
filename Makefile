CC = gcc
CFLAGS = -Wall
TARGET = main

all: $(TARGET)

$(TARGET): main.o file_operations.o system_info.o process_management.o ipc.o sysv_ipc.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o file_operations.o system_info.o process_management.o ipc.o sysv_ipc.o

main.o: main.c main.h
	$(CC) $(CFLAGS) -c main.c

file_operations.o: file_operations.c file_operations.h
	$(CC) $(CFLAGS) -c file_operations.c

system_info.o: system_info.c system_info.h
	$(CC) $(CFLAGS) -c system_info.c

process_management.o: process_management.c process_management.h
	$(CC) $(CFLAGS) -c process_management.c

ipc.o: ipc.c ipc.h
	$(CC) $(CFLAGS) -c ipc.c

sysv_ipc.o: sysv_ipc.c sysv_ipc.h
	$(CC) $(CFLAGS) -c sysv_ipc.c

clean:
	rm -f $(TARGET) *.o
