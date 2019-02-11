#pragma once
template <class T>
class THeadList
{
	TLink<T> *pHead, *pFirst, *pLast, *pPrev, *pCurr;
	int pos, size;
public:
	THeadList();
	void InsFirst(const T & elem);
	void InsCurr(const T elem);
	void DelCurr();
};

template <class T>
THeadList <T> :: THeadList() //конструктор
{
	TLink <T> *tmp = new TLink <T>;
	pHead = tmp;
	pHead->pNext = pHead;
	pFirst = pCurr = pLast = NULL;
	pos = -1;
	size = 0;
}

template <class T>
void THeadList <T> ::  InsFirst(const T & elem)
{
	TLink<T> *tmp = new TLink <T>;
	tmp->Val = elem;
	if (size > 0)
	{
		pHead->pNext = tmp;
		tmp->pNext = pFirst;
		pFirst = tmp;
		size++; pos++;
	}
	else
	{
		pHead->pNext = tmp;
		tmp->pNext = pHead;
		pFirst = tmp;
		size++; pos = 0;
		pCurr = pFirst;
	}
}

template <class T>
void THeadList <T> :: InsCurr(const T elem)
{
	TLink <T>*tmp = new TLink <T>;
	tmp->val = elem;
	pPrev->pNext = tmp;
	tmp->pNext = pCurr;
	pCurr = tmp;
	size++;
}
template <class T>
void THeadList <T> :: DelCurr()
{
	if (pCurr != pHead && size > 0)
	{
		TLink <T> *tmp = pCurr;
		pPrev->pNext = pCurr->pNext;
		delete tmp;
		pCurr = pPrev->pNext;
	}
	size--;
}
