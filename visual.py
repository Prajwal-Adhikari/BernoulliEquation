import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from matplotlib.pyplot import rcParams

df = pd.read_csv("outputs.csv")

print("********************************* User Instructions *********************************************************************\nPlease choose and enter as following:\n-------------------------------------------------------------------------------------------------------------------------\nEnter 1 to plot a line graph of lengths vs upper velocity,lower velocity and lower Pressure\nEnter 2 to plot a line graph of upper diameter vs upper velocity,lower velocity and lower Pressure\nEnter 3 to plot a line graph of lower diameter vs upper velocity,lower velocity and lower Pressure\nEnter 4 to plot a line graph of lower diameter vs upper velocity,lower velocity and lower Pressure\nEnter 5 to plot a line graph of lower diameter vs upper velocity,lower velocity and lower Pressure\n-------------------------------------------------------------------------------------------------------------------------")

choice = int(input("Enter a number here : "));



if choice == 1:
	plt.rcParams["figure.figsize"] = (10,8) 
	plt.plot(df.Lengths,df.upperVelocity,marker="+",linestyle='dashed',color='r',label='upperVelocity')
	plt.plot(df.Lengths,df.lowerVelocity,marker="+",linestyle='dotted',color='g',label='lowerVelocity')
	plt.plot(df.Lengths,df.lowerPressure,marker="*",linestyle='solid',color='b',label='lowerPressure')
	plt.grid(True)
	plt.xlabel("Lengths in meters")
	plt.ylabel("upperVelocity lowerVelocity lowerPressure")
	plt.title("Variation in outputs due to varying lengths")
	plt.legend()
	plt.show()

elif choice == 2:
	plt.rcParams["figure.figsize"] = (10,8) 
	plt.plot(df.UpperDiameter,df.upperVelocity,marker="+",linestyle='dashed',color='r',label='upperVelocity')
	plt.plot(df.UpperDiameter,df.lowerVelocity,marker="+",linestyle='dotted',color='g',label='lowerVelocity')
	plt.plot(df.UpperDiameter,df.lowerPressure,marker="*",linestyle='solid',color='b',label='lowerPressure')
	plt.grid(True)
	plt.xlabel("UpperDiameters in mm")
	plt.ylabel("upperVelocity lowerVelocity lowerPressure")
	plt.title("Variation in outputs due to varying UpperDiameters")
	plt.legend()
	plt.show()

elif choice == 3:
	plt.rcParams["figure.figsize"] = (10,8) 
	plt.plot(df.lowerDiameter,df.upperVelocity,marker="+",linestyle='dashed',color='r',label='upperVelocity')
	plt.plot(df.lowerDiameter,df.lowerVelocity,marker="+",linestyle='dotted',color='g',label='lowerVelocity')
	plt.plot(df.lowerDiameter,df.lowerPressure,marker="*",linestyle='solid',color='b',label='lowerPressure')
	plt.grid(True)
	plt.xlabel("lowerDiameter in mm")
	plt.ylabel("upperVelocity lowerVelocity lowerPressure")
	plt.title("Variation in outputs due to varying lowerDiameters")
	plt.legend()
	plt.show()

elif choice == 4:
	plt.rcParams["figure.figsize"] = (10,8) 
	plt.plot(df.flowRate,df.upperVelocity,marker="+",linestyle='dashed',color='r',label='upperVelocity')
	plt.plot(df.flowRate,df.lowerVelocity,marker="+",linestyle='dotted',color='g',label='lowerVelocity')
	plt.plot(df.flowRate,df.lowerPressure,marker="*",linestyle='solid',color='b',label='lowerPressure')
	plt.grid(True)
	plt.xlabel("flowRate in liters/sec")
	plt.ylabel("upperVelocity lowerVelocity lowerPressure")
	plt.title("Variation in outputs due to varying flowRates")
	plt.legend()
	plt.show()


elif choice == 5:
	plt.rcParams["figure.figsize"] = (10,8) 
	plt.plot(df.UpperPressure,df.upperVelocity,marker="+",linestyle='dashed',color='r',label='upperVelocity')
	plt.plot(df.UpperPressure,df.lowerVelocity,marker="+",linestyle='dotted',color='g',label='lowerVelocity')
	plt.plot(df.UpperPressure,df.lowerPressure,marker="*",linestyle='solid',color='b',label='lowerPressure')
	plt.grid(True)
	plt.xlabel("UpperPressure in KN/m2")
	plt.ylabel("upperVelocity lowerVelocity lowerPressure")
	plt.title("Variation in outputs due to varying UpperPressures")
	plt.legend()
	plt.show()
