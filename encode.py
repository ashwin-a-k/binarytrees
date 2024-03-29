import sys
import string

cv = input("Code vector file name:\n")

try:
    with open(f'{cv}',"r",encoding='utf-8-sig') as f:
        dic = {data[0]:data[2:].strip() for data in f.readlines()}
except:
    print("No file found")
    exit()

print("Paste text here:\nEnter 'ngwx' to exit")
data = []

with open("encoded.txt","w") as f:
    for line in sys.stdin:
        if 'ngwx' == line.rstrip():
            print("Exit")
            break
        data.append(line)
    data = ["".join(filter(str.isalpha, i.lower())) for i in data]
    for n,v in enumerate(data):
        concat = ""
        for j in v:
            if j:
                concat += dic[j]
        data[n] = concat + '\n'
    f.writelines(data)