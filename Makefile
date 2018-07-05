# The Use:
#   Compile into an Object:                           make name.o
#   Compile into the Objects then into an Executable: make
#   Compile into an Executable:                       make bin/minecraft.deb
#   Remove All the Objects:                           make clean

src=timestamp.cc mat3.cc Matrix.cc Shader.cc Program.cc RendererGL.cc VirtualTicker.cc main.cc
obj=$(src:.cc=.o)
exe=bin/minecraft.deb

all: $(obj) $(exe)

%.o:
	g++ -c -Wall $(subst .o,.cc, $@) -o $@

$(exe): $(obj)
	g++ $(obj) -o $@ -lGL -lGLEW -lglfw

clean:
	rm -f $(obj)
