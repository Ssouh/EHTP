#!/bin/bash

for i in $@
do
  echo "Voulez-vous réellement effacer le fichier \"$i\"?"
  read rep
    case "$rep" in 
    oui)
        echo "suppression confirmé"
        rm "$i"
    ;;    
    non)
        echo "suppression abandonné"
    ;;
    *)
      echo "réponse non valide"
      echo "Voulez-vous réellement effacer le fichier "$i"?"
      read rep
    ;;
    esac
done 
