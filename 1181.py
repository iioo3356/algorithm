n = int(input())
char_set = set()
for _ in range(n):
    char_set.add(input())
char_set = sorted(char_set, key=lambda x: (len(x), x))
for i in char_set:
    print(i)
