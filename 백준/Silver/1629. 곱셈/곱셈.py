import sys

a, b, c = map(int, sys.stdin.readline().strip().split())
print(pow(a, b, c))