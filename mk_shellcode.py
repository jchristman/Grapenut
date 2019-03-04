#!/usr/bin/python3

import os
import sys
import shutil
import argparse

ASM_TEMPLATES = './templates/asm'
EXTERNS = './templates/externs.c'
PROJECT_DIR = './projects/%s/'

class Parser(argparse.ArgumentParser):
   def error(self, message):
      sys.stderr.write('\nerror: %s\n\n' % message)
      self.print_usage()
      sys.stderr.write('\n')
      sys.exit(2)

parser = Parser(description='This script creates shellcode')
parser.add_argument('project_name', metavar='NAME', type=str, help='Project Name')

args = parser.parse_args()

project_dir = PROJECT_DIR % args.project_name
if not os.path.exists(project_dir):
    sys.stderr.write('That project does not exist!\n')
    sys.exit(2)

