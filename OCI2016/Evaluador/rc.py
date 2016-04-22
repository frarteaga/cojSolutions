#r.py inspirado en batman.bat

import sys
import os

code_prob        = sys.argv[1]
dia              = code_prob[0]
tiempo_limite    = sys.argv[2]
memoria_limite   = sys.argv[3]
check            = sys.argv[4]
verbose          = sys.argv[5]
provincia        = sys.argv[6]
concursante      = provincia + sys.argv[7]

def FileExist(filename):
	try:
		f = open(filename, 'r')
		f.close()
		return True
	except:
		return False

cc = 'g++.exe'		
cc += ' -O2 -Wall '

carpeta = 'concursantes\\' + provincia + '\\DIA' + dia + '\\' + concursante + '\\'
fileName = concursante + '-' + code_prob 	
eje_concursante  = carpeta + fileName + '.exe'
print 'Borrando ejecutable antiguo'
os.system("erase " + eje_concursante)
e = os.system(cc + ' -o ' + eje_concursante + ' ' + carpeta + fileName + '.cpp ')

if e != 0:
	print 'Error al Compilar :('
	os.system('color 0C')
	sys.exit(1)

iofiles = {'1A': 'hexagono' , '1B': 'cuentas', '1C': 'robot',
           '2A': 'tablas', '2B': 'rutas' , '2C': 'fumigacion'}

#print eje_concursante
 
if FileExist(eje_concursante) == False:
	print 'Hubo un error al copiar el codigo del concursante'
	raw_input('\n\nPresiones [Enter] para continuar')
	os.system('cls')
else:
	#os.system('cls');
	JD = 0
	ofi_in = 'tests_\\' + iofiles[code_prob] + '\\' + iofiles[code_prob] + '.' + str(JD) + '.in';
	ofi_out = 'tests_\\' + iofiles[code_prob] + '\\' + iofiles[code_prob] + '.' + str(JD) + '.out';
	print ofi_in
	AC = WA = RTE = MLE = TLE = 0
	PUNT = 0.0
	while FileExist(ofi_in):
		#print ofi_in
		e = os.system("copy " + ofi_in + " " + iofiles[code_prob] + ".in")
		if e != 0:
			print 'Hubo un error un error al copiar el archivo de entrada original'
			input()
		print "\n> Caso de Prueba # " + str(JD) + ":\n"
		salida = '\n\n>> Veredicto: '
		e = os.system("grader.exe " + eje_concursante + ' ' + tiempo_limite + " " + memoria_limite);
		if e == 1:
			salida += ' *** TLE ***'
			TLE += 1
			os.system('color 0C')
		elif e == 2:
			salida += ' *** MLE ***'
			MLE += 1
			os.system('color 0C')
		elif e == 3:
			salida += ' *** RTE ***'
			RTE += 1
			os.system('color 0C')
		else:
			#e = os.system("copy " + ofi_out + " " + iofiles[code_prob] + "___ofi.out")
			e = os.system(check + ' ' + ofi_out + ' ' + iofiles[code_prob] + '.out')
			if e != 0:
				salida += ' *** WA ***'
				WA += 1
				os.system('color 0C')
			else:
				if code_prob == '1A' or code_prob == '1C':
					if FileExist('puntuacion.txt'):
						fpunt = open('puntuacion.txt', 'r')
						puntuacion = float(fpunt.readline())
						if puntuacion > 0:
							salida += ' *** AC ***'
							AC += 1
							os.system('color 0A')
						else:
							salida += ' *** WA ***'
							WA += 1
							os.system('color 0C')
						PUNT += puntuacion
						fpunt.close()
						os.system("move puntuacion.txt punt.txt")
					else:
						print 'rc.py log: Error en el archivo puntuacion, revisar checker'
						sys.exit(1)
				else:	
					salida += ' *** AC ***'
					AC += 1
					os.system('color 0A')
		print salida
		if verbose == '1':
			raw_input('\nPresione una tecla para continuar')
		JD += 1
		ofi_in = 'tests_\\' + iofiles[code_prob] + '\\' + iofiles[code_prob] + '.' + str(JD) + '.in';
		ofi_out = 'tests_\\' + iofiles[code_prob] + '\\' + iofiles[code_prob] + '.' + str(JD) + '.out';
		#os.system('erase ' + iofiles[code_prob] + "___ofi.out")
		
	os.system('erase ' + code_prob + " *.in *.out")
	
	os.system('color 07')
	print '\n       .:: Reporte ::.'
	print '       ---------------  \n'
	print '                   Aceptados: ' + str(AC);
	print '      Respuestas Incorrectas: ' + str(WA)
	print '      Tiempo Limite Excedido: ' + str(TLE)
	print '     Memoria Limite Excedida: ' + str(MLE)
	print 'Error en Tiempo de Ejecucion: ' + str(RTE)
	if code_prob != '1A' and code_prob != '1C':
		print '\nPor ciento de casos aceptados: ' + str(float(AC) / float(JD) * 100)
	else:
		print '\nPuntuacion final: ' + str(PUNT)

