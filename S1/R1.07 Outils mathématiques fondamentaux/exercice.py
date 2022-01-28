################################
##S E A N C E    1   E T   2 ###
################################

from math import floor
from math import sqrt

#Retoune vrai si le nombre saisi est un nombre premier

def nbpremier (n):
    for i in range (2, floor(sqrt(n)+1)):
        if n % i == 0:
            return False
    return True

print (nbpremier(8))

#Affiche sous forme de liste les nombres premiers jusqu'à n, puis les nombres d'occurences

def eratosthene(n):
    Liste=[]
    for i in range (2,n+1):
        if nbpremier(i) :
            Liste.append(i)
    return Liste


#print (eratosthene(10))

#Programme principal nbpremier
"""
n=int(input("Saisir un entier supérieur ou égal à  2 : "))
if nbpremier(n)==True :
    print("n est premier")
else :
    print("n n'est pas premier  :")
"""

#Programme principal eratosthene
"""
n=int(input("Saisir un entier supérieur ou égal à  2 : "))
print("Liste des nombres premiers inférieurs ou égaux à n : ",eratosthene(n))
print("il y a " ,len(eratosthene(n)), " nombres premiers inférieurs ou égaux à n ")
"""

######################
##S E A N C E    3 ###
######################

import timeit
import matplotlib.pyplot as plt
#Affiche le duree d'execution pour eratosthene de 100 000

"""
debut = timeit.default_timer()
eratosthene(100000)
fin = timeit.default_timer()
duree=fin - debut
print (duree)
"""

#Visualiser sur un courbe le temps d'execution du programme dans le temps
#pour differente valeurs
"""
entier = [i for i in range (0,10000,100)]
temps=[]
for i in entier:
    tps1 = timeit.default_timer()
    eratosthene(i)
    tps2 = timeit.default_timer()
    temps.append(tps2-tps1)
    
#Representation avec pyplot de matplotlib

plt.plot(entier,temps)
plt.show() #Affiche la figure à l'écran
"""

#Visualiser l'évolution de la durée d'éxecution d'eratosthene 
#en fonction du nombre de bits utilisés pour stocker l'entier

"""
nbits = [b for b in range(10)]
liste=[2**b-1 for b in nbits]
temps = []
for i in liste:
    tps1 = timeit.default_timer()
    eratosthene(i)
    tps2 = timeit.default_timer()
    temps.append(tps2-tps1)
    
plt.plot(nbits,temps)
plt.show()
"""

#Retourne la liste de tous les facteurs premiers de la decomposition de n

def decomposition (n):
    listediv=[]
    for i in range (2, n+1):
        while n%i==0:
            listediv.append(i)
            n=n/i
    return listediv

#Programme principal

"""
n= int (input("Saisir un entier superieur ou egal a 2 : "))
print ("Liste des facteurs premiers de la decomposition de n :", decomposition(n))
"""

#Conjecture de Golbach
#Tout entier pair > 3 peut s'ecrire comme somme de 2 nombres premiers
"""
n= int (input("Saisir un entier superieur a 3 : "))
while n%2!=0 or n<3:
    n= int (input("Attenion saisir un entier pair : "))
L=eratosthene(n)
for i in L:
    reste=n-i
    if reste in L and i < reste:
        print ("N est la somme des nombres premiers :", i, "et ", reste)
            
golbach()
"""    
#########################
#### S E A N C E   4 ####
#########################

M = [[1,2],[3,4],[5,6],[7,8]]

def ligne (M,i):
    liste=[]
    for j in range (len(M)):
        liste.append(M[i][j])
    return(liste)

#print (ligne(M,1))

def colonne (M,j):
    liste=[]
    for i in range (len(M)):
        liste.append(M[i][j])
    return(liste)

#print (colonne(M,0))

def parcourir (M):
    liste=[]
    for i in range (len(M)):
        for j in range (2):
            liste.append(M[i][j])
    return(liste)

#print (parcourir(M))

def mult (M,x):
    liste=[]
    for i in range (len(M)):
        for j in range (2):
            liste.append((M[i][j]) * x)
    return(liste)

#print (mult(M, 2))

def multi_scal (M,x):
    liste=[]
    for i in range (len(M)):
        listeInit=[]
        for j in range (2):
            produit = ((M[i][j]) * x)
            listeInit.append(produit)
        liste.append(listeInit)
    return(liste)

#print (multi_scal(M, 2))

U = [4,2,1]
V = [-1,2,3]

def prod_ligne_col (u,v):
    produit = 0
    for i in range (len(U)):
        produit += ((U[i])*(V[i]))
    return(produit)

#print (prod_ligne_col(U,V))

#Supprime la i-eme ligne et la j-eme colonne
def supp_element (M,i,j):
    return (M)
#A faire
#print (supp_element(M,1,1))

def pgcd (a,b):
    while a%b!=0:
        x = a%b
        a = b
        b = x
    return(b)

#print(pgcd(9900,594))

def pgcd_v2 (a,b):
    listea = decomposition(a)
    listeb = decomposition(b)
    liste = []
    for i in range (len(listea)):
        for j in range (len(listeb)):
            if listea[i] == listeb[j]:
                liste.append(listea(i))
                listea.pop(i)
                listeb.pop(j)
                
    return(liste)    
    
#print(pgcd(9900,594))

#########################
#### S E A N C E   7 ####
#########################

import pandas as pd

#Addition
def tab_add(n):
    add = []
    for i in range (n):
        add.append([])
        for j in range (n):
            add[i].append((i+j)%n)
    df = pd.DataFrame(add, columns=[i for i in range (n)], index = [i for i in range (n)])
    return (df)
#Appel de la fonction
n= int (input("Saisir la borne supérieure non comprise afin de visualer les tables d'addition : "))
print (tab_add(n))   
    

#Multiplication
def tab_mult(n):
    mult = []
    for i in range (n):
        mult.append([])
        for j in range (n):
            mult[i].append((i*j))
    df = pd.DataFrame(mult, columns=[i for i in range (n)], index = [i for i in range (n)])
    return (df)
#Appel de la fonction
#n= int (input("Saisir la borne supérieure non comprise afin de visualer les tables de multiplication : "))
#print (tab_mult(n))

t = [[1,3,2], [0,-1,-1],[0,0,3]]
v = [64, -24, 31]

def remontee(t,v):
    n = len(t)
    copy = v [:]
    x = [None for i in range (n)]
    x[2] = copy[2]/t[2][2]
    copy[0] = copy[0]-x[2]*t[0][2]
    copy[1] = copy[1]-x[2]*t[1][2]
    x[1] = copy[1]/t[1][1]
    copy[0] = copy[0]-x[1]*t[0][1]
    x[0] = copy[0]/t[0][0]

print (remontee(t,v))