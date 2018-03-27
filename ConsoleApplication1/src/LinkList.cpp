
#include "LinkList.h"

bool MyLinkList::AddNode(int offset, int value)
{
	if (!Head)
	{ 
		Head = new MyLinkNodeS();
		Head->value = value;
	}
	MyLinkNodeS* p = Head;
	int i = 0;
	while (i < offset)
	{
		i++;
		if(p->next)
			p = p->next;
		else
		{
			p->next = new MyLinkNodeS();
			p->next->value = value;
			return true;
		}
	}
	MyLinkNodeS* q = p->next;
	p->next = new MyLinkNodeS();
	p->next->value = value;
	p->next->next = q;
	return true;
}

int MyLinkList::RemoveNode(int offset)
{
	MyLinkNodeS* p = Head;
	if (offset == 0)
	{
		Head = p->next;
		int re = p->value;
		delete p;
		return re;
	}

	int i = 0;
	while (p->next)
	{
		if (i == offset-1)
		{
			int valuerr = p->next->value;
			MyLinkNodeS* q = p->next;
			p->next = q->next;
			delete q;
			return valuerr;
		}			
		p=p->next;
		i++;
	}
	return 0x23333;
}

bool MyLinkList::Reverse()
{
	MyLinkNodeS *p, *q, *r;
	if (!Head)
		return false;
	p = Head;
	q = p->next;
	while (q)
	{		
			r = q->next;
			q->next = p;
			p = q;
			q = r;
	}
	Head->next = nullptr;
	Head = p;	
	return false;
}

void MyLinkList::MakeList(vector<int>& input)
{
	MyLinkNodeS*p = Head;
	if (Head)
		return;
	vector<int>::iterator it = input.begin();
	while (it != input.end())
	{
		if (!Head)
		{
			Head = new MyLinkNodeS();
			Head->value = *it;
			p = Head;
		}
		else
		{
			p->next = new MyLinkNodeS;
			p->next->value = *it;
			p = p->next;
		}
		it++;
	}
	p->next = nullptr;
	return;
}

vector<int> MyLinkList::ListPrint()
{
	vector<int> re;
	MyLinkNodeS*p = Head;
	while (p)
	{
		re.push_back(p->value);
		p = p->next;
	}
	return re;
}
