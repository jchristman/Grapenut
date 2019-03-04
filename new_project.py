#!/usr/bin/python3

import os
import sys
import shutil
import argparse

TEMPLATE = './templates/template.c'
TEMPLATE_SYSCALL_C = './templates/template_syscall.h'
TEMPLATE_SYSCALL_H = './templates/template_syscall.c'
PROJECT_DIR = './projects/%s'
DESTINATION = './projects/%s/main.c'
SYSCALL_H = './projects/%s/syscall.h'
SYSCALL_C = './projects/%s/syscall.c'

class Parser(argparse.ArgumentParser):
   def error(self, message):
      sys.stderr.write('\nerror: %s\n\n' % message)
      self.print_usage()
      sys.stderr.write('\n')
      sys.exit(2)

parser = Parser(description='This script creates skeletons for development of shellcode')
parser.add_argument('project_name', metavar='NAME', type=str, help='Project Name')

args = parser.parse_args()

os.mkdir(PROJECT_DIR % args.project_name)
shutil.copyfile(TEMPLATE, DESTINATION % args.project_name)
shutil.copyfile(TEMPLATE_SYSCALL_C, SYSCALL_C % args.project_name)
shutil.copyfile(TEMPLATE_SYSCALL_H, SYSCALL_H % args.project_name)
