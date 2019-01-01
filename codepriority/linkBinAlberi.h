#ifndef LINKBINALBERI_H_
#define LINKBINALBERI_H_

#include <iostream>
#include "coda.h"

template <class I>
class LinkBinAlberi;

template <class I>
class TreeNode
{
public:
	friend class LinkBinAlberi<I>;
private:
	TreeNode *parent = nullptr;
	TreeNode *sx = nullptr;
	TreeNode *dx = nullptr;
	I item;
	int level;
	int numNodiRadicati;
	char tipoFiglio;
};

template <class I>
class LinkBinAlberi
{
public:
	typedef  I item;
	typedef  TreeNode<I>* node;

	LinkBinAlberi();
	~LinkBinAlberi();
	void create();
	bool empty() const;

	node root() const;
	node parent(node) const;
	node sx(node) const;
	node dx(node) const;
	node fratello(node) const;
	bool sxEmpty(node) const;
	bool dxEmpty(node) const;
	bool isRoot(node) const;


	//ausiliarie
	void mutation(node,node);
	int contaNumNodi(node);
	void aggiornaNodiRadicati(node n){n->numNodiRadicati = this->contaNumNodi(n) - 1;};
	void cancFogliaPari(node);
	int getNumNodiRadicati(node n){return n->numNodiRadicati;};
	char getTipoFiglio(node n){return n->tipoFiglio;};
	bool IsFiglioSx(node n) const	{return n->tipoFiglio=='s';};
	bool IsFiglioDx(node n) const	{return n->tipoFiglio=='d';};
	int getlevel(node n){return n->level;};
	bool leaf(node)const;
	item read(node) const;
	void write(node , item);
	void printSubTree(node) const;
	void print()const;
	void printWithNumNode(node);
	friend std::ostream& operator<<(std::ostream &os, const LinkBinAlberi &L)
	{
		L.print();
		return os;
	}
	//inserimento-cancelazione
	void insRoot(item);
	void insSx(node , item);
	void insDx(node , item);
	void erase(node);
	//visite
	void preVisita(node);
	void postVisita(node);
	void inVisita(node,int);
	void ampiezza(node);
	void simmetrica(node);

private:
	node _root;
};

template <class I>
LinkBinAlberi<I>::LinkBinAlberi()
{
	create();
}

template <class I>
LinkBinAlberi<I>::~LinkBinAlberi()
{
	//this->erase(_root);
	delete this->_root;
}

template <class I>
void LinkBinAlberi<I>::create()
{
	this->_root = nullptr;
}

template <class I>
bool LinkBinAlberi<I>::empty()const
{
	return (this->_root == nullptr);
}

template <class I>
typename LinkBinAlberi<I>::node LinkBinAlberi<I>::root()const
{
	return this->_root;
}

template <class I>
typename LinkBinAlberi<I>::node LinkBinAlberi<I>::parent(node n)const
{
	if(n->parent != nullptr)
		return n->parent;
}

template <class I>
typename LinkBinAlberi<I>::node LinkBinAlberi<I>::sx(node n)const
{
	if(n->sx != nullptr)
		return n->sx;
}

template <class I>
typename LinkBinAlberi<I>::node LinkBinAlberi<I>::fratello(node n) const
{
	if(this->isRoot(n))
		return nullptr;
	if(n->tipoFiglio=='s')
		return n->parent->dx;
	if(n->tipoFiglio=='d')
		return n->parent->sx;
}

template <class I>
typename LinkBinAlberi<I>::node LinkBinAlberi<I>::dx(node n)const
{
	if(n->dx != nullptr)
		return n->dx;
}

template <class I>
bool LinkBinAlberi<I>::sxEmpty(node n)const
{
	return (n->sx == nullptr);
}

template <class I>
bool LinkBinAlberi<I>::dxEmpty(node n)const
{
	return (n->dx == nullptr);
}

template <class I>
bool LinkBinAlberi<I>::isRoot(node n)const
{
	return (n->parent == nullptr);
}

template <class I>
void LinkBinAlberi<I>::erase(node n)
{
	if(!this->sxEmpty(n))
		this->erase(this->sx(n));
	if(!this->dxEmpty(n))
		this->erase(this->dx(n));

	if(n == this->root())
		n = nullptr;
	else
	{
		node p = n->parent;
		if(p->sx == n)
		{
			p->sx = nullptr;
			delete this->sx(p);
		}
		else
		{
			p->dx = nullptr;
			delete this->dx(p);
		}
	}
}
template <class I>
void LinkBinAlberi<I>::mutation(node u , node v)
{
	node temp;
	if(u->parent != nullptr && v->parent != nullptr)
	{
		if(u->parent->sx == u)
		{
			temp = u->parent->sx;
			u->parent->sx = v;
		}

		if(u->parent->dx == u)
		{
			temp = u->parent->sx;
			u->parent->dx = v;
		}

		if(v->parent->sx == v)
			v->parent->sx = temp;

		if(v->parent->dx == v)
			v->parent->dx = temp;

		u->parent = v;
		v->parent = u;
	}

	if(u->parent != nullptr && v->parent == nullptr)
	{
		node temp1 = u->sx;
		node temp2 = u->dx;

		u->sx = v->sx;
		u->dx = v->dx;

		v->sx = temp;
		u->dx = temp;
	}

	if(u->parent == nullptr && v->parent == nullptr)
	{
		node temp1 = u->sx;
		node temp2 = u->dx;

		u->sx = v->sx;
		u->dx = v->dx;

		v->sx = temp1;
		v->dx = temp2;

		u->sx->parent = u;
		u->dx->parent = u;

		v->sx->parent = v;
		v->dx->parent = v;

	}
}

