import random
lower = int(input("Enter a lower limit : "))
upper = int(input("Enter a upper limit : "))

samples  = int(input("Enter how many sample number u want : "))

output = []
print(output);


file = open('samples.csv','w')
for x in range(samples):
	randomsample = random.randint(lower,upper)

	output.append(randomsample)

with open("samples.csv", "w") as txt_file:
    for line in samples:
        txt_file.write(" ".join(line) + "\n") 

print(output);



file.close()