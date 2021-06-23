# CMakeList.txt: progetto CMake per CompliantFramework. Includere l'origine e definire
# qui la logica specifica del progetto.
#
if(NOT DEFINED ${LOCAL_RUN})
	set(LOCAL_RUN TRUE)
endif()
cmake_minimum_required (VERSION 3.8)
project(Structural.Core)



    # Note: 2 target(s) were omitted.
# Aggiungere l'origine all'eseguibile di questo progetto.
if(${LOCAL_RUN})
	add_executable (Structural.Core "Core.cpp" "Core.h" "Interfaces.hpp" "Parsers.hpp" "Parsers.cpp")
else()
	add_library (Structural.Core SHARED "Core.cpp" "Core.h"  "ISerializable.hpp" "Collections.hpp" "Collections.cpp")
	endif()
add_compile_definitions(EXPORT)
# TODO: Aggiungere i test e, se necessario, installare le destinazioni.