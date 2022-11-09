#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>
#include<conio.h> //getch

#define ADDRFILE "c:addrlist.txt"

typedef struct tagLinkedList
{
	char name[30];/*�̸�*/
	char tel[30]; /*��ȭ*/
	char addr[100];/*�ּ�*/

	struct tagLinkedList* prev;
	struct tagLinkedList* next;
}ADDR;

ADDR* g_gAddrHead = NULL;
ADDR* g_Find;
int g_bSaved = 1;

void get_addrlist(void);
int add_list(const ADDR* addr);
int find_list(const char* name)
void SetHeadPosition(void);
void SetTailPosition(void);

void Add_addr(void);
void Find_addr(void);
void Modify_addr(void);
void Delete_addr(void);
void Print_addr(void);
void Save_addr(void);
void Remove_addr(void);

void main(void)
{
	int ch;

	get_addlist();

	puts("�ּҷ� ���α׷�");

	while (1) {
		print("\n[1]���[2]�˻�[3]����[4]����[5]���[S]����[Q]����");

		ch = getch();

		switch (ch)
		{
		case '1':Add_addr(); break;
		case '2':Find_addr(); break;
		case '3':Modify_addr(); break;
		case '4':Delete_addr(); break;
		case '5':Print_addr(); break;
		case 's':
		case 'S':Save_addr(); break;
		case 'q':
		case 'Q':
			if (g_bSaved == 0)
			{
				printf("\n\n����� �ּ� �����͸� �����Ͻðڽ��ϱ�(y/n)?");
				ch = getchar();
				if (ch == 'Y' || ch == 'y')Save_addr();
			}

			Remove_addr(); return;
		default:printf("\n\n1~5 �Ǵ� S/Q�� �����ʽÿ�.\n\n"); break;
		}
	}
}

void get_addrlist(void)
{
	ADDR addr;
	FILE* fp;

	fp = fopen(ADDRFILE, "rb");

	if (fp == NULL)
	{
		perror("���� ���� ����");
		return;
	}

	while (!feof(fp))
	{
		fread(&addr, sizeof(ADDR), 1, fp);

		if (ferror(fp))
		{
			fclose(fp);
			perror("���� �б� ����");
			return:
		}

		if (feof(fp))break;

		if (add_list(&addr) == 0)
		{
			printf("�ּ� �����͸� ������ �� �����ϴ�.\n");
		}
	}
	fclose(fp);
}

int add_list(const ADDR* addr)
{
	ADDR* plocal, * pn = g_pAddrHead;
	SetHeadPosition();

	/*g_oAddHead�� �ʱ�ȭ ���� ���� ���,�� ���� ����˴ϴ�.*/
	if (g_pAddrHead == NULL)
	{
		plocal = malloc(sizeof(ADDR));/*ADDR ����ü �Ҵ�*/
		memset(plocal, 0, sizeof(ADDR));

		if (plocal == NULL)
		{
			return 0;
		}

		g_pAddrHead = plocal;
		g_pAddrHead->prev = NULL;/*ó������  �ݵ�� NULL�� �ʱ�ȭ*/
		g_pAddrHead->next = NULL;/*ó������ �ݵ�� NULL�� �ʱ�ȭ*/
	}
	else /*g_AddrHead�� �ֱ�ȭ�� �� ��� ����˴ϴ�.*/
	{
		plocal = malloc(sizeof(ADDR));/*ADDR ����ü �Ҵ�*/
		memset(plocal, 0, sizeof(ADDR));

		if (plocal == NULL)
		{
			return 0;
		}

		while (pn->next)
		{
			pn = pn->next;
		}

		pn->next = plocal;
		plocal->prev = pn;
		plocal->next = NULL;
	}

	strcpy(plocal->name, addr->name);
	strcpy(plocal->tel, addr->tel);
	strcpy(plocal->addr, addr->addr);
	return 1;
}

void SetHeadPosition(void)
{
	if (g_pAddrHead == NULL)return;

	while (g_pAddrHead->prev)
	{
		g_pAddrHead = g_pAddHead->prev;
	}
}

