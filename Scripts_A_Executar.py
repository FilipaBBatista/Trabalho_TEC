#!/usr/bin/env python
import os
import time
import random
import multiprocessing  # the module we will be using for multiprocessing

def work(Run):
	
	WORKING_DIRECTORY=os.getcwd()
	#os.system("root -l Histogramas_Dep_Per_Event.C\(\\\"AmberTarget_Run_"+str(Run)+".root\\\"\)")
	
	#os.system("root -l Pioes_Muoes_Outras.C\(\\\"AmberTarget_Run_"+str(Run)+".root\\\"\)")
	
	#os.system("root -l Histogramas_ETotal_Particula.C\(\\\"AmberTarget_Run_"+str(Run)+".root\\\"\)")
	
	#os.system("root -l Histogramas_VH_PS_EmZ.C\(\\\"AmberTarget_Run_"+str(Run)+".root\\\"\)")
	
	#os.system("root -l Histogramas_DistXY_Detetor.C\(\\\"AmberTarget_Run_"+str(Run)+".root\\\"\)")
	
	#os.system("root -l Histogramas_DistXY_Detetor_Particula.C\(\\\"AmberTarget_Run_"+str(Run)+".root\\\"\)")
	
	#os.system("root -l total_energia_per_event.C\(\\\"AmberTarget_Run_"+str(Run)+".root\\\"\)")
	
	#os.system("root -l Histogramas_DT_H_Detetor.C\(\\\"AmberTarget_Run_"+str(Run)+".root\\\"\)")
	
	#os.system("root -l Histogramas_MZ_MP.C\(\\\"AmberTarget_Run_"+str(Run)+".root\\\"\)")
	
	os.system("root -l Histogramas_MZ_P_PS.C\(\\\"AmberTarget_Run_"+str(Run)+".root\\\"\)")
	
	



if __name__ == "__main__":  # Allows for the safe importing of the main module
	print("There are %d CPUs on this machine" % multiprocessing.cpu_count())

	number_processes = multiprocessing.cpu_count()-1 # Numero de CPU's - 1
	pool = multiprocessing.Pool(number_processes)
	total_tasks = 4 # É o número de ficheiros .root
	tasks = range(total_tasks)
	results = pool.map_async(work, tasks)
	pool.close()
	pool.join()
		
