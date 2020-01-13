# VIRSU
LE jeu de survie

Vous rêvez d'aventure ? Vous cherchez la fortune et la gloire ?
Alors ce jeu est fait pour vous ! Incarnez un oueurj, explorez les salles de le VIRSU, collectez des diams et bien plus encore.
Mais attention... Les streumons sont affamés et feront tout pour fébou le Oueurj ! NOMNOMNOM !

Pour lancer une partie :
1. Ouvrir un terminal dans le dossier où se trouvent les fichiers
2. Taper "./game nomDuGame nombreDeSallesSouhaite" pour creer un fichier nomDuGame.game
3. Taper "./jouer nomDuGame"

N.B : Si le game est déja crée, vous pouvez sauter l'étape 2.
POur reprendre un fichier de sauvegarde, cf partie SAUVEGARDE.


RÈGLES :

Le oueurj se déplace de la façon suivante :

A : NO 
Z : N
E : NE
Q : O
D : E
W : SO
X : S
C : SE
S : Téléportation sur une case aléatoire
0 : Quitter la partie

Pour obtenir 2 téléportations, il faut ramasser un geurchar '*'.

Le but : sortir de VIRSU indemne en ayant collecté un maximum de diams.

Le VIRSU est une suite de salles qu'il va falloir traverser.

Les teupors sont symbolisées par '-' si elles sont fermées, '+' si elles sont ouvertes.
Passez une teupor ouverte pour changer de salle.
Pour ouvrir les teupors, il faut collecter des diams 'd'.

A chaque tour, le oueurj peut se deplacer sur une des 8 cases adjacentes à sa position initiale.
Ensuite les streumons font de même. Leur seul but est de fébou le oueurj, ils ignorent les diams et les geurchars.
Le oueurj et les streumons ne peuvent ni traverser les reumus 'X' ni les teupors fermées.

Le oueurj a 3 vies. Quand son nombre de vies tombe à 0, c'est GAME OVER.
Si le oueurj se fait fébou mais qu'il lui reste des vies alors la salle est rechargée et le oueurj peut réessayer (à savoir que s'il n'a pas de téléportations restantes alors le VIRSU lui en offre une car il aime voir les oueurjs se battre pour leur vie !).



SAUVEGARDE :

Le VIRSU vous épuise vous voulez faire une pause? Ou alors votre mère crie "A TABLE !!!" depuis bientôt 10 minutes et elle commence à sérieuselent s'impatienter mais vous n'avez pas fini ? Pas de panique, le VIRSU vous autorise à sauvegarder la partie pour la reprendre plus tard. 
Pour cela, appuyez sur la touche 0 pour quitter. Le VIRSU vous proposera alors de sauvegarder la partie. Repondez oui ('o'), puis entrez votre nom de sauvegarde. Votre partie est maintenant sauvegardée !
N.B : La progression sur la salle en cours n'est pas sauvegardée. Avant de quitter la partie, finissez la salle en cours sinon vous devrez la reprendre du début.

Pour reprendre la partie : reprendre les étapes 1 et 3 de lancement de partie en modifiant nomDuGame par le nom de votre sauvegarde.



Bon courage aventuriers ! (vous allez en avoir besoin)
