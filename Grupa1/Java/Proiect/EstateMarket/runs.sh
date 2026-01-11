#!/bin/bash
# Compilează toate fișierele .java
javac -cp ".:sqlite-jdbc-3.50.3.0.jar" *.java

# Rulează aplicația
java -cp ".:sqlite-jdbc-3.50.3.0.jar" PaginaPrincipala
