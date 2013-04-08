import sys
import getopt
import pyparsing
import types
import re
from string import maketrans
anums = 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789,-'
anums2 = 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789,'

thecontent = pyparsing.Word(anums) | '+' |'*'| '/'
parens     = pyparsing.nestedExpr( '(', ')', content=thecontent)
thecontent2 = pyparsing.Word(anums2) | '+' |'*'| '/' | '-'
parens2     = pyparsing.nestedExpr( '(', ')', content=thecontent2)
def isop(char):
	if char =='-':
		return True
	if char =='+':
		return True
	if char =='/':
		return True
	if char =='*':
		return True
	return False
def ispar(char):
	if char =='(':
		return True
	if char ==')':
		return True
	if char ==' ':
		return True
	return False

def isdigit(char):
	if len(char)<5:
		if char =='0':
			return True
		if char =='1':
			return True
		if char =='2':
			return True
		if char =='3':
			return True
		if char =='4':
			return True
		if char =='5':
			return True
		if char =='6':
			return True
		if char =='7':
			return True
		if char =='8':
			return True
		if char =='9':
			return True
	else:
		if (char[0] == 'M' and char[4] == 'S'):
			s = char[5:]
			return isdigit(s)
	return False
def isnumber(num):
	for i in num:
		if ((not isdigit(i)) and (i !='-')):
			return False
	return True
def checksym(sym,c):
	for i in range(len(c)):
		if (c[i] != sym[i]):
			return False
	return True

def isconstant(sym):
	lensym = len(sym)
	for i in range(lensym):
		constants = ['CW','CW2','SW','SW2','MT','MT2','MZ','MZ2','S','T','U','T14','T24','S34','MW','MW2','MB','MB2','MH','MH2','Alfa','Alfa2','Pi','ME','ME2']
		for j in constants:
			if (lensym>= len(j)):
				if checksym(sym,j):
					if (lensym==len(j)):
						return True
	return False

def evalfunc(formula):
	ret = '('
	for i in formula:
		ret+= i
	ret+=')'
	return ret

def findsym2(sym):
	for i in range(len(sym)):
		# DIRTY FIX ATM
		if sym[i]=='C':
			if sym[i+1]=='W':
				tmp = sym[i+2:]
				for j in range(len(tmp)):
					if (isdigit(tmp[j])):
						return i+2+j
					return -1

		if sym[i]=='S':
			if sym[i+1]=='W':
				tmp = sym[i+2:]
				for j in range(len(tmp)):
					if (isdigit(tmp[j])):
						return i+2+j
					return -1
			if sym[i+1]=='u':
				#IN THIS CASE ONE MUST USE CPOWER !!! -> WRONG HERE
				tmp = sym[i+3:]
				#print tmp
				for j in range(len(tmp)):
					#print tmp[j]
					if ( not isdigit(tmp[j])):
						#print sym[i+2+j]
						return i+2+j
				return -1
			else:
				tmp = sym[i+1:]
				#if tmp[0]=='u':
					#return -1
				#print len(tmp),tmp
				for j in range(len(tmp)):
					#print tmp[j]
					if (isdigit(tmp[j])):
						#print sym[i+2+j]
						return i+2+j
					return i
				#tmp = sym[i+1:]
				#for j in range(len(tmp)):
					##print tmp[j]
					#if (isdigit(tmp[j])):
						##print sym[i+2+j]
						#return i+1+j
					#return -1
		if sym[i]=='M':
			if sym[i+1]=='Z':
				tmp = sym[i+2:]
				for j in range(len(tmp)):
					#print tmp[j]
					if (isdigit(tmp[j])):
						#print sym[i+2+j]
						return i+2+j
					return -1
			if sym[i+1]=='T':
				tmp = sym[i+2:]
				for j in range(len(tmp)):
					#print tmp[j]
					if (isdigit(tmp[j])):
						#print sym[i+2+j]
						return i+2+j
					return -1



				#print tmp

def evalPower(formula):
	#print 'found power'
	ret = '('
	for i in range(len(formula)):
		#print formula[i]
		#print checksym(formula[i],'CW')
		tmp =findsym2(formula[i])
		if(tmp>=0):
			#print formula[i],tmp,formula[i][:tmp+1],formula[i][tmp+1:]
			formula[i] = formula[i][:tmp+1] +'.x'+formula[i][tmp+1:]
	for i in formula:
		ret+= i
	ret+=')'
	return ret

