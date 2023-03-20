import sys

for line in sys.stdin:
    ip_mask = line[: -1].split("~")
    ip, mask = ip_mask[0].split("."), ip_mask[1].split(".")
    print(ip, mask)
