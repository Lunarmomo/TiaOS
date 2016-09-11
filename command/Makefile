# commands/Makefile

#ENTRYPOINT	= 0x1000
HD		= ../80m.img

ASM		= nasm
DASM		= objdump
CC		= gcc -m32
LD		= ld -m elf_i386
ASMFLAGS	= -I ../include/ -f elf
CFLAGS		= -I ../include/ -c -fno-builtin -fno-stack-protector -Wall
LDFLAGS		= -Ttext 0x1000
DASMFLAGS	= -D
LIB		= ../lib/orangescrt.a
BIN		= echo file create-file read-file write-file proc-status append-file ls stat
# All Phony Targets
.PHONY : everything final clean realclean disasm all install

# Default starting position
everything : $(BIN)

install : all clean
	cp ../boot/hd*.bin ./ -v
	cp ../kernel.bin ./ -v
	tar vcf inst.tar kernel.bin $(BIN)
	dd if=inst.tar of=$(HD) seek=`echo "obase=10;ibase=16;(\`egrep -e '^ROOT_BASE' ../boot/include/load.inc | sed -e 's/.*0x//g'\`+\`egrep -e '#define[[:space:]]*INSTALL_START_SECT' ../include/sys/config.h | sed -e 's/.*0x//g'\`)*200" | bc` bs=1 count=`ls -l inst.tar | awk -F " " '{print $$5}'` conv=notrunc

all : realclean everything

final : all clean

clean :
	rm -f *.o

realclean :
	rm -f $(BIN) *.o

kernel.bin :
	cp ../kernel.bin ./

start.o : start.asm
	$(ASM) $(ASMFLAGS) -o $@ $<

echo.o: echo.c ../include/type.h ../include/stdio.h
	$(CC) $(CFLAGS) -o $@ $<
echo : echo.o start.o $(LIB)
	$(LD) $(LDFLAGS) -o $@ $?

proc-status.o: proc-status.c ../include/type.h ../include/stdio.h
	$(CC) $(CFLAGS) -o $@ $<
proc-status : proc-status.o start.o $(LIB)
	$(LD) $(LDFLAGS) -o $@ $?

get-pid.o: get-pid.c ../include/type.h ../include/stdio.h
	$(CC) $(CFLAGS) -o $@ $<
get-pid : get-pid.o start.o $(LIB)
	$(LD) $(LDFLAGS) -o $@ $?

clear.o: clear.c ../include/type.h ../include/stdio.h
	$(CC) $(CFLAGS) -o $@ $<
clear : clear.o start.o $(LIB)
	$(LD) $(LDFLAGS) -o $@ $?

create-file.o: create-file.c ../include/type.h ../include/stdio.h
	$(CC) $(CFLAGS) -o $@ $<
create-file : create-file.o start.o $(LIB)
	$(LD) $(LDFLAGS) -o $@ $?

delete-file.o: delete-file.c ../include/type.h ../include/stdio.h
	$(CC) $(CFLAGS) -o $@ $<
delete-file : delete-file.o start.o $(LIB)
	$(LD) $(LDFLAGS) -o $@ $?

file.o: file.c ../include/type.h ../include/stdio.h
	$(CC) $(CFLAGS) -o $@ $<
file : file.o start.o $(LIB)
	$(LD) $(LDFLAGS) -o $@ $?


read-file.o: read-file.c ../include/type.h ../include/stdio.h
	$(CC) $(CFLAGS) -o $@ $<
read-file : read-file.o start.o $(LIB)
	$(LD) $(LDFLAGS) -o $@ $?

write-file.o: write-file.c ../include/type.h ../include/stdio.h
	$(CC) $(CFLAGS) -o $@ $<
write-file : write-file.o start.o $(LIB)
	$(LD) $(LDFLAGS) -o $@ $?

append-file.o: append-file.c ../include/type.h ../include/stdio.h
	$(CC) $(CFLAGS) -o $@ $<
append-file : append-file.o start.o $(LIB)
	$(LD) $(LDFLAGS) -o $@ $?

ls.o: ls.c ../include/type.h ../include/stdio.h
	$(CC) $(CFLAGS) -o $@ $<
ls : ls.o start.o $(LIB)
	$(LD) $(LDFLAGS) -o $@ $?

stat.o: stat.c ../include/type.h ../include/stdio.h
	$(CC) $(CFLAGS) -o $@ $<
stat : stat.o start.o $(LIB)
	$(LD) $(LDFLAGS) -o $@ $?

pwd.o: pwd.c ../include/type.h ../include/stdio.h
	$(CC) $(CFLAGS) -o $@ $<
pwd : pwd.o start.o $(LIB)
	$(LD) $(LDFLAGS) -o $@ $?
