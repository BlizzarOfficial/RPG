# RPG
RPG Game 

GIT BASICS ANLEITUNG

git clone https://github.com/<nutzername>/<repository>
  
.gitignore darf Dateien enthalten, die vom Repository ignoriert werden

cd <repository>
  
git status (Zeigt an, dass man auf Hauptbranch master ist)

git checkout -b development

git status (Zeigt an, dass man auf Hauptbranch development ist)

z.B. Datei editieren in IDE oder per Konsole mit notepad++ etc pp

SPEICHERN!

git status (zeigt in rot an modified: <dateiname>)
  
git add <dateiname> oder bei mehreren Dateien hintereinander, oder git add -A für alle
  
git status (zeigt in grün die Dateien an, die jetzt im STAGING Bereich liegen)

git commit -m "Sinnvoller Kommentar zur Änderung"

git checkout master

git merge development

git pull origin master

git push origin master
