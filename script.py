import os
import subprocess
import datetime

BED = '/home/marcotuiio/Compilers/Semantico/testes'
BSD = '/home/marcotuiio/Compilers/Semantico/saidas'
OFICIAL = '/home/marcotuiio/Compilers/Semantico/saidas_padrao'
EXEC = 'semantico'
src = '/home/marcotuiio/Compilers/Semantico'
ini = datetime.datetime.now()

os.chdir(src)
subprocess.call(["make", "clear"])
subprocess.call(["make", EXEC])

inputs = []
for (dirpath, dirnames, filenames) in os.walk(BED):
    inputs.extend(filenames)
    break

inputs.sort()

for f in inputs:
    input_file = os.path.join(BED, f)
    output_file = os.path.join(BSD, f'output_{f}')
    
    # print("valgrind ./" + EXEC +" < " + input_file + " > " + output_file)
    with open(input_file, 'r') as stdin, open(output_file, 'w') as stdout:
        subprocess.Popen(["./"+EXEC], stdin=stdin, stdout=stdout).wait()

print("\nIniciando comparação de resutados...")


outputs = []
for (dirpath, dirnames, filenames) in os.walk(OFICIAL):
    outputs.extend(filenames)
    break

my_outputs = []
for (dirpath, dirnames, filenames) in os.walk(BSD):
    my_outputs.extend(filenames)
    break

outputs.sort()
my_outputs.sort()

# print();
for index in range(len(outputs)):
    correct_output = os.path.join(OFICIAL, outputs[index])
    my_output = os.path.join(BSD, f'{my_outputs[index]}')
    print(f"diff {correct_output} {my_output}")

    with open(os.path.join(src, "diff.txt"), 'a') as stdout:
        subprocess.Popen(["diff", correct_output, my_output], stdout=stdout).wait()

fin = datetime.datetime.now()
print(f"\nTempo rodando:\n{str(fin - ini)}")
