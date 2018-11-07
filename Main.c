#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char VigenereCrypt(char *alphabet, int *key, char message, int pos);
char VigenereDecrypt(char *alphabet, int *key, char message, int pos);

int main()
{
	char message[50], messageEncrypted[50], messageDecrypted[50], key[15], alphabet[27] = "abcdefghijklmnopqrstuvwxyz";
	int x, i, j, messageLenght, keyLength, pos = 0, _key[50];

	printf("Message: ");
	gets(message);

	printf("Key: ");
	gets(key);

	messageLenght = strlen(message);
	keyLength = strlen(key);

	for (j = 0; j < keyLength; j++)
	{
		for (i = 0; i <= 25; i++)
		{
			if (key[j] == alphabet[i])
			{
				_key[j] = i;
			}
		}
	}

	printf("\n1 = Encrypt the message.\n");
	printf("2 = Decrypt the message.\n");
	scanf("%d", &x);

	switch (x)
	{
	case 1:
		for (i = 0; i < messageLenght; i++)
		{
			if (pos >= keyLength)
			{
				pos = 0;
			}
			messageEncrypted[i] = VigenereCrypt(alphabet, _key, message[i], pos);
			pos++;
		}
		messageEncrypted[messageLenght] = '\0';
		printf("\nEncrypted message: %s\n", messageEncrypted);
		break;

	case 2:
		for (i = 0; i <= messageLenght; i++)
		{
			if (pos >= keyLength)
			{
				pos = 0;
			}
			messageDecrypted[i] = VigenereDecrypt(alphabet, _key, message[i], pos);
			pos++;
		}
		messageDecrypted[messageLenght] = '\0';
		printf("\nDecrypted message: %s\n", messageDecrypted);
		break;

	default:
		printf("\n Choise 1 or 2 !! \n");
	}

	getch();
	return 0;
}

char VigenereCrypt(char *alphabet, int *_key, char message, int pos)
{
	int i, messageEncrypted;

	for (i = 0; i <= 25; i++)
	{
		if (message == alphabet[i])
		{
			messageEncrypted = (i + _key[pos]) % 26;
			return alphabet[messageEncrypted];
		}
	}
}

char VigenereDecrypt(char *alphabet, int *_key, char message, int pos)
{
	int i, messageDecrypted;

	for (i = 0; i <= 25; i++)
	{
		if (message == alphabet[i])
		{
			messageDecrypted = (i - _key[pos]) % 26;
			return alphabet[messageDecrypted];
		}
	}
}