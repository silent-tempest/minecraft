# common use: `$ make clean minecraft`

src := \
	sources/VirtualTicker.cc \
	sources/RendererGL.cc \
	sources/Transform.cc \
	sources/Program.cc \
	sources/Shader.cc \
	utils/mat3.cc \
	main.cc
obj := $(src:.cc=.o)
exe := minecraft.deb

clean:
	rm -f $(obj)

$(obj):
	g++ -c -Wall $(subst .o,.cc,$@) -o $@

$(exe): $(obj)
	g++ $(obj) -o bin/$@ -lGL -lGLEW -lglfw
