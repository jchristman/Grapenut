#!/usr/bin/python3

import os
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

parser = Parser(description='This script creates skeletons for development of shellcode')
parser.add_argument('project_name', metavar='NAME', type=str, help='Project Name')

args = parser.parse_args()

# 1. Make the project directory
os.mkdir(config.Project.Destination_dir % args.project_name)

# 2. Copy the template main.c into the directory
shutil.copyfile(config.Template.Project.Main, config.Project.Main % args.project_name)

# 3. Copy the template syscall.c (empty) into the directory
shutil.copyfile(config.Template.Project.Syscall_c, config.Project.Syscall_c % args.project_name)

# 4. Make a complete header file to inform the user what's available
all_h_data = ''
for path in glob.glob(config.Template.Asm.Base + '/*.h'):
    all_h_data += open(path, 'r').read()
with open(config.Project.Syscall_h % args.project_name, 'w') as f:
    f.write(all_h_data)