void SetTailPosition(void)
{
	if (g_pAddHead == NULL)return;

	while (g_pAddrHead->next)
	{
		g_pAddrHead = g_pAddrHead->next;
	}
}

int find_list(const char* name)
{
	ADDR* plocal;

	SetHeadPosition(); /*g_AddrHead�� ù �ּ� �����͸� ����Ű���� ����*/

	plocal = g_pAddrHead;

	while (plocal)
	{
		if (strstr(plocal->name, name)) /*�̸��� �˻�*/
		{
			g_pFind = plocal;
			return 1;
		}
		plocal = plocal->next;
	}
	return 0;
}

void Add_addr(void)
{
	ADDR addr;

	memset(&addr, 0, sizeof(ADDR));

	printf("\n\n����� �̸�: "); gets(addr.name);

	if (strlen(addr.name) == 0)return;

	printf("����� ��ȭ : "); gets(addr.tel);
	printf("����� �ּ� : "); gets(addr.addr);

	if (find_list(addr.name) == 1)
	{
		printf("\n�̹� ��ϵǾ� �ִ� �̸��Դϴ�\n\n");
		puts(g_Find->name);
		puts(g_pFind->tel);
		puts(g_pFind->addr);
		return;
	}

	if (addr_list(&addr))
	{
		g_bSaved = 0;
		printf("\n��ϵǾ����ϴ�.\n\n");
	}
	else
	{
		printf("\n����� ���еǾ����ϴ�.\n\n");
	}
}

void Find_addr(void) {
	char buff[100] = { 0, }
	ADDR * plocal;

	printf("\n\n�˻��� �̸�/��ȭ/�ּ��� �Ϻθ� �Է��ϼ���.\n");
	printf("�̸�/��ȭ/�ּ� : "); gets(buff);

	if (strlen(buff) == 0)return;

	SetHeadPosition();

	plocal = g_pAddrHead;
	g_pFInd = NULL;

	while (plocal)
	{
		if (strstr(plocal->name, buff))/*�̸��� �˻�*/
		{
			g_pFind = plocal;
			break;
		}

		if (strstr(plocal->tel, buff)) /*��ȭ�� �˻�*/
		{
			g_pFind = plocal;
			break;
		}

		if (strstr(plocal->addr, buff)) /*�ּҸ� �˻�*/
		{
			g_pFind = plocal;
			break;
		}
		plocal = plocal->next;
	}

	if (g_pFind)
	{
		puts(g_pFInd->name);
		puts(g_pFInd->tel);
		puts(g_pFInd->addr);
	}
	else
	{
		printf("\n\n%s�� �ּҷϿ��� ã�� �� �����ϴ�.\n\n", buff);
	}
}

void Modify_addr(void)
{
	cahr name[100] = { 0, };
	ADDR addr;

	while (1)
	{
		printf("\n\n������ �̸� : "); gets(name);

		if (strlen(name) == 0)return;

		if (find_list(name) == 0)
		{
			puts("������ �̸��� ã�� �� �����ϴ�.");
			continue;
		}
		break;
	}

	printf("\n%s�� ���� �ּ� �����ʹ� �Ʒ��� �����ϴ�.\n\n", name);
	puts(g_pFind->name);
	puts(g_Find->tel);
	puts(g_pFind->addr);

	printf("\n�����Ϸ��� �̸�/��ȭ/�ּҸ� �Է��� �� ���͸� ġ����\n\n");

	printf("�̸� : "); gets(addr.name);
	printf("��ȭ : "); gets(addr.tel);
	printf("�ּ� : "); gets(addr.addr);

	printf("\n%s�� ���� �ּҴ� �Ʒ��� �����ϴ�.\n\n", name);
	puts(g_pFind->name);
	puts(g_Find->tel);
	puts(g_pFind->addr);

	printf("\n�����Ϸ��� �̸�/��ȭ/�ּҸ� �Է��� �� ���͸� ġ����\n\n");

	printf("�̸� : "); gets(addr.name);
	printf("��ȭ : "); gets(addr.tel);
	printf("�ּ� : "); gets(addr.addr);

	if (strlen(add.name) == 0)strcpy(addr.name, name);

	strcpy(g_pFind->name, addr.name);
	strcpy(g_pFind->tel, addr.tel);
	strcpy(g_pFind->addr, addr.addr);

	g_bSaved = 0;

	printf("%s�� ���� �ּҸ� �����Ͽ����ϴ�.\n", name);
}

