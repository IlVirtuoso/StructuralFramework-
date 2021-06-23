# CMakeList.txt: progetto CMake per CompliantFramework. Includere l'origine e definire
# qui la logica specifica del progetto.
#
cmake_minimum_required (VERSION 3.8)
if(NOT DEFINED ${LOCAL_RUN})
	set(LOCAL_RUN true)
project(Structural.Streams)
endif() 


if(${LOCAL_RUN})
	ADD_EXECUTABLE(Structural.Streams  "Streams.hpp" "BufferedReader.cpp" "FileReader.cpp" "test.cpp" "FileSystem.hpp" "FileSystem.cpp")
else()
	add_library (Structural.Streams  "Streams.hpp" "Streams.cpp")
	target_link_libraries(Structural.Streams LINK SHARED)
# TODO: Aggiungere i test e, se necessario, installare le destinazioni.
endif()
