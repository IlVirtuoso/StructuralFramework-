# CMakeList.txt: progetto CMake per CompliantFramework. Includere l'origine e definire
# qui la logica specifica del progetto.
#
cmake_minimum_required (VERSION 3.8)

# Aggiungere l'origine all'eseguibile di questo progetto.

#install(CompliantFramework)

add_executable (Tester "Tester.h" "Tester.cpp")


#target_link_libraries(Tester CompliantFramework)


#target_include_directories(Tester PUBLIC "../CompliantFramework/")

# TODO: Aggiungere i test e, se necessario, installare le destinazioni.