def findfunc(formula):
	for i in range(len(formula)):
		#print formula[i]
		if (len(formula)>1):
			if (isinstance(formula[i], types.ListType)):
				if (len(formula[i]) > 1):
					findfunc(formula[i])
				if i>0:
					if (not (isnumber(formula[i-1]) or isop(formula[i-1]))):
						#print "Found function",formula[i-1]
						#if(str(formula[i-1]) == 'Power'):
							#formula[i-1]+=evalPower(formula[i])
						#else:
						formula[i-1]+=evalfunc(formula[i])
						formula.pop(i)
						return findfunc(formula)
						#formula[i] = hidefunc(formula[i])
						#print formula[i]
						#HIDE formula[i]
	return formula


def even(number):
    if number%2==0:
        return True
    else:
        return False

def isconstformula(formula,parsed = False):
	if(parsed==False):
		t1 = mprob(formula)
		t1 = '('+t1+')'				
		t2 = parens2.parseString(t1)
		t3 = t2.asList()[0]
	else:
		t3 = formula

	for i in t3:
		if (isinstance(i, types.ListType) and len(i) ==1):
			i = i[0]
		if (isinstance(i, types.ListType) and len(i)>1):
			#print "is nested"
			if (not isconstformula(i,True)):
				return False
		else:
			if (not(isop(i) or isnumber(i) or isconstant(i) or ispar(i))):
				return False

	#print "true"
	return True


def evalop(formula):
	#print len(formula)
	for i in range(len(formula)):
		#print formula[i]
		if (isinstance(formula[i], types.ListType) and len(formula[i])>0):
			#print "HERE"
			formula[i] =  evalop(formula[i])
		if i>0:
			if i< len(formula)-1:	
				if (isinstance(formula[i+1], types.ListType) and len(formula[i+1])>0):
					#print "HERE"
					formula[i+1] =  evalop(formula[i+1])
		#print i
		if (not even(i)):
			#print "HERE",formula[i]
			if (formula[i] == '/'):
				#print "Found *"
				if (isinstance(formula[i-1], types.ListType) and len(formula[i-1])==1):
					formula[i-1] = formula[i-1][0]
				if (isinstance(formula[i+1], types.ListType) and len(formula[i+1])==1):
					formula[i+1] = formula[i+1][0]
				#if (isnumber(formula[i-1])):
					#formula[i-1] = '(ctype)(' + formula[i-1] + ',0.0)'
				#if (isnumber(formula[i+1])):
					#formula[i+1] = '(ctype)(' + formula[i+1] + ',0.0)'

				if (isconstformula(formula[i+1])):
					if (len(formula[i-1])>=3):
						formula[i-1] = '(' + formula[i-1] +')'
					if (len(formula[i+1])>=3):
						formula[i+1] = '(' + formula[i+1] +')'
					formula[i-1] =formula[i-1] + '/' +formula[i+1]
				
				#if (isnumber(formula[i+1]) or isconstant(formula[i+1])):
					##if (isconstant(formula[i+1])):
						##formula[i+1] = formula[i+1] + '.x'
					#formula[i-1] =str(formula[i-1]) + '/' +str(formula[i+1])
				else:
					if (isconstformula(formula[i-1])):
						formula[i-1] = 'DtoV2('+ formula[i-1] + ')'
					formula[i-1] = 'cdiv('+ str(formula[i-1]) + ',' +str(formula[i+1])+')'
				formula.pop(i+1)
				formula.pop(i)
					#print formula
				return evalop(formula)

	for i in range(len(formula)):
		#print formula[i]
		if (isinstance(formula[i], types.ListType) and len(formula[i])>0):
			#print "HERE"
			formula[i] =  evalop(formula[i])
		if i>0:
			if i< len(formula)-1:	
				if (isinstance(formula[i+1], types.ListType) and len(formula[i+1])>0):
					#print "HERE"
					formula[i+1] =  evalop(formula[i+1])
		#print i
		if (not even(i)):
			#print "HERE",formula[i]
			if (formula[i] == '*'):
				#print "Found *",formula[i-1], formula[i+1]
				if (isinstance(formula[i-1], types.ListType) and len(formula[i-1])==1):
					formula[i-1] = formula[i-1][0]
				if (isinstance(formula[i+1], types.ListType) and len(formula[i+1])==1):
					formula[i+1] = formula[i+1][0]
				
				#print isconstformula(formula[i+1])

				if (isconstformula(formula[i-1])):
					if (len(formula[i-1])>=3):
						formula[i-1] = '(' + formula[i-1] +')'

					#if (isconstformula(formula[i+1])):
					if (len(formula[i+1])>=3):
						formula[i+1] = '(' + formula[i+1] +')'

					formula[i-1] += '*' + formula[i+1]
					formula.pop(i+1)
					formula.pop(i)
					return evalop(formula)
				else:
					if (isconstformula(formula[i+1])):
						if (len(formula[i-1])>=3):
							formula[i-1] = '(' + formula[i-1] +')'
						if (len(formula[i+1])>=3):
							formula[i+1] = '(' + formula[i+1] +')'
						formula[i-1] += '*' + formula[i+1]
						formula.pop(i+1)
						formula.pop(i)
						return evalop(formula)
					else:
						formula[i-1] = 'cmult('+ str(formula[i-1]) + ',' +str(formula[i+1])+')'
						formula.pop(i+1)
						formula.pop(i)
						return evalop(formula)


	

	for i in range(len(formula)):
		#print formula[i]
		if (isinstance(formula[i], types.ListType) and len(formula[i])>0):
			#print "HERE"
			formula[i] =  evalop(formula[i])
		if i>0:
			if i< len(formula)-1:	
				if (isinstance(formula[i+1], types.ListType) and len(formula[i+1])>0):
					#print "HERE"
					formula[i+1] =  evalop(formula[i+1])
		#print i
		if (not even(i)):
			#print "HERE",formula[i]
			if (formula[i] == '-'):
				if (isinstance(formula[i-1], types.ListType) and len(formula[i-1])==1):
					formula[i-1] = formula[i-1][0]
				if (isinstance(formula[i+1], types.ListType) and len(formula[i+1])==1):
					formula[i+1] = formula[i+1][0]
				if (isconstformula(formula[i-1]) and (not isconstformula(formula[i+1]))):
					formula[i-1] = 'DtoV2('+ formula[i-1] + ')'
				if (isconstformula(formula[i+1]) and (not isconstformula(formula[i-1]))):
					formula[i+1] = 'DtoV2('+ formula[i+1] + ')'
				formula[i-1] += '-' + formula[i+1]
				formula.pop(i+1)
				formula.pop(i)
				return evalop(formula)

	for i in range(len(formula)):
		if (isinstance(formula[i], types.ListType) and len(formula[i])>0):
			formula[i] =  evalop(formula[i])
		if i>0:
			if i< len(formula)-1:	
				if (isinstance(formula[i+1], types.ListType) and len(formula[i+1])>0):
					formula[i+1] =  evalop(formula[i+1])
		#print i
		if (not even(i)):
			#print "HERE",formula[i]
			if (formula[i] == '+'):
				if (isinstance(formula[i-1], types.ListType) and len(formula[i-1])==1):
					formula[i-1] = formula[i-1][0]
				if (isinstance(formula[i+1], types.ListType) and len(formula[i+1])==1):
					formula[i+1] = formula[i+1][0]
				if (isconstformula(formula[i-1]) and (not isconstformula(formula[i+1]))):
						formula[i-1] = 'DtoV2('+ formula[i-1] + ')'
				if (isconstformula(formula[i+1]) and (not isconstformula(formula[i-1]))):
						formula[i+1] = 'DtoV2('+ formula[i+1] + ')'
				formula[i-1] += '+' + formula[i+1]
				formula.pop(i+1)
				formula.pop(i)
				return evalop(formula)
	
					

	return formula


