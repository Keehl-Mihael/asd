//
// Created by siroid on 1/1/19.
//

#ifndef TEST_BUILD_RICHIESTE_H
#define TEST_BUILD_RICHIESTE_H


class rating{
public:
    string utente;
    string prodotto;
    int rating;
};

class recommender{
public:
    // inserisce nella lista ratings una nuovo rating
    // <user, item, rating>
    void insert(string user, string item, int voto);
    // restituisce la media dei rating dell’utente user
    double meanUser(string user);
    // restituisce la media dei rating per il prodotto item
    double meanItem(string item);
    // restituisce la lista dei prodotti votati dall’utente user
    list<string> rated(string user);
    // restituisce la lista dei prodotti votati sia dall’utente user1
    // che dall’utente user2
    list<string> common(string user1, string user2);
    // usando il metodo common, calcola quanti prodotti sono stati votati
    // allo stesso modo sia dall’utente user1 che dall’utente user2
    int commonEqual(string user1, string user2);
private:
    list<rating> ratings;
};

void recommender::insert(string user, string item, int voto) {
    if(voto >0 && voto < 6){
        rating nuovo_rating;
        nuovo_rating.utente = user;
        nuovo_rating.prodotto = item;
        nuovo_rating.rating = voto;
        ratings.push_back(nuovo_rating);
    }
}

double recommender::meanUser(string user){
    double avg = 0;
    int counter = 0;
    list<rating>::iterator it;
    for(it=ratings.begin();it!=ratings.end();++it){
        if(it->utente == user){
            avg += it->rating;
            counter++;
        }
    }
    return avg/counter;
}

double recommender::meanItem(string item){
    double avg = 0;
    int counter = 0;
    list<rating>::iterator it;
    for(it=ratings.begin();it!=ratings.end();++it){
        if(it->prodotto == item){
            avg += it->rating;
            counter++;
        }
    }
    return avg/counter;
}

list<string> recommender::rated(string user){
    list<string> prodottiVotati;
    list<rating>::iterator it;
    for(it=ratings.begin();it!=ratings.end();++it){
        if(it->utente == user){
            prodottiVotati.push_back(it->prodotto);
        }
    }
    return prodottiVotati;
};

list<string> recommender::common(string user1, string user2){
    list<string> prodottiComuni;
    list<rating>::iterator it;
    map<string,int> dbProdotti;
    std::map<string,int>::iterator secondIt;
    for(it=ratings.begin();it!=ratings.end();++it){
        if(it->utente == user1){
            secondIt = dbProdotti.find(it->prodotto);
            if (secondIt != dbProdotti.end()){
                prodottiComuni.push_back(it->prodotto);
            }else{
                dbProdotti[it->prodotto] = it->rating;
            }
        }
        if(it->utente == user2){
            secondIt = dbProdotti.find(it->prodotto);
            if (secondIt != dbProdotti.end()){
                prodottiComuni.push_back(it->prodotto);
            }else{
                dbProdotti[it->prodotto] = it->rating;
            }
        }
    }
    return prodottiComuni;
};


#endif //TEST_BUILD_RICHIESTE_H
