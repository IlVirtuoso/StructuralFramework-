# CMakeList.txt: file di progetto CMake di primo livello. Eseguire la configurazione globale
# e includere qui i sottoprogetti.
#
cmake_minimum_required (VERSION 3.8)

project ("StructuralFramework")
set(LOCAL_RUN FALSE)

# Includere i sottoprogetti.
add_subdirectory (Core)
add_subdirectory(NetSupport)
