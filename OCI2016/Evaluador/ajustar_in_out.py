"""
Script para ajustar los nombres de fichero de los JDs al formato
en que deben estar para el r.py
Frank Arteaga Salgado
frankr@coj
27/11/2015
"""

import os

def getFilesInDirectory(path):
	f = []
	for (dirpath, dirnames, filenames) in os.walk(path):
		f.extend(filenames)
		break
	return f

def getIOFiles(files, io):
	Files = { } 
	for fn in files:
		if io in fn or io.upper() in fn:
			key = fn.replace(io, '').replace(io.upper(), '')
			Files[key] = fn
	return Files

problemCode = raw_input('Enter the problem code: ')
path = '.'

Files = getFilesInDirectory(path)
InFiles = getIOFiles(Files, '.in')
OutFiles = getIOFiles(Files, '.out')
#print InFiles
#print OutFiles

assert len(InFiles) == len(OutFiles)

cantJDs = len(InFiles)
jd = 0

for k, v in InFiles.items():
	os.rename(v, problemCode + '.' + str(jd) + '.in')
	outCorrespondiente = OutFiles.get(k)
	os.rename(outCorrespondiente, problemCode + '.' + str(jd) + '.out')
	jd += 1
