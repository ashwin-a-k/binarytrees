import sys
import string

cv = input("Code vector file name:\n")

try:
    with open(f'{cv}',"r",encoding='utf-8-sig') as f:
        dic = {data[0]:data[2:].strip() for data in f.readlines()}
except:
    print("No file found")
    exit()

cv = input("Song text file name:\n")

try:
    with open(f'{cv}',"r",encoding='utf-8-sig') as f:
        data = f.readlines()
except:
    print("No file found")
    exit()


data = ["".join(filter(str.isalpha, i.lower())) for i in data]
encoded_data = []

for n, v in enumerate(data):
    concat = ""
    for j in v:
        if j:
            concat += dic.get(j, '')  # Use .get() to handle characters not in the dictionary
    encoded_data.append(concat + '\n')

with open("encoded.txt", "w") as f:
    f.writelines(encoded_data)

print("Song encoded and written to encoded.txt")
