txt = input()
words = 0
while (len(txt)>0):
    if 'c=' in txt:
        idx = txt.find('c=')
        txt = txt[:idx]+'_'+txt[idx+2:]
    elif 'c-' in txt:
        idx = txt.find('c-')
        txt = txt[:idx]+'_'+txt[idx+2:]
    elif 'dz=' in txt:
        idx = txt.find('dz=')
        txt = txt[:idx] +'_'+ txt[idx+3: ]
    elif 'd-' in txt:
        idx = txt.find('d-')
        txt = txt[:idx] +'_'+ txt[idx+2: ]
    elif 'lj' in txt:
        idx = txt.find('lj')
        txt = txt[:idx] +'_'+ txt[idx+2: ]
    elif 'nj' in txt:
        idx = txt.find('nj')
        txt = txt[:idx] +'_'+ txt[idx+2: ]
    elif 's=' in txt:
        idx = txt.find('s=')
        txt = txt[:idx] +'_'+ txt[idx+2: ]
    elif 'z=' in txt:
        idx = txt.find('z=')
        txt = txt[:idx] +'_'+ txt[idx+2: ]
    else:
        words += len(txt)
        txt = ''

print(words)
