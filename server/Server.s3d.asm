0:	PUSHN	0		
1:	CALLX	5 :CVMMOUSE		0
2:	POP  			G0:MOUSE
3:	CALLX	1 :CVMJOYSTICK		0
4:	POP  			G1:JOYSTICK
5:	CALLX	2 :CVMMMAVI		0
6:	POP  			G2:MMAVI
7:	CALLX	4 :CVMMMMP3		0
8:	POP  			G3:MMMP3
9:	CALLX	3 :CVMMMMIDI		0
10:	POP  			G4:MMMIDI
11:	RET  			
12:	PUSHN	0		
13:	RET  	Void		
14:	PUSHN	0		
15:	PUSH 	<cStr0 "">		
16:	CALLX	11 :SETLOCALDIR		1
17:	POPN 	2		
18:	PUSH 	<cStr1 "../UtilityDll/Release/UtilityDll.dll">		
19:	CALLX	0 :CVMEXTERNDLL		1
20:	POP  			G7:TESTDLL
21:	POPN 	1		
22:	PUSH 	<cStr2 "get_IPaddress">		
23:	PUSH 	4		
24:	CALLM	G7:TESTDLL	m_0	2
25:	POPN 	3		
26:	CALLM	G7:TESTDLL	m_1	0
27:	POP  			G5:MY_IP
28:	PUSH 	<cStr3 "\n">		
29:	CALLX	8 :OUTPUTLN		1
30:	POPN 	2		
31:	PUSH 	G5:MY_IP		
32:	CALLX	8 :OUTPUTLN		1
33:	POPN 	2		
34:	PUSH 	1		
35:	PUSH 	<cStr4 "0.0.0.0">		
36:	PUSH 	50023		
37:	CALLX	6 :NETCREATECHANNEL		3
38:	POP  			G6:NET_CHANNEL
39:	POPN 	3		
40:	RET  	Void		
41:	PUSHN	0		
42:	CALLX	9 :SCENEBEGIN		0
43:	POPN 	1		
44:	CALLX	10 :SCENEEND		0
45:	POPN 	1		
46:	RET  	Void		
47:	PUSHN	0		
48:	RET  	Void		
49:	PUSHN	8		
50:	PUSH 	<cStr5 "................">		
51:	PUSH 	G6:NET_CHANNEL		
52:	CALLX	7 :NETVARRECEIVEFROM		2
53:	POP  			BP(1)
54:	POPN 	2		
55:	JV   	BP(1)		Quad:66
56:	GET  	BP(1)	0	BP(2)
57:	JNEQ 	BP(2)	0	Quad:66
58:	GET  	BP(1)	1	BP(2)
59:	GET  	BP(1)	2	BP(3)
60:	ADD  	<cStr6 "received: ">	BP(2)	BP(4)
61:	ADD  	<cStr7 " ">		BP(4)
62:	ADD  	BP(3)		BP(4)
63:	PUSH 	BP(4)		
64:	CALLX	8 :OUTPUTLN		1
65:	POPN 	2		
66:	RET  	Void		
67:	PUSHN	0		
68:	RET  	Void		
69:	PUSHN	0		
70:	RET  	Void		
71:	PUSHN	0		
72:	RET  	Void		
