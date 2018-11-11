lpg1:	imp.o	app.o
	c++ imp.o app.o -o lpg
imp.o: imp.cpp
	c++ imp.cpp -c
app.o:	app.cpp
	c++ app.cpp -c
