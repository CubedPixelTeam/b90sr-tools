f = open("text","r")
contents = f.readlines()
i = 0
e = 0
num_lines = sum(1 for _ in open('text'))
output = open("output","w")
while i<num_lines:
    e = i+1
    line = contents[i].replace('\n','')
    string = f"Crystals[{i}].Create({e},1,{line});\n"
    output.write(string)
    i += 1
f.close()
output.close()
print("Done.")
