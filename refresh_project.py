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

# Make a complete header file to inform the user what's available
all_h_data = ''
for path in glob.glob(config.Template.Asm.Base + '/*.h'):
    all_h_data += open(path, 'r').read()
with open(config.Project.Syscall_h % args.project_name, 'w') as f:
    f.write(all_h_data)
