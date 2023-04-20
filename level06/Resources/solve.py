
test_string = 'test123'

string = list(map(ord, test_string))
length = len(string)

n = (string[3] ^ 0x1337) + 0x5EEDED

for i in range(length):
    if string[i] <= 31:
        print("No")
        exit()
    n += (n ^ string[i]) % 0x539

print(n)

