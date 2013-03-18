#!/usr/bin/env python

import os
import os.path


f = open('CMakeLists.txt', 'w')

def write_test(f, fname):
	print(fname)
	name=fname[:-4]
	f.write('add_executable({0}_exc {1})\n'.format(name, fname))
	f.write('target_link_libraries({0}_exc culio culsys cullog)\n'.format(name))
	f.write('get_target_property({0}_loc {0}_exc LOCATION)\n'.format(name))
	f.write('add_test(NAME {0} WORKING_DIRECTORY "${{CMAKE_CURRENT_LIST_DIR}}" COMMAND "${{{0}_loc}}")\n'.format(name))
	f.write('\n')
	
for root, dirs, files in os.walk('.'):
	#print(files)
	for file in files:
		if file.endswith('.cpp'):
			write_test(f, file)
				
f.close();

