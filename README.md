# Minecraft

### Compile

Remove all the objects:

`$ make clean`

Compile into the objects then into an executable:

`$ make`

### Re-Compile (if only one file has been changed)

Remove the object:

`$ rm TheFile.o` or `$ rm -f TheFile.o` (with the force flag)

Compile into the object (only TheFile.o) then into an executable:

`$ make
