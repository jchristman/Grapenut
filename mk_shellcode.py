#!/usr/bin/python3

import os
import re
import sys
import glob
import shutil
import argparse
import config

class Parser(argparse.ArgumentParser):
   def error(self, message):
      sys.stderr.write('\nerror: %s\n\n' % message)
      self.print_usage()
      sys.stderr.write('\n')
      sys.exit(2)

parser = Parser(description='This script creates shellcode')
parser.add_argument('project_name', metavar='NAME', type=str, help='Project Name')

args = parser.parse_args()

main = config.Project.Main % args.project_name
project_dir = config.Project.Destination_dir % args.project_name
syscall_c_file = config.Project.Syscall_c % args.project_name

if not os.path.exists(project_dir):
    sys.stderr.write('That project does not exist!\n')
    sys.exit(2)

# First, get a list of all functions that exist
functions = []
for path in glob.glob(config.Template.Asm.Base + '/*.h'):
    functions.append(os.path.splitext(os.path.basename(path))[0])

code = open(main, 'r').read()

# Next use regex to find out if a function was used
used_functions = []
for function in functions:
    regex = re.compile('\\s%s\\s*\\(' % function)
    if regex.search(code):
        used_functions.append(function)

# Now generate the C file and the h file
syscall_c = '''
__asm__ volatile ("jmp end");
'''

for function in used_functions:
    asm_path = os.path.sep.join([config.Template.Asm.Base, '%s.asm' % function])

    # Add the asm function to the C file
    syscall_c += '\n__asm__ volatile (\n"{function_name}:"\n'.format(function_name=function)
    for line in open(asm_path, 'r').readlines():
        line = line.split(';')[0].strip() + '\\n'
        if len(line) == 0:
            continue
        syscall_c += '"{asm_line}"\n'.format(asm_line=line)
    syscall_c += ');\n'

syscall_c += '''
__asm__ volatile ("end:");
'''

with open(syscall_c_file, 'w') as f:
    f.write(syscall_c)
