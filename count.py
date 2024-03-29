import string

file_name = "WarPeace.txt"

with open(file_name,"r",encoding='utf-8-sig') as f:
    data = "".join(f.read().lower().split())
    data = data.translate(str.maketrans('', '', string.punctuation))

dic = {}
for i in data:
    if i in dic:
        dic[i] += 1
    else:
        dic[i] = 1
    
dic = {k: dic[k] for k in sorted(dic) if k in [chr(i) for i in range(97,122+1)]}

with open("frequency.txt","w") as f:
    for i in dic:
        f.write(f'{i} {dic[i]}\n')