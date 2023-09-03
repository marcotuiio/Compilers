import os
import subprocess
import datetime

BED = '/home/marcotuiio/Compilers/Lista_6/entradas'
BSD = '/home/marcotuiio/Compilers/Lista_6/o'
OFICIAL = '/home/marcotuiio/Compilers/Lista_6/saidas'
src = '/home/marcotuiio/Compilers/Lista_6'
ini = datetime.datetime.now()

os.chdir(src)
subprocess.call(["make", "clear"])
subprocess.call(["make", "l6e1"])
print("\n")

inputs = []
for (dirpath, dirnames, filenames) in os.walk(BED):
    inputs.extend(filenames)
    break

inputs.sort()

for f in inputs:
    input_file = os.path.join(BED, f)
    output_file = os.path.join(BSD, f'output_{f}')
    
    with open(input_file, 'r') as stdin, open(output_file, 'w') as stdout:
        subprocess.Popen(["./l6e1"], stdin=stdin, stdout=stdout).wait()

print("Iniciando comparação de resutados...\n")


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

for index in range(len(outputs)):
    correct_output = os.path.join(OFICIAL, outputs[index])
    my_output = os.path.join(BSD, f'{my_outputs[index]}')
    print(f"Comparando {correct_output} com {my_output}")

    with open(os.path.join(src, "diff.txt"), 'a') as stdout:
        subprocess.Popen(["diff", correct_output, my_output], stdout=stdout).wait()

print("\n")
fin = datetime.datetime.now()
print(f"Tempo para rodar:\n{str(fin - ini)}")
