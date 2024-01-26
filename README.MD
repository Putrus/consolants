# Uruchomienie programu
W celu uruchomienia programu ConsolAnts należy odpalić skrypt RunSimulation.bat

# Uruchomienie testów
W celu uruchomienia testów jednostkowych należy uruchomić skrypt RunUnittests.bat

# Generowanie pliku XML z wynikami testów
Po uruchomieniu testów raport powinien wygenerować się automatyczne.
Jeśli narzędzie cmake jest zainstalowane to raport pojawi się w folderze
build\unittests\Testing\YYYYMMDD-HHMM pod nazwą Test.xml
Jeśli narzędzie cmake nie jest zainstalowane to raport pojawi się w folderze
build\unittests\Testing\report i dla każdego modułu utworzy się oddzielny plik xml (Logic.xml, Main.xml, Math.xml i View.xml)