void Delete_addr(void)
{
	char name[100] = { 0, };
	ADDR* plocal;
	int ch;

	while (1)
	{
		printf("\n\n������ �̸� : "); gets(name);

		if (strlen(name) == 0)return;

		if (find_list(name) == 0)
		{
			puts("������ �̸��� ã�� �� �����ϴ�.");
			continue;
		}
		break;
	}

	puts(g_pFind->name);
	puts(g_pFind->tel);
	puts(g_pFind->addr);

	printf("%s�� �����Ͻðڽ��ϱ�(y/n)?", name);
	ch = getch();
	fflush(stdin);

	if (ch == 'Y' || ch == 'y')
	{
		if (g_pFind->prev == NULL) /*���� �����Ͱ� ���� ���*/
		{
			if (g_pFind->next == NULL) /*���� �����Ͱ� ���� ���*/
			{
				free(g_pFind);
				g_pAddrHead = NULL;
			}
			else
			{
				plocal = g_pFind->next;
				free(g_pFind);
				plocal->prev = NULL;
				g_pAddrHead = plocal;
			}
		}
		else if (g_pFind->next == NULL) /*���� �����Ͱ� ���� ���*/
		{
			plocal = g_pFind->prev;
			free(g_pFind);
			plocal->next = NULL;
			g_pAddrHead = plocal;
		}

		else
		{
			plocal = g_pFind->prev;
			plocal->next = g_pFind->next;

			plocal = g_pFind->next;
			plocal->next = g_pFind->prev;

			free(g_Find);
			g_AddrHead = plocal;
		}

		g_bSaved = 0;

		printf("\n\n�˻��� �ּ� �����͸� �����Ͽ����ϴ�.\n\n");
	}
}

void Print_addr(void)
{
	int count = 1;
	ADDR* plocal;

	SetHeadPosition();

	plocal = g_pAddrHead;

	//plocal ����Ʈ�� �� ó������ �̵�
	whiile(plocal->prev)
	{
		plocal = plocal->prev;
	}

	printf("\n\n");

	//�Ѱ��� ���
	while (plocal)
	{
		printf("��ȣ.%d\n", count++);
		puts(plocal->name);
		puts(plocal->tel);
		printf("%s \n\n", plocal->addr);

		printf("�ƹ�Ű�� ��������,(����:q)\n\n");
		if (getch() == 'q')return;

		plocal = plocal->next;
	}
}

void Save_addr(void)
{
	ADDR* plocal;
	FILE* fp;

	if (g_pAddrHead == NULL)return;

	fp = fopen(ADDRFILE, "w+b");

	if (fp == NULL)
	{
		perror("���� ���� ����");
		return;
	}
	SetHeadPosition();

	//�Ѱ��� �޸� ����
	while (g_pAddrHead)
	{
		plocal = g_pAddrHead -> next;

		fwirte(g_pAddrHead, sizeof(ADDR), 1, fp)

			g_pAddrHead = plocal;
	}

	printf("\n��� �����͸� ���Ͽ� �����Ͽ����ϴ�.");
	g_bSaved = 1;

	fclose(fp);
}

void Remove_addr(void)
{
	ADDR* plocal;

	if (g_pAddrHead == NULL)return;

	SetHeadPosition();

	/*�Ѱ��� �޸� ����*/
	while (g_pAddrHead)
	{
		plocal = g_pAddrHead->next;

		free(g_pAddrHead = plocal);

		g_pAddrHead = plocal;
	}

	g_pAddrHead = NULL; /*������ �ϱ� ���� �ʱ�ȭ*/
}