def checkfirstminv(formula):
	for i in range(len(formula)):
		if (formula[i] =='-'):
			for j in range(i+1,len(formula)):
			#for j in range(i,len(formula)):
				if ((formula[j] == '(') ):
					#print j
					return True
					#do nada
					print ''
				else:
					if(formula[j]!=' '):
						#print 'false'
						return False
			return False
		else:
			if ((not (formula[i] =='(')) or formula[i] ==' '):
				return False

	return False
def checkfirstmin(formula):
	for i in range(len(formula)):
		if (formula[i] =='-'):
			return True
		else:
			#NOT SURE IF THIS SOLVES THE PROBLEM!!
			if ((not (formula[i] =='(')) and formula[i] !=' '):
			#if (((formula[i] =='(')) or formula[i] !=' '):
				return False
	return False

def mprob(formula):
	for i in range(len(formula)):
		#print formula[i]
		if (len(formula)>1):
			#if (isinstance(formula[i], types.ListType)):
				#if (len(formula[i]) > 1):
					#mprob(formula[i])
			if(formula[i]== '('):
				#print i
				if(checkfirstminv(formula[i:])):
					#print 'true'
					#print formula[i:],i
					for j in range(i-1,len(formula)-2):
						if ((formula[j] == '-') ):
							#print formula[j]
							formula =formula[:j] + '-1*' + formula[j+1:] 
							return mprob(formula)
				#print formula


	
	return formula

