class Template:
    class Project:
        pass

    class Asm:
        pass

class Project:
    pass


Template.Base = './templates'
Template.Project.Base = '%s/projects' % Template.Base
Template.Project.Main = '%s/template.c' % Template.Project.Base
Template.Project.Syscall_c = '%s/template_syscall.c' % Template.Project.Base
Template.Asm.Base = '%s/asm' % Template.Base

Project.Base = './projects'
Project.Destination_dir = Project.Base + '/%s/'
Project.Main = Project.Destination_dir + 'main.c'
Project.Syscall_c = Project.Destination_dir + 'syscall.c'
Project.Syscall_h = Project.Destination_dir + 'syscall.h'
