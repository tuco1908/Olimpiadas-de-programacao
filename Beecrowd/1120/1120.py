while True:
    d, v = [str(i) for i in input().split()]
    if d == '0' and v == "0":
        break
    v = list(v)
    v = [caractere for caractere in v if caractere != d]
    if v == [] and d == "0":
        print(" ")
    elif v == [] and d != "0":
        v = 0
        print(v)
    else:
        for i in range(len(v)):
            if i == len(v)-1 and v[i] == "0":
                v[i] == ''
            else:
                if v[i] == "0" and v[i+1] != "0":
                    v[i] = ''
                    break
                elif v[i] == '0' and v[i+1] == '0':
                    v[i] = ''
        v = [caractere for caractere in v if caractere != '']
        print(''.join(v))
