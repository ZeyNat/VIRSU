

bool Teaupla::verifieGeuchars(int x, int y){
  return (tab[y][x].getEtat()=='*');
}




void Teaupla::teleportation(Oueurj J, int x, int y){

  int xrand;
  int yrand;
  do{
    xrand = rand()%(getMaxX());
    yrand = rand()%(getMaxY());
  } while(!posValide(xrand,yrand));
  tab[y][x].setEtat(' ');
  J.setLocalisation(xrand,yrand);
  tab[yrand][xrand].setEtat('J'); //mise à jour de la place du oueurj
    cout<< "Vous vous etes TELEPORTES à la position (" << xrand <<',' << yrand << ")" << endl;
}



void Teaupla::deplaceOueurj(){ //deplacement du oueurj en fonction de l'entrée clavier
  Oueurj J = getOueurj();
  bool perdu = false;
  char mouv;
  J.afficheDiams();


  do{ //on demande au oueurj de joueur tant qu'il ne veut pas quitter (0 pour quitter la partie)
    cout<<"Jouer"<<endl;
    cin>>mouv;
    int x = J.getX();
    int y = J.getY();

    //deplacement au Nord
    if(mouv=='z' && posValide(x,y-1)){
        if (verifieGeuchars(x,y-1)){
          teleportation(J,x,y); //on teleporte le oueurj si il est sur *
        }
        else{
            if (verifieDiams(x,y-1)){ //si le oueurj veut recuperer un diams
              J.incrementeDiams();
              ouvreTeuport();
            }
            tab[y][x].setEtat(' ');
            J.setLocalisation(x,y-1);
            cout<<"Nouvelle localisation de J est : (" << x << ", " << y-1 << ")" << endl; //pour tester
            tab[y-1][x].setEtat('J'); //mise à jour de la place du oueurj
            cout<<"Vous vous etes deplaces au Nord"<<endl;
        }
    }


    //deplacement au Nord Est
    if(mouv=='e' && posValide(x+1,y-1)){

      if (verifieGeuchars(x+1,y-1)){
        teleportation(J,x,y); //on teleporte le oueurj si il est sur *
      }

      else{
        if (verifieDiams(x+1,y-1)){
          J.incrementeDiams();
          ouvreTeuport();
        }
        tab[y][x].setEtat(' ');
        J.setLocalisation(x+1,y-1);
        cout<<"Nouvelle localisation de J est : (" << x+1 << ", " << y-1 << ")" << endl;
        tab[y-1][x+1].setEtat('J'); //mise à jour de la place du oueurj
        cout<<"Vous vous etes deplacer au Nord Est"<<endl;
      }
    }


    //deplacement au Nord Ouest
    if(mouv=='a' && posValide(x-1,y-1)){

      if (verifieGeuchars(x-1,y-1)){
        teleportation(J,x,y); //on teleporte le oueurj si il est sur *
      }

      else{
        if (verifieDiams(x-1,y-1)){
          J.incrementeDiams();
          ouvreTeuport();
        }
        tab[y][x].setEtat(' ');
        J.setLocalisation(x-1,y-1);
        cout<<"Nouvelle localisation de J est : (" << x-1 << ", " << y-1 << ")" << endl;
        tab[y-1][x-1].setEtat('J'); //mise à jour de la place du oueurj
        cout<<"Vous vous etes deplacer au Nord Ouest"<<endl;
      }
    }

    //deplacement a l'Est
    if(mouv=='d' && posValide(x+1,y)){

      if (verifieGeuchars(x+1,y)){
        teleportation(J,x,y); //on teleporte le oueurj si il est sur *
      }

      else{
        if (verifieDiams(x+1,y)){
          J.incrementeDiams();
          ouvreTeuport();
        }
        tab[y][x].setEtat(' ');
        J.setLocalisation(x+1,y);
        cout<<"Nouvelle localisation de J est : (" << x+1 << ", " << y << ")" << endl;
        tab[y][x+1].setEtat('J'); //mise à jour de la place du oueurj
        cout<<"Vous vous etes deplacer a l'Est"<<endl;
      }
    }

    //deplacement a l'Ouest
    if(mouv=='q' && posValide(x-1,y)){

      if (verifieGeuchars(x-1,y)){
        teleportation(J,x,y); //on teleporte le oueurj si il est sur *
      }
      else{
        if (verifieDiams(x-1,y)){
          J.incrementeDiams();
          ouvreTeuport();
        }
        tab[y][x].setEtat(' ');
        J.setLocalisation(x-1,y);
        cout<<"Nouvelle localisation de J est : (" << x-1 << ", " << y << ")" << endl;
        tab[y][x-1].setEtat('J'); //mise à jour de la place du oueurj
        cout<<"Vous vous etes deplacer a l'Ouest"<<endl;
      }
    }

    //deplacement au Sud
    if(mouv=='x' && posValide(x,y+1)){

      if (verifieGeuchars(x,y+1)){
        teleportation(J,x,y); //on teleporte le oueurj si il est sur *
      }

      else{
        if (verifieDiams(x,y-1)){
          J.incrementeDiams();
          ouvreTeuport();
        }
        tab[y][x].setEtat(' ');
        J.setLocalisation(x,y+1);
        cout<<"Nouvelle localisation de J est : (" << x << ", " << y+1 << ")" << endl;
        tab[y+1][x].setEtat('J'); //mise à jour de la place du oueurj
        cout<<"Vous vous etes deplacer au Sud"<<endl;
      }
    }

    //deplacement au Sud Est
    if(mouv=='c' && posValide(x+1,y+1)){

      if (verifieGeuchars(x+1,y+1)){
        teleportation(J,x,y); //on teleporte le oueurj si il est sur *
      }
      else{
        if (verifieDiams(x+1,y+1)){
        J.incrementeDiams();
        ouvreTeuport();
        }
        tab[y][x].setEtat(' ');
        J.setLocalisation(x+1,y+1);
        cout<<"Nouvelle localisation de J est : (" << x+1 << ", " << y+1 << ")" << endl;
        tab[y+1][x+1].setEtat('J'); //mise à jour de la place du oueurj
        cout<<"Vous vous etes deplacer au Sud Est"<<endl;
      }
    }

    //deplacement au Sud Ouest
    if(mouv=='w' && posValide(x-1,y+1)){

      if (verifieGeuchars(x-1,y+1)){
        teleportation(J,x,y); //on teleporte le oueurj si il est sur *
      }
      else{
        if (verifieDiams(x-1,y+1)){
          J.incrementeDiams();
          ouvreTeuport();
        }
        tab[y][x].setEtat(' ');
        J.setLocalisation(x-1,y+1);
        cout<<"Nouvelle localisation de J est : (" << x-1 << ", " << y+1 << ")" << endl;
        tab[y+1][x-1].setEtat('J'); //mise à jour de la place du oueurj
        cout<<"Vous vous etes deplacer au Sud Ouest"<<endl;
      }
    }


    perdu = deplaceStreumons(J);

    affiche();
    cout << "Vous avez " << J.getDiams() << " diams." << endl;
  } while(mouv!='0' && !perdu);
  cout << "Perdu ! Le Oueurj sest fait febou par un streumon ! NOMNOMNOM !!!" << endl;
}