#p = "(((3 - 4*SW2)*Power(-CW2 + SW2,2))/(CW2*CW2)*(F5*F6) + 2*(1 - 2*SW2)*(F1*F4*Sub9))"
#p = "(Sub104*pave14(cc11) + Sub106*pave14(cc22))"
#p = "(F2*F3*(Conjugate(dZfL1(2,1,1)) + Conjugate(dZfL1(3,3,3))) + F5*F6*(Conjugate(dZfL1(3,3,3)) + Conjugate(dZfR1(2,1,1))) + F1*F4*(Conjugate(dZfL1(2,1,1)) + Conjugate(dZfR1(3,3,3))) + F7*F8*(Conjugate(dZfR1(2,1,1)) + Conjugate(dZfR1(3,3,3))))"

#p = "(1/SW2*((-1 - 2*SW2)*(F2*F3) + 2*SW2*(F5*F6)))"
#p = "( -1*(ChainV0(Spinor(1,-1,2),0,0,Spinor(3,-1,1))*Hel(1)*Hel(3)))"
#p = "(-1*(2*MT2*(-(F2*F3) - F1*F4)) + F10*(F18 + MT*(F12 + F9)))"
p = "(Alfa*Pi*(-(2/(3*CW2)*Sub2/(-MZ2 + S)) + 16/3*Sub3/S))"

p = "((MT2*(-CW2 + SW2))/MW2*(4*Sub49 - (MT*Power(1 - 2*SW2,2))/(SW2*SW2)*Sub44))"
p = "(-(F14*Sub9986) + F5*F9*U + F30*(F54 + 3*MT2*F11))"

p = "((MT*(3 - 4*SW2)*Power(-CW2 + SW2,2))/(CW2*CW2*(SW2*SW2))*(F11*F13) + 32/SW2*(-(F12*F34) + F21*F8))"

p ="((-4 + 8*SW2)*(F22*F29) + (4 - 8*SW2)*(F14*F3) + 8*SW2*Sub3 + 3*MT*Sub4 + (-3 + 4*SW2)*Sub5)"

p = "(-2/(F30*F38 + F48*F5 - SW) + (5*MT2 - 4*U)*U*F5*F6 + F1*F2*U)"

p = "(MT*(Sub151*(32*(SW2*SW2)*(F2*F3) + 8*(3 - 4*SW2)*SW2*(F21*F32) + Power(1-SW2,3)*(4/SW2*(F16*F34) + (3 - 4*SW2)/(SW2*SW2)*(F10*F6)))))"

p ="((Alfa*Pi)/(CW*CW2)*(dZZA1*Sub222)/((-MZ2 + S)*SW))"

p = "(Pair3*(-2*MT2 + 3*S + 2*(T + U)))"


#if p[1] =='-':
	#p = '(-1*'+p[1:]


def parse(formula):
	formula =formula.translate(None,'.')
	#print formula
	formula = mprob(formula)
	#print formula
	parsedform = parens.parseString(formula)
	parsedform2 = parsedform.asList()[0]
	#print parsedform2
	return evalop(findfunc(parsedform2))[0]

def findeq(string):
	for i in range(len(string)):
		if string[i] == '=':
			return i
	return False

#print p
#print parse(p)

def checkfirstparen(eq):
	for i in range(len(eq)):
		if (eq[i] == '('):
			return True
		if (eq[i] != ' '):
			return False

starteq = False
start = ''
eq = ''
filetoopen = sys.argv[1]
parsedfile = 'parsed_'+filetoopen
fileabbr = open(parsedfile,'w')
for line in open(filetoopen,'r'):
	if (not starteq):
		index = findeq(line)
		if index > 0:
			start =line[:index+1]
			eq += line[index+1:]
		    	starteq = True
	else:
		index = findeq(line)
		if index == 0:
			eq += line
		else:
			#CONVERT AND WRTIE TO FILE
			eq =eq.translate(None,';')
			eq =eq.translate(None,'\n')
			eq =eq.translate(None,'\t')

			test =checkfirstparen(eq)
			if(checkfirstmin(eq)):
				#print 'true'
				for i in range(len(eq)):
					#print eq
					if (eq[i] == '-'):
						eq = '(-1*' + eq[i+1:]+')'
						break
				if test:
					eq = '(' + eq + ')'

			else:
				eq = '(' + eq + ')'


			toprint = '\n'
			fileabbr.write(toprint)
			toprint = start+ " " +parse(eq) + ';'+'\n'
			fileabbr.write(toprint)

			start =line[:index+1]
			eq = line[index+1:]
		    	starteq = True

