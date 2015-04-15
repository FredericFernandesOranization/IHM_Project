Cahier de Charge: (pas en ordre de priorité)

1) drag and drop pour remplir la zone "commande"

2) classe item pour gérér le rendu visuel des plats dans la partie droite de l'interface graphique 
	3-4 plat par ligne, 2-3 ligne verticals selon l'écran ... 

3) message de validation de la commande (ça doit etre beau!)

4) analyse XML pour charger la base -> se servir de la classe database.cpp et de l'Outil Qt XML (parser déjà existant)

5) effet pour faire disparaitre / apparaitre la zone "commande" qui sera toujours présente mais visible / invisible 
   grace au bouton en haut gauche de l'écran 

6) Skelette de l'interface (division en 4 zones -> 1 objet pour gérér chaque zone?)

7) remplissage de la base de données (puis script pour permettre à un utilisateur "grand père" de rémplir sa base ... )

8) filtrage plats par allergies

9) modification plat (possibilité de rétirer des ingredients)

10) création de la fenetre detaillé lorsqu'on clique sur un plat dans la partie droite de l'interface graphique 


README: 

a

database.h -> classe qui s'occupe du chargement de la base de données à partir du fichier XML et qui offre au dévéloppeur de l'interface graphique les fonctions d'accés à la liste des plats (fonction "loadDatabase") et les fonctions de filtrage (fonction "filter")

plat.h -> classe qui modélise un plat de notre restaurant, indépendamment du type (boissons, dessert) qui est specifié dans son attribut "QString type", donc si on a besoin de traiter des plats, c'est cette classe qu'on utilisera ! (getNom, getType, getDescription ...)


Pour la lecture du hashMap qui contient tous les plats voici un example pour le parcourir :

	//    foreach (QString type , dishesMap.keys()){
	//        qDebug() << "~~~~~~~~~~~~Liste des plats de type : "<< type <<"~~~~~~~~~~~~~~";
	//        QList<Plat*> listPlat = dishesMap[type];
	//        foreach (Plat* plat, listPlat){
	//            qDebug() << plat->toString() << endl;
	//        }
	//    }

ou  

	//    foreach (QList<Plat*> listPlat, dishesMap)
	//        foreach (Plat* plat, listPlat)
	//            qDebug() << plat->toString() << endl;