template <class I>
int LinkBinAlberi<I>::contaNumNodi(node n)
{
	int numNodi = 0;

	if(!this->sxEmpty(n))
		numNodi += this->contaNumNodi(this->sx(n));
	if(!this->dxEmpty(n))
		numNodi += this->contaNumNodi(this->dx(n));
	numNodi++;

	return numNodi;
}

//vale solo per int
template <class I>
void LinkBinAlberi<I>::cancFogliaPari(node n)
{
	if(!this->sxEmpty(n))
		this->cancFogliaPari(this->sx(n));
	//std::cout << this->read(n) << std::endl;
	if(!this->dxEmpty(n))
		this->cancFogliaPari(this->dx(n));
	if((this->read(n) %2 == 0) && ( this->leaf(n) ))
		this->erase(n);
}

template <class I>
bool LinkBinAlberi<I>::leaf(node n)const
{
	return(n->sx == nullptr && n->dx == nullptr);
}

template <class I>
typename LinkBinAlberi<I>::item LinkBinAlberi<I>::read(node n)const
{
	return n->item;
}

template <class I>
void LinkBinAlberi<I>::write(node n , item elem)
{
	n->item = elem;
}

template <class I>
void LinkBinAlberi<I>::insRoot(item i)
{
	this->_root = new TreeNode<I>();
	this->_root->item = i;
	this->_root->level = 0;
	this->_root->numNodiRadicati = 0;
	this->_root->tipoFiglio = '0';
}

template <class I>
void LinkBinAlberi<I>::insSx(node n , item i)
{
	if(this->sxEmpty(n))
	{
	node newNode = new TreeNode<I>();
	newNode->item = i;
	n->sx = newNode;
	newNode->parent = n;
	newNode->level = (newNode->parent->level)+1;
	newNode->numNodiRadicati = 0;
	newNode->tipoFiglio = 's';
	}
	else
		std::cout << "Nodo sinistro pieno" << std::endl;
}

template <class I>
void LinkBinAlberi<I>::insDx(node n , item i)
{
	if(this->dxEmpty(n))
	{
		node newNode = new TreeNode<I>();
		newNode->item = i;
		n->dx = newNode;
		newNode->parent = n;
		newNode->level = (newNode->parent->level)+1;
		newNode->numNodiRadicati = 0;
		newNode->tipoFiglio = 'd';
	}
	else
		std::cout << "Nodo destro pieno" << std::endl;
}

template <class I>
void LinkBinAlberi<I>::printSubTree(node n)const
{
	std::cout << this->read(n) << ": ";
	if(!this->sxEmpty(n))
		std::cout << this->read(n->sx) << " ";
	else
		std::cout << "NIL" << " ";
	if(!this->dxEmpty(n))
		std::cout << this->read(n->dx);
	else
		std::cout << "NIL";
	std::cout << std::endl;
	if(!this->sxEmpty(n))
		printSubTree(this->sx(n));
	if(!this->dxEmpty(n))
		printSubTree(this->dx(n));
	/*
	std::cout << this->read(n) << ": ";
	if(!this->sxEmpty(n))
		print(this->sx(n));
	else
		std::cout << "NIL";
	std::cout << " " ;
	if(!this->dxEmpty(n))
		print(this->dx(n));
	else
		std::cout << "NIL";
	*/
}

template <class I>
void LinkBinAlberi<I>::print()const
{
	if(!this->empty())
		this->printSubTree(this->root());
	else
		std::cout << "Albero binario vuoto";
	std::cout << std::endl;
}

template <class I>
void LinkBinAlberi<I>::printWithNumNode(node n)
{
	this->aggiornaNodiRadicati(n);
	std::cout << "numNodi radicati in " << this->read(n) << " > " << this->getNumNodiRadicati(n) << std::endl;
	if(!this->sxEmpty(n))
		this->printWithNumNode(this->sx(n));
	if(!this->dxEmpty(n))
		this->printWithNumNode(this->dx(n));

}

template <class I>
void LinkBinAlberi<I>::preVisita(node n)
{
	std::cout << this->read(n) << std::endl;
	if(!this->sxEmpty(n))
		this->preVisita(this->sx(n));
	if(!this->dxEmpty(n))
		this->preVisita(this->dx(n));

}

template <class I>
void LinkBinAlberi<I>::postVisita(node n)
{
	if(!this->sxEmpty(n))
		this->preVisita(this->sx(n));
	if(!this->dxEmpty(n))
		this->preVisita(this->dx(n));
	std::cout << this->read(n) << std::endl;
}
/*da completare
template <class I>
void LinkBinAlberi<I>::inVisita(node n , int i)
{
	if(this->leaf(n))
		std::cout << this->read(n) << std::endl;
	else
	{
		int k = 0;

	}

}
*/
template <class I>
void LinkBinAlberi<I>::simmetrica(node n)
{
	if(!this->sxEmpty(n))
		this->simmetrica(this->sx(n));
	std::cout << this->read(n) << std::endl;
	if(!this->dxEmpty(n))
		this->simmetrica(this->dx(n));

}

template <class I>
void LinkBinAlberi<I>::ampiezza(node n)
{
	Coda<node> temp;
	temp.inCoda(n);
	while(!temp.codaVuota())
	{
		node p = temp.leggiCoda();
		temp.fuoriCoda();
		std::cout << p->item << "  " << p->level <<  std::endl;
		if(!this->sxEmpty(p))
			temp.inCoda(this->sx(p));
		if(!this->dxEmpty(p))
			temp.inCoda(this->dx(p));
	}
}

#endif /* LINKBINALBERI_H_ */
