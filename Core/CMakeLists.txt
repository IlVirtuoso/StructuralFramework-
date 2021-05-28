# CMakeList.txt: progetto CMake per CompliantFramework. Includere l'origine e definire
# qui la logica specifica del progetto.
#
cmake_minimum_required (VERSION 3.8)
project("Core")
# Aggiungere l'origine all'eseguibile di questo progetto.
#add_executable (Core "Core.cpp" "Core.h")
add_library (Core SHARED "Core.cpp" "Core.h"  "ISerializable.hpp" "Collections.hpp" "Collections.cpp")
add_compile_definitions(EXPORT)

# TODO: Aggiungere i test e, se necessario, installare le destinazioni.
